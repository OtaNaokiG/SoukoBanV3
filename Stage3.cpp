#include "Stage3.h"
#include"stages.h"
void Stage3::Init(StageManager* stageManager) {
	StageBase::Init(stageManager);
	game.SetStageData(&stage3);

	stageText.text = "LEVEL 3";
	stageManager->SetCurrentStage(2);// ステージに3
}

SceneBase* Stage3::Update() {

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

void Stage3::Draw() {
	game.Draw();
	StageBase::Draw();
}