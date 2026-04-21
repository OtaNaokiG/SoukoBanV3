#pragma once
#include "DxLib.h"
//マップの1マス＝60×60px
#define TILESIZE 60

const int screenWIDTH = 1200, screenHEIGHT = 720;

struct Vector2 {
    int x = 0, y = 0;
};

struct Box {
    Vector2 pos;

    bool isOnGoal = false;
    bool isPushable = false;

    int GHandle = -1;

    void GetPushed(Vector2 dir) {
        pos.x += dir.x * TILESIZE;
        pos.y += dir.y * TILESIZE;
    }

    void Draw() {
        DrawGraph(pos.x, pos.y, GHandle, TRUE);
    }
};