#include "Input.h"
#include "DxLib.h"
#include <cstring>

void Input::Update() {
    memcpy(oldKey, key, 256);
    GetHitKeyStateAll(key);
}

// ‰Ÿ‚µ‚½uŠÔ
bool Input::Press(int keyCode) {
    return key[keyCode] == 1 && oldKey[keyCode] == 0;
}

// ‰Ÿ‚µ‚Á‚Ï‚È‚µ
bool Input::Trigger(int keyCode) {
    return key[keyCode] == 1;
}