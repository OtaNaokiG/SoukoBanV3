#pragma once
#include "Variables.h"
#include"stages.h"
#include "Input.h"

#include <stack>

class GameManager;

enum Direction {
    DIR_DOWN,
    DIR_UP,
    DIR_LEFT,
    DIR_RIGHT
};

//一個前にいたタイルの座標を保持 & 一個前の向き
struct PlayerState {
    Vector2 pos;
    Direction dir;
};


class Player {

private:
    int GHandle = 0;
    Vector2 DirToVec(Direction dir);
    Direction dir = DIR_UP; //キャラの向き

    std::stack<PlayerState> history;//一個前にいたタイルの座標を保持 & 一個前の向き

private:
    bool isMoving = false;
    //キャラが移動し始める前の...
    Vector2 moveStart;//最初にいた位置
    Vector2 moveEnd;//終点
    void TryMove(int dx, int dy, const GameManager* gm);
    void Move(Input& input, const GameManager* gm);
public:
    Vector2 pos;

public:
    void Update(Input& input, const GameManager* gm);
    void Draw();

   Player(Vector2 FirstPos);
    ~Player();

private:
    void MovementController(Input& input, const GameManager* gm);

public:
    void GoBackOneTile();
};