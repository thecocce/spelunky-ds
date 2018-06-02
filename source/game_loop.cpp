#include <nds.h>
#include "game_loop.h"
#include "tiles/map_utils.h"
#include "sprites/non_interactive/spelunky_title.h"
#include "sprites/non_interactive/copyrights.h"
#include "sprites/non_interactive/title_menu_sign.h"
#include "sprites/items/rope.h"
#include "sprites/enemies/bat.h"
#include "sprites/enemies/spider.h"
#include "rooms/left_right_rooms.h"
#include "rooms/room_type.h"
#include "rooms/left_right_down_rooms.h"
#include "rooms/left_right_up_rooms.h"
#include "rooms/entrance_rooms.h"
#include "rooms/exit_rooms.h"
#include "rooms/closed_rooms.h"
#include <algorithm>
#include "time/time_utils.h"
#include "memory/oam_utils.h"
#include "sprites/traps/spikes.h"
#include "sprites/collectibles/chest.h"
#include "sprites/collectibles/crate.h"
#include "sprites/enemies/caveman.h"

static const int BOUNDARY_VALUE = 64; /* This is the default boundary value (can be set in REG_DISPCNT) */
static const int OFFSET_MULTIPLIER_MAIN = BOUNDARY_VALUE / sizeof(SPRITE_GFX[0]);
static const int OFFSET_MULTIPLIER_SUB = BOUNDARY_VALUE / sizeof(SPRITE_GFX_SUB[0]);

void gameloop::scroll() {

    global::main_oam_manager->initOAMTable(SPRITE_GFX, SPRITE_PALETTE, OAM, OFFSET_MULTIPLIER_MAIN, OamType::MAIN);
    global::sub_oam_manager->initOAMTable(SPRITE_GFX_SUB, SPRITE_PALETTE_SUB, OAM_SUB, OFFSET_MULTIPLIER_SUB,
                                          OamType::SUB);
    global::main_dude->init();
    global::camera->x = 0;
    global::camera->y = 127;
    global::main_dude->x = 224;
    global::main_dude->y = 300;
    global::sprites.push_back(global::main_dude);

    global::hud->init();

    populate_main_menu();

    while (true) {

        time::update_ms_since_last_frame();

        global::input_handler->updateInput();

        if (global::game_state->bombed) {
            global::level_generator->render_tiles_on_base_map();
            global::game_state->bombed = false;
            for (int a = 0; a < global::sprites.size(); a++)
                (*global::sprites.at(a)).bottomCollision = false;
        }

        global::camera->update_position();

        for (int a = 0; a < global::sprites.size(); a++) {
            if (global::sprites.at(
                    a) /*&& !global::sprites.at(a)->ready_to_dispose *//*&& !global::sprites.at(a)->killed*/) {
                (*global::sprites.at(a)).update();
                (*global::sprites.at(a)).draw();
            }
        }

        global::main_dude->handle_key_input();

        global::hud->update();


        swiWaitForVBlank();
        global::camera->set_scroll();


        global::main_oam_manager->updateOAM();
        global::sub_oam_manager->updateOAM();


        oam_utils::clean_unused_oam();

    }

}

void gameloop::populate_cave_moniez() {


    int last_placement = 3;

    int gold_bars_left = 8;
    int rubies_left = 8;
    int rocks_left = 8;
    int jars_left = 8;
    int chests_left = 3;
    int crates_left = 3;

    std::cout << '\n' << '\n';

    for (int b = ROOMS_Y - 1; b >= 0; b--) {
        for (int a = 0; a < ROOMS_X; a++) {

            int room_type = global::level_generator->layout_room_types[a][b];
            int room_id = global::level_generator->layout_room_ids[a][b];


            if (room_id == -1)
                continue;


            for (int tab_y = 0; tab_y < ROOM_TILE_HEIGHT_GAME; tab_y++) {
                for (int tab_x = 0; tab_x < ROOM_TILE_WIDTH_GAME; tab_x++) {

                    last_placement++;
                    if (last_placement < 4)
                        continue;

                    int npc;

                    if (room_type == room_type::ROOM_LEFT_RIGHT)
                        npc = left_right_loot[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_LEFT_RIGHT_UP)
                        npc = left_right_up_loot[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_LEFT_RIGHT_DOWN)
                        npc = left_right_down_loot[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_ENTRANCE)
                        npc = entrance_room_loot[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_EXIT)
                        npc = exit_room_loot[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_CLOSED)
                        npc = closed_rooms_loot[room_id][tab_y][tab_x];
                    else
                        continue;

                    if (npc == 0)
                        continue;

                    int r = rand() % 3;
                    int loot_type = rand() % 6;

                    u16 pos_x = (OFFSET_X + tab_x * 2 + 2 * ROOM_TILE_WIDTH_GAME * a) / 2;
                    u16 pos_y = (OFFSET_X + tab_y * 2 + 2 * ROOM_TILE_HEIGHT_GAME * ((ROOMS_Y - b) - 1)) / 2;


                    if (loot_type == 1 && gold_bars_left > 0 && r == 1) {

                        Moniez *moniez = new Moniez();

                        moniez->spriteType = MONIEZ_TRIPLE_GOLD_BARS;
                        moniez->value = 1000;

                        moniez->init();

                        global::sprites.push_back(moniez);

                        moniez->x = pos_x * 16;
                        moniez->y = pos_y * 16;

                        gold_bars_left--;
                        last_placement = 0;
                    }

                    if (loot_type == 2 && rubies_left > 0 && r == 1) {
                        Moniez *moniez = new Moniez();

                        moniez->spriteType = MONIEZ_RUBY;
                        moniez->value = 1200;
                        moniez->init();
                        global::sprites.push_back(moniez);
                        moniez->x = pos_x * 16;
                        moniez->y = pos_y * 16;
                        rubies_left--;
                        last_placement = 0;

                    }

                    if (loot_type == 3 && jars_left > 0 && r == 1) {
                        Jar *jar = new Jar();
                        jar->init();
                        global::sprites.push_back(jar);
                        jar->x = pos_x * 16;
                        jar->y = pos_y * 16;
                        jars_left--;
                        last_placement = 0;
                    }

                    if (loot_type == 0 && rocks_left > 0 && r == 1) {
                        Rock *rock = new Rock();
                        rock->init();
                        global::sprites.push_back(rock);
                        rock->x = pos_x * 16;
                        rock->y = pos_y * 16;
                        rocks_left--;
                        last_placement = 0;
                    }


                    if (loot_type == 4 && rocks_left > 0 && r == 1) {
                        Chest *chest = new Chest();
                        chest->init();
                        global::sprites.push_back(chest);
                        chest->x = pos_x * 16;
                        chest->y = pos_y * 16;
                        chests_left--;
                        last_placement = 0;
                    }


                    if (loot_type == 5 && rocks_left > 0 && r == 1) {
                        Crate *crate = new Crate();
                        crate->init();
                        global::sprites.push_back(crate);
                        crate->x = pos_x * 16;
                        crate->y = pos_y * 16;
                        crates_left--;
                        last_placement = 0;
                    }

                }
            }
        }
    }


}


void gameloop::populate_cave_npcs() {

    int last_placement = 3;

    int bats_left = 5;
    int spiders_left = 5;
    int snakes_left = 5;
    int spikes_left = 4;
    int cavemen_left = 3;

    std::cout << '\n' << '\n';

    for (int b = ROOMS_Y - 1; b >= 0; b--) {
        for (int a = 0; a < ROOMS_X; a++) {

            int room_type = global::level_generator->layout_room_types[a][b];
            int room_id = global::level_generator->layout_room_ids[a][b];


            if (room_id == -1)
                continue;


            for (int tab_y = 0; tab_y < ROOM_TILE_HEIGHT_GAME; tab_y++) {
                for (int tab_x = 0; tab_x < ROOM_TILE_WIDTH_GAME; tab_x++) {

                    last_placement++;
                    if (last_placement < 4)
                        continue;

                    int npc;
                    if (room_type == room_type::ROOM_LEFT_RIGHT)
                        npc = left_right_npcs[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_LEFT_RIGHT_DOWN)
                        npc = left_right_down_npcs[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_LEFT_RIGHT_UP)
                        npc = left_right_up_npcs[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_EXIT)
                        npc = exit_room_npcs[room_id][tab_y][tab_x];
                    else if (room_type == room_type::ROOM_CLOSED)
                        npc = closed_rooms_npcs[room_id][tab_y][tab_x];
                    else
                        continue;


                    int r = rand() % 3;

                    u16 pos_x = (OFFSET_X + tab_x * 2 + 2 * ROOM_TILE_WIDTH_GAME * a) / 2;
                    u16 pos_y = (OFFSET_X + tab_y * 2 + 2 * ROOM_TILE_HEIGHT_GAME * ((ROOMS_Y - b) - 1)) / 2;


                    if (npc == 1 && snakes_left > 0 && r == 1) {
                        Snake *snake = new Snake();
                        snake->init();
                        global::sprites.push_back(snake);
                        snake->x = pos_x * 16;
                        snake->y = pos_y * 16;
                        snakes_left--;
                        last_placement = 0;
                    }

                    if (npc == 2 && bats_left > 0 && r == 1) {
                        Bat *bat = new Bat();
                        bat->init();
                        global::sprites.push_back(bat);
                        bats_left--;
                        bat->x = pos_x * 16;
                        bat->y = pos_y * 16;
                        last_placement = 0;
                    }

                    if (npc == 3 && spiders_left > 0 && r == 1) {
                        Spider *spider = new Spider();
                        spider->init();
                        global::sprites.push_back(spider);
                        spider->x = pos_x * 16;
                        spider->y = pos_y * 16;
                        spiders_left--;
                        last_placement = 0;
                    }

                    if (npc == 4 && spikes_left > 0 && r == 1) {
                        Spikes *spikes = new Spikes();
                        spikes->init();
                        global::sprites.push_back(spikes);
                        spikes->x = pos_x * 16;
                        spikes->y = (pos_y * 16) + 3;
                        spikes_left--;
                        last_placement = 0;
                    }


                    if (npc == 5 && cavemen_left > 0 && r == 1) {
                        Caveman *caveman = new Caveman();
                        caveman ->init();
                        global::sprites.push_back(caveman );
                        caveman ->x = pos_x * 16;
                        caveman ->y = pos_y * 16;
                        cavemen_left--;
                        last_placement = 0;
                    }

                }
            }
        }
    }

}

void gameloop::populate_main_menu() {

    global::hud->hide();
    global::hud->bombs = 0;
    global::hud->ropes = 0;

    SpelunkyTitle *spelunkyTitle = new SpelunkyTitle();
    spelunkyTitle->oamType = OamType::MAIN;
    spelunkyTitle->init();
    spelunkyTitle->x = 60;
    spelunkyTitle->y = 175;


    global::sprites.push_back(spelunkyTitle);

    Copyrights *copyrights = new Copyrights();
    copyrights->oamType = OamType::SUB;
    copyrights->init();
    copyrights->x = 60;
    copyrights->y = 380;
    global::sprites.push_back(copyrights);

    TitleMenuSign *start = new TitleMenuSign();
    start->oamType = OamType::MAIN;
    start->menuSignType = MenuSignType::START;
    start->init();
    start->x = 50;
    start->y = 272;
    global::sprites.push_back(start);

    TitleMenuSign *scores = new TitleMenuSign();
    scores->oamType = OamType::MAIN;
    scores->menuSignType = MenuSignType::SCORES;
    scores->init();
    scores->x = 98;
    scores->y = 272;
    global::sprites.push_back(scores);

    TitleMenuSign *tutorial = new TitleMenuSign();
    tutorial->oamType = OamType::MAIN;
    tutorial->menuSignType = MenuSignType::TUTORIAL;
    tutorial->init();
    tutorial->x = 0;
    tutorial->y = 272;
    global::sprites.push_back(tutorial);

    TitleMenuSign *quit = new TitleMenuSign();
    quit->oamType = OamType::MAIN;
    quit->menuSignType = MenuSignType::QUIT;
    quit->init();
    quit->x = 192;
    quit->y = 143;
    global::sprites.push_back(quit);

    Rope *rope = new Rope();
    rope->init();
    rope->x = 227;
    rope->y = 260;
    rope->ySpeed = -4;

    rope->hold_by_main_dude = false;
    rope->activated_by_main_dude = false;
    rope->thrown = true;

    global::sprites.push_back(rope);

}