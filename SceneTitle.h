#pragma once
#include "SceneBase.h"
#include"Ui.h"
class SceneTitle :public SceneBase {
private:
	LetterUi title;
	int titleFontHandle = -1;

	Button playButton;

public:
	void Init(StageManager* stageManager) override;
	SceneBase* Update() override;
	void Draw() override;
};