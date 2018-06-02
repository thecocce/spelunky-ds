//
// Created by xdbeef on 01.06.18.
//

#ifndef SPELUNKYDS_FALL_BLOOP_H
#define SPELUNKYDS_FALL_BLOOP_H


#include "../sprite_info.h"
#include "../sprite_state.h"
#include "../moving_object.h"

#define FALL_POOF_SPRITE_HEIGHT 8
#define FALL_POOF_SPRITE_WIDTH 8

class FallPoof : public MovingObject {

public:

    FallPoof();

    void updateOther() override {};

    void init() override;

    void draw() override;

    void initSprite() override;

    void apply_dmg(int dmg_to_apply) override {};

    void updateTimers() override {};

    void updateSpeed() override {};

    void updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) override {};

    void updateCollisionsOtherMoving() override {};

    void onCollisionWithMainCharacter() override {};

    int animFrameTimer{};
    int animFrame{};

    SpriteInfo *mainSpriteInfo{};
    SpriteInfo *subSpriteInfo{};

    u8 *frameGfx{};

    SpritesheetType spriteType{};

    void set_position();

};




#endif //SPELUNKYDS_FALL_BLOOP_H