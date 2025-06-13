#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/UILayer.hpp>

using namespace geode::prelude;

class $modify(SteppedBaseGameLayer, GJBaseGameLayer) {
    struct Fields {
        std::vector<Ref<CheckpointObject>> states;
        bool paused = true;
        bool steppingUpdate = false;
    };

    bool getPausedUpdate();

    virtual void update(float dt);
    void checkRepellPlayer(); // Runs every tick

    void stepFrame();

    void storeState();
    void restoreState();
};

class $modify(SteppedUILayer, UILayer) {
    struct Fields {
        RepeatableMenuItemSpriteExtra* next;
        RepeatableMenuItemSpriteExtra* prev;
        RepeatableMenuItemSpriteExtra* pause;
        CCMenu* menu;
    };

    bool init(GJBaseGameLayer* bgl);

    void onTogglePaused(CCObject*);
    void onPreviousFrame(CCObject*);
    void onStepFrame(CCObject*);

    void updateUI();
};

/*
#ifndef GEODE_IS_IOS
class $modify(SteppedKeyboardDispatcher, CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(enumKeyCodes key, bool isKeyDown, bool isKeyRepeat);
};
#endif
*/
