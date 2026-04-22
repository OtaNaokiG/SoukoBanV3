#pragma once
#include "DxLib.h"
//マップの1マス＝60×60px
#define TILESIZE 60

constexpr int screenWIDTH = 1200, screenHEIGHT = 720;
//箱とかプレイヤーがみんな同じスピードにしたいから
constexpr int objectsSpeed = 4; //定数にしました

struct Vector2 {
    int x = 0, y = 0;

    //演算子オーバーロード
    Vector2 operator-(const Vector2& other) const {
        return { x - other.x, y - other.y };
    }

    Vector2 operator+(const Vector2& other) const {
        return { x + other.x, y + other.y };
    }
};


struct Box {
    Vector2 pos;

    bool isOnGoal = false;
    bool isPushable = false;

    int GHandle = -1;

    bool isMoving = false;
    Vector2 moveStart;
    Vector2 moveEnd;

    void Update();
    void Draw() {
        DrawGraph(pos.x, pos.y, GHandle, TRUE);
    }

    void StartMove(Vector2 dir);
};

