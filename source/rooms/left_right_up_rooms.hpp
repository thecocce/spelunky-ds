//
// Created by xdbeef on 02.05.18.
//

#ifndef SPELUNKYDS_LEFTRIGHTUPROOMS_H
#define SPELUNKYDS_LEFTRIGHTUPROOMS_H


static int left_right_up_rooms[6][10][10] = {
        {
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                {0,  0, 4, 4, 4, 4, 4, 0, 0, 0},
                {0, 0, 0, 0, 0, 0,  9, 0, 0, 0},
                {0, 0,  0, 0, 0, 0, 10, 2, 2, 2},
                {2, 2, 13, 0, 0, 0, 9, 3, 3,  3},
                {3, 3, 4, 0, 0, 0, 9, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 5, 0, 0,  0},
                {0, 2, 2, 2, 0, 2, 2, 5, 0, 0},
                {2, 7, 8, 5, 2, 1, 1, 2, 2, 2}
        },
        {
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                {0, 2, 2, 0, 0, 0, 0, 0, 0, 3},
                {0,  7, 6, 0, 0, 9, 0, 0, 0, 0},
                {0, 3, 3, 4, 4, 10, 0, 0, 0, 0},
                {0, 0,  0, 0, 0, 9, 0,  0, 0, 2},
                {0, 0, 4,  4, 4, 9, 0, 0, 0,  3},
                {0, 0, 0, 0, 0, 9, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 9, 2, 4, 4,  0},
                {0, 0, 0, 0, 0, 9, 5, 0, 0, 0},
                {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
        },
        {
                {3, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 12},
                {0,  0, 0, 4, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0,  0, 0, 0, 0},
                {0, 2,  2, 4, 0, 0, 0,  0, 2, 2},
                {0, 3, 3,  0, 0, 0, 0, 0, 3,  3},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 4, 4, 0, 0, 0,  0},
                {0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
                {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
        },
        {
                {0, 4, 4, 2, 4, 0, 0, 0, 2, 0},
                {0, 0, 0, 3, 0, 0, 0, 0, 3, 4},
                {0,  0, 0, 0, 0, 0, 0, 0, 0, 12},
                {0, 9, 0, 0, 0, 0,  0, 0, 0, 0},
                {0, 10, 4, 4, 4, 4, 2,  0, 0, 0},
                {0, 9, 0,  0, 0, 0, 8, 0, 0,  0},
                {0, 9, 0, 5, 2, 0, 3, 2, 0, 0},
                {0, 9, 2, 4, 1, 0, 0, 6, 2,  0},
                {1, 3, 3, 5, 8, 2, 5, 7, 3, 0},
                {3, 0, 0, 0, 3, 3, 3, 3, 0, 0},
        },
        {
                {1, 3, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {3,  4, 0, 0, 0, 0, 12, 4, 4, 4},
                {0, 0, 0, 0, 0, 0,  0, 0, 0, 0},
                {0, 0,  0, 0, 0, 0, 0,  0, 9, 0},
                {0, 2, 4,  4, 4, 2, 2, 2, 10, 0},
                {0, 1, 0, 0, 0, 1, 1, 3, 9, 0},
                {2, 3, 0, 0, 0, 3, 3, 0, 9,  0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                {1, 2, 2, 2, 2, 2, 2, 2, 2, 5},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {13, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {2, 2, 0, 0, 0, 0,  0, 0, 0, 0},
                {7, 1,  9, 0, 0, 0, 0,  0, 0, 0},
                {3, 3, 10, 4, 4, 4, 5, 4, 2,  0},
                {0, 0, 9, 0, 0, 0, 0, 0, 3, 0},
                {2, 0, 9, 4, 4, 4, 4, 0, 12, 2},
                {6, 0, 9, 0, 0, 0, 0, 0, 0, 6},
                {1, 5, 2, 2, 2, 2, 2, 2, 2, 1},
        }
};


//1 snake
//2 bat
//3 spider
//9 arrow trap left oriented (12 tile type)
//10 arrow trap right oriented (13 tile type)


static int left_right_up_npcs[6][10][10] = {
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 1, 1, 5, 1, 0, 0, 0, 0,},
                {0,  0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 10, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0,  0, 0, 0, 0, 2,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0,  0, 0, 0, 0, 0, 0,  0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0,  0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 2, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0,  0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0,  0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 1, 13, 1, 5, 0, 0, 0, 0,  0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 9,},
                {0,  0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0,  0, 0, 0, 0, 0, 0, 0,},
                {0, 3, 2, 0, 0,  0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 1, 13, 5, 1, 0, 0, 0, 0,  0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
        {


                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 2, 3, 0, 0, 0, 0, 0, 0, 0},
                {0,  0, 0, 0, 0, 0, 0, 0, 0, 9},
                {0, 0, 1, 5, 6, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0,  0, 0, 0, 0, 5, 0, 0},
                {0, 0, 0, 0, 0,  0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 4, 1, 0, 0, 0},
                {0, 0, 0,  0, 0, 0, 0, 0, 0,  0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        },
        {

                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 9, 5, 1, 1},
                {0,  0, 0, 0, 0, 0, 0, 0, 0, 0},
                {2, 3, 0, 0, 0, 0, 2, 3, 2, 3},
                {0, 1, 1, 5, 1, 6, 1, 1, 0, 0},
                {0, 0, 0,  0, 0, 0, 0, 0, 0, 0},
                {1, 0, 2, 3, 2,  0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 4,  1, 4, 1, 4, 1, 13, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {10, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 5, 1, 6, 1, 1, 0},
                {0, 0, 0,  0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 1, 13, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 9, 0},
                {0, 1, 0,  4, 1, 4, 1, 1, 1,  0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        }
};

//1 if loot can be placed
static int left_right_up_loot[6][10][10] = {
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 1, 1, 1, 1, 1, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {1, 1, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 1, 1, 1, 0, 1, 0, 0, 0, 0,},
                {1, 0, 0, 0, 1, 0, 0, 0, 1, 1,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
        {
                {0, 1, 1, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 1, 1, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 1, 1, 1, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 1, 1, 1, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {1, 1, 1, 1, 1, 0, 0, 1, 1, 1,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 1, 1, 1, 0, 0, 0, 0, 1, 1,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {0, 0, 0, 0, 1, 1, 0, 0, 0, 0,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                {1, 1, 1, 1, 1, 1, 1, 0, 1, 1,},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        },
        {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 1, 1, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        }

};


#endif //SPELUNKYDS_LEFTRIGHTUPROOMS_H
