#include "Toggles.h"

Toggles::Toggles() {
    Switch case_sensitive(true, "Case sensitive search is now ");
    Switch and_or(true, "AND/OR search is now ");
    Switch ranking(false, "Ranking search is now");
}

void Toggles::turnToggle(Switch &toggle) {
    toggle.button = !toggle.button;
    toggle.on_off = (toggle.button ? "ON" : "OFF");
    toggle.message = toggle.sentence + toggle.on_off;
}

Toggles::~Toggles() {
    
}