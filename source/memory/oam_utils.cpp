//
// Created by xdbeef on 06.05.18.
//

#include <cassert>
#include "oam_utils.hpp"
#include "../globals_declarations.hpp"

namespace oam_utils {

    //TODO Clean only the higher addresses of memory, don't clean up the hud and main dude sprites, so the blinking
    // that the cleaning causes would be less visible.
    bool clean_unused_oam() {

        global::clean_unused_oam_timer += *global::timer;

        if (/*global::clean_unused_oam_timer > 250 && */global::main_oam_manager->current_oam_id_tiles >= 120) {

//            for (auto &sprite_info : global::sprite_infos) {
//                sprite_info->entry = nullptr; //fixme - shouldn't this be deleted first? i guess no
//                delete sprite_info;
//                sprite_info = nullptr;
//            }

            global::main_oam_manager->clear_sprite_attributes();
            global::sub_oam_manager->clear_sprite_attributes();

            global::hud->delete_sprites();
            global::main_dude->deleteSprite();
            global::main_dude->whip->deleteSprite();

            std::vector<MovingObject *>::iterator iter;
            for (iter = global::sprites.begin(); iter != global::sprites.end();) {

                iter.operator*()->deleteSprite();

                if (iter.operator*()->ready_to_dispose) {
                    delete iter.operator*();
                    iter = global::sprites.erase(iter);
                } else
                    ++iter;
            }


//            for (auto &sprite_info: global::sprite_infos) {
//                if (sprite_info != nullptr) {
//                    printf("ASSERTION FALSE");
//                    for(int a =0;a<5*60;a++)
//                        swiWaitForVBlank();
//                }
//            }
//https://stackoverflow.com/questions/2275076/is-stdvector-copying-the-objects-with-a-push-back
            global::sprite_infos.clear();

//            for (int a = 0; a < global::sprites.size(); a++) {
//                if (global::sprites.at(a)->ready_to_dispose) {
//                    delete (global::sprites.at(a));
//                    global::sprites.erase(global::sprites.begin() + a);
//                }
//            }


            global::main_dude->initSprite();
            global::main_dude->whip->initSprite();

            for (int a = 0; a < global::sprites.size(); a++) {
                //fixme - being killed not always means it's ready for disposing!
                if (!global::sprites.at(a)->ready_to_dispose /*&& !global::sprites.at(a)->killed*/) {
                    global::sprites.at(a)->initSprite();
                }
            }

            global::hud->init_sprites();

//            global::clean_unused_oam_timer = 0;
            return true;
        }

        return false;
    };


    void delete_all_sprites() {

        //possible memory leak?
//        global::main_oam_manager->delete_sprite_infos();
//        global::sub_oam_manager->delete_sprite_infos();

//        for (auto &sprite_info : global::sprite_infos) {
//            if (sprite_info != nullptr) {
//                sprite_info->entry = nullptr; //fixme - shouldn't this be deleted first? i guess no
//                delete sprite_info;
//                sprite_info = nullptr;
//            }
//        }

        global::main_oam_manager->clear_sprite_attributes();
        global::sub_oam_manager->clear_sprite_attributes();

        global::main_dude->deleteSprite();
        global::main_dude->whip->deleteSprite();

        global::hud->delete_sprites();

        for (auto &sprite : global::sprites) {
            sprite->deleteSprite(); //deletes its SpriteInfos and nullptrs them
            delete sprite; //deletes sprite itself
        }

        for (auto &sprite : global::sprites_to_add) {
            sprite->deleteSprite(); //deletes its SpriteInfos and nullptrs them
            delete sprite; //deletes sprite itself
        }

        global::sprites.clear(); //deletes pointers to the sprites removed above - they're not nullptrs!
        global::sprites_to_add.clear(); //deletes pointers to the sprites removed above - they're not nullptrs!

//Assertion will always be false, pointers are copied when pushed to the vector
//        int c =0;
//        for (auto &sprite_info: global::sprite_infos) {
//            if (sprite_info != nullptr) {
//                printf("ASSERTION FALSE %i", c);
//                for(int a =0;a<5*60;a++)
//                    swiWaitForVBlank();
//            }
//            c++;
//        }
//https://stackoverflow.com/questions/2275076/is-stdvector-copying-the-objects-with-a-push-back
        global::sprite_infos.clear(); //deletes pointers to the SpriteInfos deleted above - they're not nullptrs!


    }
}