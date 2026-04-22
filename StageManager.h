#pragma once

/// <summary>
/// ・ステージが解放されてるか
/// ・今どのステージか
/// ・クリアしたか
/// ・ステージ管理は一個だけ(SceneManagerにある）
/// </summary>
class StageManager
{
private:
    static const int STAGE_MAX = 25;
    bool unlocked[STAGE_MAX];

    int currentStageNum = 0;
public:
    StageManager();

    void SetCurrentStage(int stageNum);
    int  GetCurrentStageNum() const; //今どこのステージにいるのかを渡す

    bool IsUnlocked(int stage);
    void Unlock(int stage);
};