//
// Created by xdbeef on 27.05.18.
//

#ifndef SPELUNKYDS_GAME_STATE_H
#define SPELUNKYDS_GAME_STATE_H

#include "../../tiles/map_tile_type.h"

class GameState {
public:
    bool bombed{};
    bool splash_screen{};
    bool levels_transition_screen{};
    bool scores_screen{};
    bool in_main_menu{};

    void start_new_game();
    void start_main_menu();
    void start_scores();

    void start_level_transition_screen();

    void start_next_level();

    void handle_changing_screens();

    void set_position_to(MapTileType t);
};

#endif //SPELUNKYDS_GAME_STATE_H
