//
// Created by xdbeef on 02.06.18.
//

#ifndef SPELUNKYDS_JETPACK_H
#define SPELUNKYDS_JETPACK_H


#include "../SpriteInfo.h"
#include "../Orientation.hpp"
#include "../_BaseCreature.h"
#include "../../interfaces/ShoppingObject.h"
#include "../animations/FallPoof.hpp"

//http://spelunky.wikia.com/wiki/jetpack
class Jetpack : public BaseCreature, public ShoppingObject {

public:
    
    static constexpr u16 jetpack_cost = 16000;
    static constexpr const char *jetpack_name = "JETPACK";
    static constexpr u8 jetpack_sprite_width = 16;
    static constexpr u8 jetpack_sprite_height = 16;
    static constexpr u16 jetpack_physical_width = 14;
    static constexpr u16 jetpack_physical_height = 12;
    static constexpr SpritesheetType jetpack_spritesheet_type = SpritesheetType::BAT_JETPACK;

    Jetpack(int x, int y) : BaseCreature(
            x,
            y,
            jetpack_sprite_width,
            jetpack_sprite_height,
            jetpack_spritesheet_type,
            jetpack_physical_width,
            jetpack_physical_height,
            CreatureType::JETPACK
    ), ShoppingObject(jetpack_cost, jetpack_name) {
        init_sprites();
        init_anim_icon();
        update_anim_icon(x, y, _physical_width);
    }

    ~Jetpack();

    // Base creature overrides

    void update_creature_specific() override;

    void introduce_yourself() override { printf("WHIP\n"); };

    void apply_dmg(int dmg_to_apply) override {};

    bool can_update_collidable() const override { return !collected; }

    // IRenderable overrides

    void init_sprites() override;

    void delete_sprites() override;

    void update_sprites_position() override;

    // ICollidable overrides

    bool can_apply_friction() const override { return true; }

    bool can_apply_gravity() const override { return true; }

    // Other, creature specific

    void equip();

    double _poof_spawn_timer{};
    bool collected{};
    SpriteInfo *_main_sprite_info{};
    SpriteInfo *_sub_sprite_info{};
    FallPoof *_poofs[2]{};

};


#endif //SPELUNKYDS_JETPACK_H
