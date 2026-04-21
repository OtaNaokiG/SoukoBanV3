#include "SceneTitle.h"
#include "DxLib.h"
#include"SelectStageScene.h"

#include"Variables.h"


void SceneTitle::Init(StageManager* stageManager) {


    titleFontHandle = CreateFontToHandle(NULL, 100, 10);

    title = {
       {screenWIDTH / 2, 200},
       "SOKOBAN",
        titleFontHandle,
        GetColor(255, 255, 255),
    };

    playButton.SetButton({ 460, 350 }, PlayButtonGHandle);
    playButton.w = 282;//ボタンの判定の大きさを再設定
}

SceneBase* SceneTitle::Update() {
    Vector2 mouse;
    GetMousePoint(&mouse.x, &mouse.y);

    if (playButton.IsClicked(mouse)) {
        return new SelectStageScene(); //選択画面シーン
    }

	if (CheckHitKey(KEY_INPUT_SPACE)) {
        return new SelectStageScene(); //選択画面シーン
	}
	return nullptr;
}

void SceneTitle::Draw() {

    title.Draw();
    playButton.Draw();

}
