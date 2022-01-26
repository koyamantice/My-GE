#include "TisGame.h"
#include "GamePlayScene.h"
#include "TitleScene.h"

void TisGame::Initialize() {
	//基底クラスの初期化
	Framework::Initialize();
	BaseScene* scene = new TitleScene();
	sceneManager_->SetNextScene(scene);
}

void TisGame::Finalize() {

	//基底クラスの初期化
	Framework::Finalize();
}

void TisGame::Update() {
	//基底クラスの更新
	Framework::Update();
	//DirectX毎フレーム処理 ここから

}

void TisGame::Draw() {
	//基底クラスの更新
	Framework::Draw();

}
