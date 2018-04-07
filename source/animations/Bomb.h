//
// Created by xdbeef on 04.04.18.
//

#ifndef SPELUNKYDS_BOMB_H
#define SPELUNKYDS_BOMB_H

#define BOUNCE_VELOCITY_LOSS 0.65
#define BOMB_SIZE 8
#define ARMED_TIME_BLINK_SLOW 2000
#define ARMED_TIME_BLINK_FAST 2000

#define MAX_X_SPEED_BOMB 1
#define MAX_Y_SPEED_BOMB 1.5

#include <nds/arm9/sprite.h>
#include "../level_layout/SpriteInfo.h"
#include "../level_layout/MapTile.h"
#include "Camera.h"
#include "../level_layout/LevelGenerator.h"
#include "../sprites/MovingObject.h"

class Bomb : public MovingObject {

public:

    void updateOther() override {};

    void init(){};

    void draw() {};

    void updateTimers() {};

    void updatePosition() {};

    void updateSpeed() {};

    void updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) {};

    void updateCollisionsOtherMoving() {};

    void onCollisionWithMainCharacter() {};


    double *timer;
    double pos_inc_timer;

    SpriteInfo *mainSpriteInfo;
    SpriteInfo *subSpriteInfo;

    bool carried;
    bool armed;

    int armedTimer;

    LevelGenerator *levelGenerator;

    void init(int x, int y, bool armed, LevelGenerator *l, double *timer);

    void update(Camera *camera);

    void updateCollisions();

    void checkCollisionWithMap(MapTile *mapTiles[32][32], int xx, int yy);

    void applyFriction();
};


#endif //SPELUNKYDS_BOMB_H
