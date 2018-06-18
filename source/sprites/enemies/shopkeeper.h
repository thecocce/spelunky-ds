//
// Created by xdbeef on 25.05.18.
//

#ifndef SPELUNKYDS_SHOPKEEPER_H
#define SPELUNKYDS_SHOPKEEPER_H

#define MAX_X_SPEED_SHOPKEEPER 4
#define MAX_Y_SPEED_SHOPKEEPER 4

#define SHOPKEEPER_PHYSICAL_HEIGHT 16
#define SHOPKEEPER_PHYSICAL_WIDTH 16
#define SHOPKEEPER_SPRITE_HEIGHT 16
#define SHOPKEEPER_SPRITE_WIDTH 16

#define SHOPKEEPER_STUN_TIME 7000
#define SHOPKEEPER_HITPOINTS 3

#include "../moving_object.h"
#include "../sprite_state.h"
#include "../sprite_info.h"

class Shopkeeper : public MovingObject {

public:

    //todo shopkeeper's name

    Shopkeeper();

    void updateOther() override {};

    void init() override;

    void draw() override;

    void apply_dmg(int dmg_to_apply) override;

    void updateTimers() override {};

    void updateSpeed() override;

    void updateCollisionsMap(int x_current_pos_in_tiles, int y_current_pos_in_tiles) override;

    void updateCollisionsOtherMoving() override {};

    void onCollisionWithMainCharacter() override {};

    void initSprite() override;

    double pos_inc_timer{};

    SpriteInfo *mainSpriteInfo{};
    SpriteInfo *subSpriteInfo{};

    u8 *frameGfx{};

    SpriteState sprite_state{};
    int waitTimer{};
    int go_timer{};

    int anim_frame{};
    int anim_frame_timer{};

    int invert_speed_timer{};
    int blood_spawn_timer{};

    bool landlocked{};
    bool triggered{};
    bool stunned{};
    int stunned_timer{};

    int shop_bounds_left_x_px{};
    int shop_bounds_right_x_px{};
    int shop_bounds_up_y_px{};
    int shop_bounds_down_y_px{};

    bool introduced_shop_name{};

    void randomizeMovement();

    void set_position();

    void apply_walking_sprites();

    void apply_stunned_sprites();

    void make_some_movement();

    void check_if_can_be_triggered();

    void apply_stunned_carried_sprites();

    void apply_dead_carried_sprites();

    void apply_dead_sprites();

    void update_animation();

    void set_shop_bounds();

    void check_if_dude_in_shop_bounds();
};


#endif //SPELUNKYDS_SHOPKEEPER_H
