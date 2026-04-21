#pragma once
#include "StageBase.h"
class Stage1:public StageBase
{
	void Init(StageManager* stageManager) override;
	SceneBase* Update() override;
	void Draw() override;
};

