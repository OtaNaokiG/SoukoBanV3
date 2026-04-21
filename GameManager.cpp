#include "GameManager.h"

#include"Functions.h"
#include"Handles.h"

GameManager::GameManager() {

}

void GameManager::Update() {

    input.Update();

    player->Update(input, this);

    UpdateBoxOnGoal();

    //クリア（箱が全部乗った）
    if (IsClear()) {
        clearTimer++;
        if (clearTimer >= CLEAR_WAIT) {
            isGameOver = true;
        }
    }
}

void GameManager::Draw() {
    // 背景
    for (Box* t : tiles) {
        t->Draw();
    }

    // 箱
    for (Box* b : boxes) {
        b->Draw();
    }

    // プレイヤー
    player->Draw();

    //クリア（箱が全部乗った）
    if (isGameOver) {
        DrawString(500, 300, "CLEAR!!", GetColor(255, 255, 0));
    }
}


void GameManager::SetStageData(const StageData* data) {
    stageData = data;

    //マップを中央に描画
    int mapWidth = data->widthAmount * TILESIZE;
    int mapHeight = data->heightAmount * TILESIZE;
    mapOffSet.x = (screenWIDTH - mapWidth) / 2;
    mapOffSet.y = (screenHEIGHT - mapHeight) / 2;

    //ステージデータを全部確認
    for (int y = 0; y < data->heightAmount; y++) {
        for (int x = 0; x < data->widthAmount; x++) {
            //配置するマスを決める
            Vector2 pos;
            pos.x = mapOffSet.x + x * TILESIZE;
            pos.y = mapOffSet.y + y * TILESIZE;
            //判別
            switch (data->stageData[y][x]) {
            case WALL:
                tiles.push_back(Instantiate(pos, WallGHandle));
                break;

            case FLOOR:
                tiles.push_back(Instantiate(pos, GroundGHandle));
                break;

            case GOAL:
                tiles.push_back(Instantiate(pos, GreenSpotGHandle));;
                // グリッド座標で保存
                goals.push_back({ x, y });
                break;

            case BOX:
                tiles.push_back(Instantiate(pos, GroundGHandle));//箱の下にも床を設置
                boxes.push_back(InstantiateBox(pos, true, BoxGHandle));
                break;

            case PLAYER:
                //プレイヤーを生成する位置にも地面を配置
                tiles.push_back(Instantiate(pos, GroundGHandle));
                player = new Player(pos);
                break;

            case SPACE:
                //何もない置かない
                break;

            case BOXandGOAL:
                tiles.push_back(Instantiate(pos, GroundGHandle));//箱の下にも床を設置
                boxes.push_back(InstantiateBox(pos, true, BoxGHandle));

                tiles.push_back(Instantiate(pos, GreenSpotGHandle));;
                // グリッド座標で保存
                goals.push_back({ x, y });
                break;
            }
        }
    }
    
}

//プレイヤーを進ませない壁
bool GameManager::IsWall(int x, int y) const {
    if (x < 0 || y < 0 || x >= stageData->widthAmount || y >= stageData->heightAmount) {
        return true; // 外は壁扱い
    }

    return stageData->stageData[y][x] == WALL;
}

//押せる箱を調べる
bool GameManager::IsBox(int x, int y) const {
    for (Box* b : boxes) {
        int bx = (b->pos.x - mapOffSet.x) / TILESIZE;
        int by = (b->pos.y - mapOffSet.y) / TILESIZE;

        if (bx == x && by == y && b->isPushable) {
            return true;
        }
    }
    return false;
}

Box* GameManager::GetBox(int x, int y)const {
    for (Box* b : boxes) {
        int bx = (b->pos.x - mapOffSet.x) / TILESIZE;
        int by = (b->pos.y - mapOffSet.y) / TILESIZE;

        if (bx == x && by == y && b->isPushable) {
            return b;
        }
    }
    return nullptr;
}

bool GameManager::IsClear() const {

    for (Box* b : boxes) {
        if (!b->isOnGoal) {
            return false; // 1個でも乗ってない箱がある
        }
    }
    return true; // 全部乗ってる
}

//ゴールの上に載っているかを確認する関数
void GameManager::UpdateBoxOnGoal() {

    for (Box* b : boxes) {

        // 一旦false
        bool onGoal = false;

        int bx = (b->pos.x - mapOffSet.x) / TILESIZE;
        int by = (b->pos.y - mapOffSet.y) / TILESIZE;

        //座標がゴールと一致していたら
        for (const Vector2& goal : goals) {
            if (bx == goal.x && by == goal.y) {
                onGoal = true;
                break;
            }
        }
        //箱の状態を変更
        b->isOnGoal = onGoal;

        if (onGoal) {//画像を変更
            b->GHandle = GreenBoxGHandle;
        }
        else {
            b->GHandle = BoxGHandle;
        }
    }
}

GameManager::~GameManager() {
    //new・delete　解放
    for (Box* b : boxes) {
        delete b;
    }
    boxes.clear();

    //プレイヤー解放
    if (player != nullptr) {
        delete player;
    }
}