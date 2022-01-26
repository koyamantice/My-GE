#include "GamePlayScene.h"
#include "Audio.h"
#include "input.h"
#include "DebugText.h"

void GamePlayScene::Initialize() {
	//オブジェクト初期化
	objPin = Object3d::Create();
	// テクスチャ読み込み
	Sprite::LoadTexture(1, L"Resources/2d/title.png");
	Sprite::LoadTexture(2, L"Resources/2d/gameplay.png");

	//背景スプライト生成
	sprite = Sprite::Create(2, { 0.0f,0.0f });
	//スプライト生成

	// モデル読み込み
	modelPin = Model::CreateFromOBJ("Pin");
	objPin->SetModel(modelPin);
	objPin->SetScale({ 2.0f, 1.8f, 2.0f });

}

void GamePlayScene::Finalize() {
	//３ｄのモデルのデリート

}

void GamePlayScene::Update() {
	Input* input = Input::GetInstance();
	objPin->Update();
	if (input->PushMouseLeft()) {
		objPin->SetScale({ 2.0f, 1.8f, 2.0f });
	}
	DebugText::GetInstance()->Print("Oh!MyGod!!",200, 100,1.0f);
}

void GamePlayScene::Draw() {
	sprite->PreDraw();
	//背景用
	sprite->Draw();


	Object3d::PreDraw();
	//背景用
	objPin->Draw();




	//前面用

}

