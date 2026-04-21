#include "StageManager.h"
#pragma once


StageManager::StageManager() {
    for (int i = 0; i < STAGE_MAX; i++) {
        unlocked[i] = false;
    }

    unlocked[0] = true; // 最初のステージだけ解放
}

//今いるステージを受け取る
void StageManager::SetCurrentStage(int stageNum) {
    currentStageNum = stageNum;
}

int StageManager::GetCurrentStageNum() const {
    return currentStageNum;
}

bool StageManager::IsUnlocked(int stage) {
    return unlocked[stage];
}

void StageManager::Unlock(int stage) {
    if (stage >= 0 && stage < STAGE_MAX) {
        unlocked[stage ] = true;
    }
}