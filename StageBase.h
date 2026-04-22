#pragma once
#include "SceneBase.h"
#include "StageManager.h"
#include "GameManager.h"
#include"Ui.h"

//ƒ{ƒ^ƒ““ü—Í

class StageBase :public SceneBase {

private:

	StageManager* thisStageManager = nullptr;

protected:

	bool isPaused = false;
	bool isGameOver = false;
protected:
	GameManager game;

public:
	void Init(StageManager* stageManager) override;
	SceneBase* Update() override;
	void Draw() override;

protected:
	Button pauseButton;
	Button goBackButton;
	Button returnButton;

	TwoLayerUi pausedUi;
	TwoLayerUi gameOverUi;

	LetterUi stageText;
	void UpUiBox();

protected:
	SceneBase* CreataStage(int stageNum);

	
};