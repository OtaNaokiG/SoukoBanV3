#pragma once
#include "SceneBase.h"
#include"Ui.h"

class SelectStageScene:public SceneBase
{
private:
    StageManager* ThisStageManager = nullptr;

private:
    LetterUi slectlvl;
public:
    void Init(StageManager* stageManager) override;
    SceneBase* Update() override;
    void Draw() override;
};

