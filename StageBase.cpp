#include "StageBase.h"
#include "Handles.h"
#include"SelectStageScene.h"
#include"DxLib.h"

#include"stageHeaders.h"

void StageBase::Init(StageManager* stageManager) {

	thisStageManager = stageManager;

	pauseButton.SetButton({ 0, 0 }, PauseGHandle);
	goBackButton.SetButton({ 1000, 0 }, GoBackGHandle);
	returnButton.SetButton({ 1100, 0 }, RetryGHandle);

	pausedUi.SetTwoLayerUi("PAUSE");
	gameOverUi.SetTwoLayerUi("CLEAR");

	stageText = {
		{(screenWIDTH / 2) - 20, 18},
	   "LEVEL 1",
		CreateFontToHandle(NULL, 50, 2),
		GetColor(255, 255, 255),
	};
}

SceneBase* StageBase:: Update() {
	Vector2 mouse;
	GetMousePoint(&mouse.x, &mouse.y);


	
	//ポーズ中
	if (isPaused) {
		if (pausedUi.PlayButton.IsClicked(mouse)) {
			isPaused = false;
		}
		if (pausedUi.menuButton.IsClicked(mouse)) {
			return new SelectStageScene(); //選択画面シーン
		}
	}
	else if (isGameOver) {
		//次のステージの番号を保持
		int next = thisStageManager->GetCurrentStageNum() + 1;
		thisStageManager->Unlock(next);

		if (gameOverUi.PlayButton.IsClicked(mouse)) {
			//次のステージへ
			return CreataStage(next);
		}
		if (gameOverUi.menuButton.IsClicked(mouse)) {
			return new SelectStageScene(); //選択画面シーン
		}
	}
	else {
		if (pauseButton.IsClicked(mouse)) {			
			isPaused = !isPaused;
			//停止
		}
		if (goBackButton.IsClicked(mouse)) {
			game.PlayerGoBack();
			//巻き戻し
		}
		if (returnButton.IsClicked(mouse)) {
			int current = thisStageManager->GetCurrentStageNum();//今いるステージを取得して
			return CreataStage(current);//新しい自分を作る
			//やり直し
		}
	}
	return nullptr;
}

void StageBase::Draw() {
	UpUiBox();

	pauseButton.Draw();
	goBackButton.Draw();
	returnButton.Draw();

	if (isGameOver) {
		gameOverUi.Draw();
	}
	if (isPaused) {
		pausedUi.Draw();
	}
	stageText.Draw();
}

void StageBase::UpUiBox() {
	//1200 = 画面の幅
	DrawBox(0, 0, 1200,81, GetColor(180, 200, 220),TRUE);

}

SceneBase* StageBase::CreataStage(int stageNum) {
	switch (stageNum) {
	case 0: return new Stage1();
	case 1: return new Stage2();
	case 2: return new Stage3();
	case 3:return new Stage4();
	default: return new SelectStageScene();
	}
}