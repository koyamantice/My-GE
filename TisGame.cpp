#include "TisGame.h"

void TisGame::Initialize() {
	//基底クラスの初期化
	Framework::Initialize();
	//オブジェクト初期化
	objPin = Object3d::Create();
	// テクスチャ読み込み
	Sprite::LoadTexture(1, L"Resources/2d/backscreen.png");
	//背景スプライト生成
	sprite[0] = Sprite::Create(1, { 0.0f,0.0f });
	//スプライト生成

	// モデル読み込み
	modelPin = Model::CreateFromOBJ("Pin");
	objPin->SetModel(modelPin);
	objPin->SetScale({ 2.0f, 1.8f, 2.0f });

}

void TisGame::Finalize() {
	//３ｄのモデルのデリート


	//基底クラスの初期化
	Framework::Finalize();
}

void TisGame::Update() {
	//基底クラスの更新
	Framework::Update();
	//DirectX毎フレーム処理 ここから
	objPin->Update();
}

void TisGame::Draw() {
	dxCommon->PreDraw();

	Sprite::PreDraw(dxCommon->GetCmdList());
	//背景用
	sprite[0]->Draw();
	Sprite::PostDraw();
	dxCommon->ClearDepthBuffer();


	// 3Dオブジェクト描画前処理
	Object3d::PreDraw(dxCommon->GetCmdList());
	// 3Dオブジェクト描画後処理
	Object3d::PostDraw();

	Sprite::PreDraw(dxCommon->GetCmdList());
	//前面用
	Sprite::PostDraw();
	dxCommon->PostDraw();

}
