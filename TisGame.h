#pragma once
#include "CollisionPrimitive.h"
#include "Collision.h"
#include "Framework.h"
#include <vector>

class TisGame:public Framework {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;
	/// <summary>
	/// 終了
	/// </summary>
	void Finalize() override;
	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update() override;
	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;
private:


	Model* modelPin = nullptr;
	Object3d* objPin = nullptr;
	Sprite* sprite[10] = { nullptr };
};

