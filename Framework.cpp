#include "Framework.h"

void Framework::Run() {
	//初期化
	Initialize();
	while (true)//ゲームループ
	{
		//毎フレーム更新
		Update();

		//終了リクエストが来たら抜ける
		if (IsEndRequst()) {
			break;
		}

		//描画
		Draw();
	}
	//ゲームの終了
	Finalize();

}

void Framework::Initialize() {
	winApp = new WinApp();
	winApp->Initialize();
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);
	// 入力の初期化
	input = new Input();
	if (!input->Initialize(winApp)) {
		assert(0);
		return;
	}//スプライト関係
	// スプライト静的初期化
	Sprite::StaticInitialize(dxCommon->GetDev(), WinApp::window_width, WinApp::window_height);

	const int debugTextTexNumber = 0;
	// デバッグテキスト用テクスチャ読み込み
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/2d/debugfont.png")) {
		assert(0);
		return;
	}
	// デバッグテキスト初期化
	debugText = DebugText::GetInstance();
	debugText->Initialize(debugTextTexNumber);



	Object3d::StaticInitialize(dxCommon->GetDev(), WinApp::window_width, WinApp::window_height);
	// マウスカーソルの非表示
	ShowCursor(TRUE);


}

void Framework::Finalize() {
	delete audio;
	delete dxCommon;
	delete input;
	winApp->Finalize();
	delete winApp;

}

void Framework::Update() {
	input->Update(winApp);
	if (winApp->ProcessMessage() || input->TriggerKey(DIK_ESCAPE)) {
		endResquest_ = true;
		return;
	}
}

void Framework::Draw() {

}
