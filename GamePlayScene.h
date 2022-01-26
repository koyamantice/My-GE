#pragma once
#include "Sprite.h"
#include "Object3d.h"

/// <summary>
/// ゲームプレイシーン
/// </summary>
class GamePlayScene {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
/// 終了
/// </summary>
	void Finalize();

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();



private:
	Model* modelPin = nullptr;
	Object3d* objPin = nullptr;
	Sprite* sprite = { nullptr };


};

