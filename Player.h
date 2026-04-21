#pragma once
#include "Variables.h"
#include"stages.h"
#include "Input.h"
class GameManager;
enum Direction {
    DIR_DOWN,
    DIR_UP,
    DIR_LEFT,
    DIR_RIGHT
};


class Player {

private:
    int GHandle = 0;
    Vector2 DirToVec(Direction dir);
    Direction dir = DIR_UP; //ƒLƒƒƒ‰‚ÌŒü‚«
public:
    Vector2 pos;

public:
    void Update(Input& input, const GameManager* gm);
    void Draw();

   Player(Vector2 FirstPos);
    ~Player();

private:
    void MovementController(Input& input, const GameManager* gm);
};