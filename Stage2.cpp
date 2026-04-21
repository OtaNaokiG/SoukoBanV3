#include "Stage2.h"

void Stage2::Init(StageManager* stageManager) {
	StageBase::Init(stageManager);
	game.SetStageData(&stage2);

	stageText.text = "LEVEL 2";
	stageManager->SetCurrentStage(1);// ステージに２
}

SceneBase* Stage2::Update() {

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

void Stage2::Draw() {
	game.Draw();
	StageBase::Draw();
}