#pragma once
#include "StageManager.h"
class SceneBase {
public:
	//virtual がないと SceneBase の関数が呼ばれてしまう。
	/// <summary>
	///= 0 を付けると、その関数は[ 純粋仮想関数 ]になる 
	/// これは「派生クラスで必ず実装しろ」という意味。
	/// ★純粋仮想関数を持つクラスは 抽象クラス になり、インスタンス化できなくなる。
	/// </summary>

	/// <summary>
	///シーンを動的に切り替えるため
	/// ポリモーフィズムを使うため
	/// ,ポリモーフィズム（多態性）とは？同じ型（SceneBase）で、実際には違うクラスを動かせる仕組み」*
	/// </summary>
	virtual void Init(StageManager* stageManager) = 0;
	virtual SceneBase* Update() = 0;// 次のシーンを返す（切り替えなしなら nullptr）
	virtual void Draw() = 0;
};