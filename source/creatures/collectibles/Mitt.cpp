//
// Created by xdbeef on 19.05.18.
//


#include "../SpritesheetType.hpp"
#include "SpringShoes.hpp"
#include "../../GlobalsDeclarations.hpp"
#include "../../collisions/Collisions.hpp"
#include "../../../build/gfx_saleable.h"
#include "Mitt.hpp"
#include "../../decorations/GotCollectible.hpp"
#include "../SpriteUtils.hpp"

#define MITT_POS_INC_DELTA 15

void Mitt::update_creature_specific() {

    if (_ready_to_dispose) return;

    sprite_utils::set_vertical_flip(false, mainSpriteInfo, subSpriteInfo);
    sprite_utils::set_horizontal_flip(false, mainSpriteInfo, subSpriteInfo);
    update_anim_icon(_x, _y, _physical_width);

    if (collected) return;

    if (_bought && check_if_can_be_equipped())
        equip();
    else if (!_bought && !hold_by_main_dude)
        check_if_can_be_pickuped();

    if (hold_by_main_dude) {
        set_pickuped_position(4, -4);
        if (shopping_transaction(this)) {
            collected = true;
            equip();
        }
    }

    update_sprites_position();
}

void Mitt::init_sprites() {

    delete_sprites();

    subSpriteInfo = global::sub_oam_manager->initSprite(gfx_saleablePal, gfx_saleablePalLen,
                                                        nullptr, _sprite_size, ObjSize::OBJSIZE_16,
                                                        _spritesheet_type, true, false, LAYER_LEVEL::MIDDLE_TOP);
    mainSpriteInfo = global::main_oam_manager->initSprite(gfx_saleablePal, gfx_saleablePalLen,
                                                          nullptr, _sprite_size, ObjSize::OBJSIZE_16,
                                                          _spritesheet_type, true, false, LAYER_LEVEL::MIDDLE_TOP);

    sprite_utils::set_visibility(true, mainSpriteInfo, subSpriteInfo);
    sprite_utils::set_vertical_flip(false, mainSpriteInfo, subSpriteInfo);
    sprite_utils::set_horizontal_flip(false, mainSpriteInfo, subSpriteInfo);
    update_sprites_position();
    match_animation();
}

void Mitt::update_sprites_position() {
    if (collected) {
        mainSpriteInfo->entry->priority = OBJPRIORITY_0;
        sprite_utils::set_entry_xy(mainSpriteInfo, _x, _y);
        subSpriteInfo->entry->isHidden = true;
        mainSpriteInfo->entry->isHidden = false;
    } else {
        int main_x, main_y, sub_x, sub_y;
        get_x_y_viewported(&main_x, &main_y, &sub_x, &sub_y);
        sprite_utils::set_entry_xy(mainSpriteInfo, main_x, main_y);
        sprite_utils::set_entry_xy(subSpriteInfo, sub_x, sub_y);
    }

}

void Mitt::equip() {
    collected = true;

    auto *g = new GotCollectible(_x - 12, _y - 20, GotCollectible::Type::ITEM);
    global::decorations_to_add.push_back(g);

    if (!global::main_dude->carrying_mitt) {
        global::main_dude->carrying_mitt = true;
        update_sprites_position();
        _x = HUD_ITEMS_ROW_X;
        _y = global::hud->items_offset_y;
        global::hud->increment_offset_on_grabbed_item();
    } else {
        sprite_utils::set_visibility(false, mainSpriteInfo, subSpriteInfo);
        _ready_to_dispose = true;
    }

}

void Mitt::match_animation() {
    frameGfx = sprite_utils::get_frame((u8 *) gfx_saleableTiles, _sprite_size, 0);
    sprite_utils::update_frame(frameGfx, _sprite_size, mainSpriteInfo, subSpriteInfo);
}

void Mitt::delete_sprites() {
    delete mainSpriteInfo;
    delete subSpriteInfo;
    mainSpriteInfo = nullptr;
    subSpriteInfo = nullptr;
}
