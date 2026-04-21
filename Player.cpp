#include "Player.h"
#include "GameManager.h"
#include "Handles.h"


void Player::Update(Input& input, const GameManager* gm) {
    MovementController(input, gm);
}

void Player::Draw() {
    GHandle = PFront;

    switch (dir) {
    case DIR_DOWN:
        GHandle = PFront;
        break;
    case DIR_UP:
        GHandle = PBack;
        break;
    case DIR_LEFT:
        GHandle = PLeft;
        break;
    case DIR_RIGHT:
        GHandle = PRight;
        break;
    }

    DrawGraph(pos.x, pos.y, GHandle, TRUE);
}

Player::Player(Vector2 FirstPos) {
    pos = FirstPos;
}
Player::~Player() {

}

void Player::MovementController(Input& input, const GameManager* gm) {

    //次の座標を加算するため　現在の座標を一時的に保持
    int nextX = pos.x;
    int nextY = pos.y;


    if (input.Press(KEY_INPUT_RIGHT)) {
        nextX += TILESIZE;
        dir = DIR_RIGHT;
    }

    if (input.Press(KEY_INPUT_LEFT)) {
        nextX -= TILESIZE;
        dir = DIR_LEFT;
    }

    if (input.Press(KEY_INPUT_UP)) {
        nextY -= TILESIZE;
        dir = DIR_UP;
    }

    if (input.Press(KEY_INPUT_DOWN)) {
        nextY += TILESIZE;
        dir = DIR_DOWN;
    }

    // マップ座標に変換
    Vector2 offset = gm->GetMapOffset();

    int gridX = (nextX - offset.x) / TILESIZE;
    int gridY = (nextY - offset.y) / TILESIZE;

    // 壁だったら進まない
    if (gm->IsWall(gridX, gridY)) return;

    //進む先が箱だったら
    if (gm->IsBox(gridX, gridY)) {
        // 押せるかチェックして処理
        Box* box = gm->GetBox(gridX, gridY);
        //キャラの向いてる方向を足してベクトルに変換
        Vector2 dirVec = DirToVec(dir);

        int nextBoxX = gridX + dirVec.x;
        int nextBoxY = gridY + dirVec.y;

        // 箱の先が壁 or 別の箱なら押せない
        if (gm->IsWall(nextBoxX, nextBoxY) || gm->IsBox(nextBoxX, nextBoxY)) {
            return;
        }

        // 押せる
        box->GetPushed(dirVec);
    }

    //移動
    pos.x = nextX;
    pos.y = nextY;
}


Vector2 Player::DirToVec(Direction dir) {
    switch (dir) {
    case DIR_RIGHT: return { 1, 0 };
    case DIR_LEFT:  return { -1, 0 };
    case DIR_UP:    return { 0, -1 };
    case DIR_DOWN:  return { 0, 1 };
    }
    return { 0, 0 }; // 念のため
}