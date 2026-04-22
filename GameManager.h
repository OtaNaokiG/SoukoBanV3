#pragma once
#include "stages.h"
#include "Variables.h"
#include "Player.h"
#include "Input.h"
#include <vector>

//ゲームの管理
class GameManager
{
private:
	//キー状態・入力を管理
	Input  input;
	//ゲームオーバーになった時少し時間を置くため
	int clearTimer = 0;
	const int CLEAR_WAIT = 60; // 60フレーム（約1秒）
public:
	bool isGameOver = false;

private:
	Vector2 mapOffSet;//マップを中央に描画するため
public:
	Vector2 GetMapOffset()const { return mapOffSet; }

private:
	const StageData* stageData = nullptr;

	std::vector<Box*> tiles; // 床・壁・ゴール
	std::vector<Vector2> goals;//緑色の点　（ゴール）の位置
	std::vector<Box*> boxes; // 押せる箱だけ

	Player* player = nullptr;

public:
	//プレイヤーを一個前のタイルに戻す関数を呼ぶ
	void PlayerGoBack();

public:
	void Update();
	void Draw();

public:
	GameManager(); 

	void SetStageData(const StageData* data);
	bool IsWall(int x, int y) const;
	bool IsBox(int x, int y) const;
	void UpdateBoxOnGoal();
	bool IsClear() const;
	Box* GetBox(int x, int y)const;
	~GameManager();
};

