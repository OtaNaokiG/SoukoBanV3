#include "Stage1.h"
#include"stages.h"
void Stage1::Init(StageManager* stageManager) {
	StageBase::Init(stageManager);
	game.SetStageData(&stage1);

	stageText.text = "LEVEL 1";
	stageManager->SetCurrentStage(0);// ステージに１
}

SceneBase* Stage1::Update() {

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

void Stage1::Draw() {
	game.Draw();
	StageBase::Draw();
}