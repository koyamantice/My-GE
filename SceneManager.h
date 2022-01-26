#pragma once
#include "BaseScene.h"

/// <summary>
/// シーンマネージャー
/// </summary>
class SceneManager {
public:
	~SceneManager();
/// <summary>
/// 更新
/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();


public:
	//次シーン予約
	void SetNextScene(BaseScene* nextScene) { nextScene_ = nextScene; }
private:
	//今のシーン
	BaseScene* scene_ = nullptr;
	//次のシーン
	BaseScene* nextScene_ = nullptr;

};

