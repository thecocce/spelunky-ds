//
// Created by xdbeef on 02.05.18.
//

#ifndef SPELUNKYDS_LEFTRIGHTDOWNROOMS_H
#define SPELUNKYDS_LEFTRIGHTDOWNROOMS_H

static int left_right_down_rooms[3][10][10] = {
        {
                {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                {0, 9, 0, 5, 0, 0, 0, 0, 0, 0},
                {4, 10, 4, 4, 0, 0, 0, 0, 0, 0},
                {0, 9, 0, 0, 0, 0, 0, 0, 0, 0},
                {4, 9, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 9, 0, 0,  0, 0, 0, 0, 0, 0},
                {0, 9, 0, 0, 0, 0, 5, 0, 0, 0},
                {3, 4, 4, 0, 0, 0, 4, 4, 4, 2},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {2, 2, 2, 0, 0, 0, 0, 0, 2, 1},
        },
        {
                {3, 3, 3, 3, 3, 3, 3, 3, 3, 7},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {0, 0,  0, 2, 0, 0, 0, 0, 0, 0},
                {2, 2, 2, 1, 4, 4, 0, 0, 0, 0},
                {3, 1, 1, 3, 0, 0, 0, 0, 2, 2},
                {0, 3, 3, 13, 0, 0, 0, 4, 3, 3},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 4, 4, 0, 0, 0, 0},
                {0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
                {2, 2, 0, 0, 0, 0, 0, 0, 2, 2},
        },
        {
                {3, 3, 3, 3, 3, 3, 3, 3, 3, 7},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {0, 0,  0, 2, 0, 0, 0, 0, 0, 0},
                {2, 2, 2, 1, 4, 4, 0, 0, 0, 0},
                {3, 1, 1, 3, 0, 0, 0, 0, 2, 2},
                {0, 3, 3, 0,  0, 0, 0, 4, 3, 3},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 4, 4, 0, 0, 0, 0},
                {0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
                {2, 2, 0, 0, 0, 0, 0, 0, 2, 2},
        }
};


//1 snake
//2 bat
//3 spider

static int left_right_down_npcs[3][10][10] = {
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 2, 0, 2, 3, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 3, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 2, 0, 3, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 3, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 3, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {2, 3, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
};



#endif //SPELUNKYDS_LEFTRIGHTDOWNROOMS_H
