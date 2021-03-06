//
// Created by xdbeef on 10.03.18.
//

#ifndef SPELUNKYDS_MAPTILE_H
#define SPELUNKYDS_MAPTILE_H

#include "MapTileType.hpp"
#include "nds.h"

/**
 * In SpelunkyDS there's a 512x512 px render space that can be filled with 8x8 tiles,
 * in the origial Spelunky, tiles are of 16 px width and 16 px height, so in SpelunkyDS it makes an array of 32x32
 * tiles, the smallest object that tile map can use is 8x8 px tile, so to have a 16x16px tile I need a 2x2 array
 * (called 'values') which will store 4 integer values that represent an index on the spritesheet, from which
 * graphics for this tile will be copied.
 * 32x32 makes a map of 3x3 rooms composed of 10x10 tiles + a frame of 1 undestroyable tile over the whole map.
 * sizeof(MapTile) == 225, whole 32x32 map makes 225 KB! That's a big chunk of the ~850 KB RAM, which is left for
 * allocation after the 3.1 MB game is loaded into 4 MB of RAM.
 */
class MapTile {
public:
    //https://stackoverflow.com/questions/629017/how-does-array100-0-set-the-entire-array-to-0
    u16 values[4]{};
    //index on the render space, takes values 0 to (512x512 / 8x8) = 4096
    //this index moves from the left-upper corner to the right-down corner, increments once every 8x8 tile
    u16 map_index[4]{};
    //this x,y means position on 32x32 MapTile array
    u8 x{}; //0-32
    u8 y{}; //0-32
    bool collidable{};
    bool destroyable{};
    bool exists{};
    MapTileType mapTileType{};

    void match_tile(MapTileType type);
};


#endif //SPELUNKYDS_MAPTILE_H
