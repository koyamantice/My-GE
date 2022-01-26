#include "TisGame.h"

void TisGame::Initialize() {
	winApp = new WinApp();
	winApp->Initialize();
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);
	// 入力の初期化
	input = new Input();
	if (!input->Initialize(winApp)) {
		assert(0);
		return ;
	}//スプライト関係
	// スプライト静的初期化
	Sprite::StaticInitialize(dxCommon->GetDev(), WinApp::window_width, WinApp::window_height);

	const int debugTextTexNumber = 0;
	// デバッグテキスト用テクスチャ読み込み
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/2d/debugfont.png")) {
		assert(0);
		return ;
	}
	// デバッグテキスト初期化
	debugText = DebugText::GetInstance();
	debugText->Initialize(debugTextTexNumber);



	Object3d::StaticInitialize(dxCommon->GetDev(), WinApp::window_width, WinApp::window_height);
	objPin = Object3d::Create();

	// マウスカーソルの非表示
	ShowCursor(TRUE);

#pragma endregion
#pragma region//ゲームクラスの初期化
	// テクスチャ読み込み
	Sprite::LoadTexture(1, L"Resources/2d/backscreen.png");
	//背景スプライト生成
	sprite[0] = Sprite::Create(1, { 0.0f,0.0f });
	//スプライト生成

	// モデル読み込み
	modelPin = Model::CreateFromOBJ("Pin");
	objPin->SetModel(modelPin);
	objPin->SetScale({ 2.0f, 1.8f, 2.0f });

#pragma endregion

}

void TisGame::Finalize() {
	//ウィンドウ表示
	ShowWindow(winApp->GetHwnd(), SW_SHOW);
	winApp->Finalize();
	delete input;
	delete dxCommon;
	delete winApp;

}

void TisGame::Update() {
	//DirectX毎フレーム処理 ここから
	input->Update(winApp);
	objPin->Update();
	if (winApp->ProcessMessage() || input->TriggerKey(DIK_ESCAPE)) {
		endResquest_ = true;
		return;
	}
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
