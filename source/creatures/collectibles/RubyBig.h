//
// Created by xdbeef on 16.09.18.
//

#ifndef SPELUNKYDS_RUBY_BIG_H
#define SPELUNKYDS_RUBY_BIG_H

#include <cstdlib>

#include "../_BaseCreature.h"
#include "../../interfaces/Moniez.hpp"
#include "../SpriteInfo.h"

class RubyBig : public BaseCreature, public Moniez {

public:

    static constexpr u8 ruby_big_sprite_width = 8;
    static constexpr u8 ruby_big_sprite_height = 8;
    static constexpr u16 ruby_big_physical_width = 8;
    static constexpr u16 ruby_big_physical_height = 8;
    static constexpr SpritesheetType ruby_big_spritesheet_type = SpritesheetType::MONIEZ_RUBY;

    RubyBig(int x, int y) : BaseCreature(
            x,
            y,
            ruby_big_sprite_width,
            ruby_big_sprite_height,
            ruby_big_spritesheet_type,
            ruby_big_physical_width,
            ruby_big_physical_height
    ), Moniez(VALUE_RUBY_BIG) {
        activated = true;
        _collected = false;
        _collectible_timer = 500;

        int type = rand() % 3;
        //randomly select ruby color
        switch (type) {
            case 0:
                sprite_type = SpriteType::S_MONIEZ_RUBY_BIG_RED;
                break;
            case 1:
                sprite_type = SpriteType::S_MONIEZ_RUBY_BIG_GREEN;
                break;
            case 2:
                sprite_type = SpriteType::S_MONIEZ_RUBY_BIG_BLUE;
                break;
            default:
                break;
        }

        activated = true;
        _collected = false;
        init_sprites();
    }

    // Base creature overrides

    void update_creature_specific() override;

    void introduce_yourself() override { printf("WHIP\n"); };

    void apply_dmg(int dmg_to_apply) override {};

    bool can_update_collidable() const override { return true; }

    // IRenderable overrides

    void init_sprites() override;

    void delete_sprites() override;

    void update_sprites_position() override;

    // ICollidable overrides

    bool can_apply_friction() const override { return true; }

    bool can_apply_gravity() const override { return true; }

    // Other, creature specific

    //rename to vectors_update_timer?
    double pos_inc_timer{};
    SpriteInfo *mainSpriteInfo{};
    SpriteInfo *subSpriteInfo{};
    u8 *frameGfx{};
};


#endif //SPELUNKYDS_RUBY_BIG_H
