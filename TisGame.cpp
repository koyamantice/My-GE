#include "TisGame.h"
#include "GamePlayScene.h"

void TisGame::Initialize() {
	//基底クラスの初期化
	Framework::Initialize();
	scene_ = new GamePlayScene();
	scene_->Initialize();
}

void TisGame::Finalize() {

	scene_->Finalize();
	//基底クラスの初期化
	Framework::Finalize();
}

void TisGame::Update() {
	//基底クラスの更新
	Framework::Update();
	//DirectX毎フレーム処理 ここから
	scene_->Update();

}

void TisGame::Draw() {
	dxCommon->PreDraw();

	scene_->Draw();

	debugText->DrawAll();
	dxCommon->PostDraw();

}
