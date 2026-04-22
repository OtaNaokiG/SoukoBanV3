#pragma once
#include "SceneBase.h"

class SceneManager
{
private:
	SceneBase* main_scene = nullptr;
	/// <summary>
	/// stageManagerをSceneManagerだけに持たせて　⇒　他のステージシーンにアドレスを渡す
	/// </summary>
	StageManager stageManager; // ← ここに1つだけ

public:
	SceneManager();
	~SceneManager();
	void Update();
	void Draw();
};

