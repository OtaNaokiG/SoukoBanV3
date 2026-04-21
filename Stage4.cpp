#include "Stage4.h"
#include"stages.h"
void Stage4::Init(StageManager* stageManager) {
	StageBase::Init(stageManager);
	game.SetStageData(&stage4);

	stageText.text = "LEVEL 4";
	stageManager->SetCurrentStage(3);// ステージに4
}

SceneBase* Stage4::Update() {

	//シーン切替
	SceneBase* next = StageBase::Update();  // ← ここで受け取る
	if (next != nullptr) {
		return next;  // ← そのまま返す
	}

	game.Update();
	//ゲームオーバー
	if (game.isGameOver) {
		isGameOver = true;
	}
	return nullptr;
}

void Stage4::Draw() {
	game.Draw();
	StageBase::Draw();
}