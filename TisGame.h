#pragma once
#include "DirectXCommon.h"
#include "WinApp.h"
#include "Input.h"
#include "Sprite.h"
#include "DebugText.h"
#include "CollisionPrimitive.h"
#include "Collision.h"
#include "Object3d.h"
#include "Audio.h"


class TisGame {
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
	bool IsEndRequst() { return endResquest_; }
private:
	bool endResquest_ = false;
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;

	Input* input = nullptr;
	Audio* audio=nullptr;
	DebugText* debugText=nullptr;


	Model* modelPin = nullptr;
	Object3d* objPin = nullptr;

	Sprite* sprite[10] = { nullptr };


};

