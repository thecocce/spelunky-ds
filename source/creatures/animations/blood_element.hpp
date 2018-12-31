//
// Created by xdbeef on 28.04.18.
//

#ifndef SPELUNKYDS_BLOODELEMENT_H
#define SPELUNKYDS_BLOODELEMENT_H

#include "../_base_creature.h"
#include "../sprite_info.h"


#define blood_sprite_width 8
#define blood_sprite_height 8
#define blood_physical_width 8
#define blood_physical_height 8
#define blood_spritesheet_type SpritesheetType::BLOOD_ROCK_ROPE_POOF


class BloodElement : public BaseCreature {

public:

    BloodElement(int x, int y) : BaseCreature(
            x,
            y,
            blood_sprite_width,
            blood_sprite_height,
            blood_spritesheet_type,
            blood_physical_width,
            blood_physical_height
    ) {
        _pos_update_delta = 30;
        init_sprites();
    }

    // Base creature overrides

    void update_creature_specific() override;

    void introduce_yourself() override { printf("WHIP\n"); };

    void apply_dmg(int dmg_to_apply) override {};

    void onCollisionWithMainCharacter() override {};

    // IRenderable overrides

    void init_sprites() override;

    void delete_sprites() override;

    void update_sprites_position() override;

    // ICollidable overrides

    bool can_update_collidable() override { return !finished; }

    bool can_apply_friction() override { return true; }

    bool can_apply_gravity() override { return true; }

    // Other, creature specific

    void match_animation();

    SpriteInfo *mainSpriteInfo {};
    SpriteInfo *subSpriteInfo {};
    u8 * frameGfx{};
    int currentFrame{};
    double frameTimer{};
    double pos_inc_timer{};
    double inactive_delay{};
    bool finished{};

};



#endif //SPELUNKYDS_BLOODELEMENT_H
