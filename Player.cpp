#include "Player.h"
#include "GameManager.h"
#include "Handles.h"


void Player::Update(Input& input, const GameManager* gm) {
    Move(input, gm);
}

void Player::Draw() {
    GHandle = PFront;

    //画像切替
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
    //動いていたら入力を受け付けない
    if (!isMoving) {

        if (input.Press(KEY_INPUT_RIGHT)) {
            dir = DIR_RIGHT;
            TryMove(1, 0, gm);
        }
        else if (input.Press(KEY_INPUT_LEFT)) {
            dir = DIR_LEFT;
            TryMove(-1, 0, gm);
        }
        else if (input.Press(KEY_INPUT_UP)) {
            dir = DIR_UP;
            TryMove(0, -1, gm);
        }
        else if (input.Press(KEY_INPUT_DOWN)) {
            dir = DIR_DOWN;
            TryMove(0, 1, gm);
        }
    }
}

void Player::TryMove(int dx, int dy, const GameManager* gm) {

    int nextX = pos.x + dx * TILESIZE;
    int nextY = pos.y + dy * TILESIZE;

    // 壁チェック
    Vector2 offset = gm->GetMapOffset();
    int gridX = (nextX - offset.x) / TILESIZE;
    int gridY = (nextY - offset.y) / TILESIZE;

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
        box->StartMove(dirVec);
    }

    // 移動開始
    isMoving = true;
    moveStart = pos;
    moveEnd = { nextX, nextY };
     //移動前の座標と向きを保存
    history.push({ pos, dir });
    
}

void Player::Move(Input& input, const GameManager* gm) {
    if (isMoving) {
        // 1フレームごとに少しずつ移動
        Vector2 diff = moveEnd - pos;//moveEnd - pos で「残り距離」を求める

        if (abs(diff.x) <= objectsSpeed && abs(diff.y) <= objectsSpeed) {
            pos = moveEnd;
            isMoving = false;
        }
        else {
            pos.x += (diff.x > 0 ? objectsSpeed : (diff.x < 0 ? -objectsSpeed : 0));
            pos.y += (diff.y > 0 ? objectsSpeed : (diff.y < 0 ? -objectsSpeed : 0));
        }
        return;
    }
    // 移動していないときだけ入力を受け付ける
    MovementController(input, gm);
}



void Player::GoBackOneTile() {
    if (history.empty()) return;

    PlayerState prev = history.top();
    history.pop();

    pos = prev.pos;
    dir = prev.dir;
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