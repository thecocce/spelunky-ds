//
// Created by xdbeef on 22.07.18.
//

#include <maxmod9.h>
#include "../../build/soundbank.h"
#include "../GlobalsDeclarations.hpp"
#include "SoundUtils.hpp"

void sound::start_menu_music() {
    //probably should load it only once, on start
//    mmLoadEffect(SFX_MTITLE);
//    global::menu_music_handler = mmEffect(SFX_MTITLE);
}

void sound::stop_menu_music() {
//    mmEffectCancel(global::menu_music_handler);
    //probably should not unload, due to memory fragmentation when loading/unloading every level
//    mmUnloadEffect(SFX_MTITLE);
}

void sound::start_cave_music() {
    //probably should load it only once, on start
//    mmLoadEffect(SFX_MCAVE);
//    global::cave_music_handler = mmEffect(SFX_MCAVE);
}

void sound::stop_cave_music() {
//    mmEffectCancel(global::cave_music_handler);
    //probably should not unload, due to memory fragmentation when loading/unloading every level
//    mmUnloadEffect(SFX_MCAVE);
}

void sound::load_sounds() {
    mmInitDefaultMem((mm_addr) soundbank_bin);
//    mmLoadEffect(SFX_XJUMP);
//    mmLoadEffect(SFX_XBREAK);
//    mmLoadEffect(SFX_XALERT);
//    mmLoadEffect(SFX_XARROWTRAP);
//    mmLoadEffect(SFX_XKISS);
//    mmLoadEffect(SFX_XJETPACK);
//    mmLoadEffect(SFX_XWHIP);
//    mmLoadEffect(SFX_XCOIN);
//    mmLoadEffect(SFX_XTHROW);
//    mmLoadEffect(SFX_XGEM);
//    mmLoadEffect(SFX_XEXPLOSION);
//    mmLoadEffect(SFX_XSTEPS);
//    mmLoadEffect(SFX_XLAND);
//    mmLoadEffect(SFX_XBAT);
//    mmLoadEffect(SFX_XPICKUP);
//    mmLoadEffect(SFX_XCLIMB1);
//    mmLoadEffect(SFX_XCLIMB2);
//    mmLoadEffect(SFX_XHIT);
//    mmLoadEffect(SFX_XHURT);
//    mmLoadEffect(SFX_XDIE);
//    mmLoadEffect(SFX_XCHESTOPEN);
//    mmLoadEffect(SFX_XSHOTGUN);
}


