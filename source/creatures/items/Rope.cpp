//
// Created by xdbeef on 04.04.18.
//

#include <maxmod9.h>

#include "Rope.hpp"
#include "../../GlobalsDeclarations.hpp"
#include "../../../build/gfx_blood_rock_rope_poof.h"
#include "../../../build/soundbank.h"
#include "../../collisions/Collisions.hpp"
#include "../../tiles/LevelRenderingUtils.hpp"
#include "../SpriteUtils.hpp"

void Rope::update_creature_specific() {

    if (_ready_to_dispose) return;

    _expand_timer += *global::timer;

    for (int a = _rope_chain.size() - 1; a >= 0; a--) {

        _rope_chain.at(a)->update();

        if (_finished) {
            if (_expand_timer > 40) {
                if (!_rope_chain.at(a)->_active) {
                    _rope_chain.at(a)->_active = true;
                    _expand_timer = 0;
                }
            }
        }
    }

    if (activated && !_thrown && !_finished) {
        mmEffect(SFX_XTHROW);

        _thrown = true;
        _throwing_timer = 0;

        _x = floor_div(global::main_dude->_x + 0.5 * MainDude::main_dude_physical_width, TILE_W) * TILE_W +
             _physical_width * 0.5;
        _y -= 16;
        _y_speed = -4;
    }

    if (_thrown && !_finished) {
        _throwing_timer += *global::timer;
        add_rope_if_needed();
    }

    //checking if main dude can climb over the rope

    bool onTopOfClimbingSpace = global::main_dude->_y < _y + 6;
    global::main_dude->on_top_of_climbing_space = onTopOfClimbingSpace;

    for (unsigned long a = 0; a < _rope_chain.size(); a++) {

        if (_rope_chain.at(a)->_x + 5 > global::main_dude->_x &&
            _rope_chain.at(a)->_x + 5 < global::main_dude->_x + MainDude::main_dude_physical_width &&
            _rope_chain.at(a)->_y + 5 > global::main_dude->_y &&
            _rope_chain.at(a)->_y - 5 < global::main_dude->_y + MainDude::main_dude_physical_height &&
            _rope_chain.at(a)->_active
            && !onTopOfClimbingSpace) {
            if (!global::input_handler->r_bumper_down) {
                global::main_dude->can_climb_rope = true;
                if (global::input_handler->up_key_held) {
                    global::main_dude->_x = _rope_chain.at(a)->_x - 4;
                }
            }

            break;
        }
    }

    if (!_finished) {
        kill_creatures_if_have_speed(1);
    }

    update_sprites_position();

    if (_upper_collision) {
        if (!_finished) {
            set_sprite_throwing_finished();
            _finished = true;

            int temp_y = floor_div(this->_y + (0.5 * _physical_height), TILE_H);

            auto element = new RopeElement(_x, temp_y * TILE_H);
            element->update();
            _rope_chain.push_back(element);
        }
    }

}

void Rope::set_sprite_throwing() {
    u8 *frame_gfx = sprite_utils::get_frame((u8 *) gfx_blood_rock_rope_poofTiles, _sprite_size, 9);
    sprite_utils::update_frame(frame_gfx, _sprite_size, _main_sprite_info, _sub_sprite_info);
}

void Rope::set_sprite_throwing_finished() {
    u8 *frame_gfx = sprite_utils::get_frame((u8 *) gfx_blood_rock_rope_poofTiles, _sprite_size, 10);
    sprite_utils::update_frame(frame_gfx, _sprite_size, _main_sprite_info, _sub_sprite_info);
}

bool Rope::isThereChainForThisTile(int rope_y) {
    for (auto &a : _rope_chain) {
        if (a->_y == rope_y)
            return true;
    }
    return false;
}

void Rope::init_sprites() {

    delete_sprites();

    _sub_sprite_info = global::sub_oam_manager->initSprite(gfx_blood_rock_rope_poofPal, gfx_blood_rock_rope_poofPalLen,
                                                           nullptr, _sprite_size, ObjSize::OBJSIZE_8, BLOOD_ROCK_ROPE_POOF, true,
                                                           false, LAYER_LEVEL::MIDDLE_TOP);
    _main_sprite_info = global::main_oam_manager->initSprite(gfx_blood_rock_rope_poofPal,
                                                             gfx_blood_rock_rope_poofPalLen,
                                                             nullptr, _sprite_size, ObjSize::OBJSIZE_8, BLOOD_ROCK_ROPE_POOF, true,
                                                             false, LAYER_LEVEL::MIDDLE_TOP);

    sprite_utils::set_visibility(true, _main_sprite_info, _sub_sprite_info);

    if (!_finished)
        set_sprite_throwing();
    else
        set_sprite_throwing_finished();

    for (auto &a : _rope_chain)
        a->init_sprites();
}

void Rope::add_rope_if_needed() {

    int temp_y = floor_div(this->_y + (0.5 * _physical_height), TILE_H);

    if (!isThereChainForThisTile(temp_y * TILE_H)) {

        if (temp_y * TILE_H > _y) {

            auto *element = new RopeElement(_x, temp_y * TILE_H);
            element->update();
            _rope_chain.push_back(element);

            if ((_extended_rope && _rope_chain.size() == max_rope_chain_size_extended) ||
                (!_extended_rope && _rope_chain.size() == max_rope_chain_size)) {
                set_sprite_throwing_finished();
                _finished = true;
            }

        }
    }
}

void Rope::update_sprites_position() {
    int main_x, main_y, sub_x, sub_y;
    get_x_y_viewported(&main_x, &main_y, &sub_x, &sub_y);
    sprite_utils::set_entry_xy(_main_sprite_info, static_cast<u16>(main_x), static_cast<u16>(main_y));
    sprite_utils::set_entry_xy(_sub_sprite_info, static_cast<u16>(sub_x), static_cast<u16>(sub_y));
}

void Rope::delete_sprites() {
    delete _main_sprite_info;
    delete _sub_sprite_info;
    _main_sprite_info = nullptr;
    _sub_sprite_info = nullptr;
}

