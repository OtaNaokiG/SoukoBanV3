#include"DxLib.h"

#include "SelectStageScene.h"
#include"stageHeaders.h"
const int STAGE_MAX = 20;


const int GRID_COL = 5;
const int GRID_ROW = 5;

const int CELL_SIZE = 100;
const int MARGIN = 20;
const int START_X = 280;
const int START_Y = 150;

void SelectStageScene::Init(StageManager* stageManager) {
    ThisStageManager = stageManager;

    slectlvl = {
       {(screenWIDTH / 2) -30, 50},
       "SELECT LEVEL",
        CreateFontToHandle(NULL, 50, 2),
        GetColor(255, 255, 255),
    };
   
}

SceneBase* SelectStageScene::Update() {
    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);

    if (GetMouseInput() & MOUSE_INPUT_LEFT) {
        for (int i = 0; i < STAGE_MAX; i++) {

            int col = i % GRID_COL;
            int row = i / GRID_COL;

            int x = START_X + col * (CELL_SIZE + MARGIN);
            int y = START_Y + row * (CELL_SIZE + MARGIN);

            // ★ マウスが乗ってるかチェック
            if (mouseX >= x && mouseX <= x + CELL_SIZE &&
                mouseY >= y && mouseY <= y + CELL_SIZE) {

                if (ThisStageManager->IsUnlocked(i)) {

                    switch (i) {
                    case 0:
                        return new Stage1();
                    case 1:
                        return new Stage2();
                    case 2:
                        return new Stage3();
                    case 3:
                        return new Stage4();
                    }
                }
            }
        }
    }
    return nullptr;
}

void SelectStageScene::Draw() {

    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);

    for (int i = 0; i < STAGE_MAX; i++) {

        int col = i % GRID_COL;
        int row = i / GRID_COL;

        int x = START_X + col * (CELL_SIZE + MARGIN);
        int y = START_Y + row * (CELL_SIZE + MARGIN);

        bool isHover =
            (mouseX >= x && mouseX <= x + CELL_SIZE &&
                mouseY >= y && mouseY <= y + CELL_SIZE);

        int color;

        if (ThisStageManager->IsUnlocked(i)) {
            color = isHover ? GetColor(150, 255, 150)
                : GetColor(100, 220, 100);
        }
        else {
            color = isHover ? GetColor(200, 200, 200)
                : GetColor(180, 180, 180);
        }

        DrawBox(x, y, x + CELL_SIZE, y + CELL_SIZE, color, TRUE);

        if (isHover) {
            DrawBox(x, y, x + CELL_SIZE, y + CELL_SIZE, GetColor(255, 255, 0), FALSE);
        }

        DrawFormatString(x + 40, y + 40, GetColor(255, 255, 255), "%d", i + 1);
    }

    //文字UI
    slectlvl.Draw();
}