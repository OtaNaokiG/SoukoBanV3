#include "SceneManager.h"

#include "SceneTitle.h"

SceneManager::SceneManager() {
	main_scene = new SceneTitle;
	main_scene->Init(&stageManager);
}

SceneManager::~SceneManager() {
	delete main_scene;

}

void SceneManager::Update()
{
	SceneBase* nextScene = main_scene->Update();//シーンの更新
	if (nextScene != nullptr) { // nullptr以外が返ってきたら → 次のシーンへの遷移要求
		delete main_scene; // 古いシーンを破棄 
		main_scene = nextScene; // 新しいシーンに切り替え
		main_scene->Init(&stageManager); // 初期化 
	}
}

void SceneManager::Draw()
{
	if (main_scene != nullptr)
	{
		main_scene->Draw();
	}
}