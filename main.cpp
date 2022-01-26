
#include"TisGame.h"



//Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
#pragma region//必須クラスの初期化
	TisGame game;
	//初期化
	game.Initialize();
	while (true)//ゲームループ
	{
		//毎フレーム更新
		game.Update();

		//終了リクエストが来たら抜ける
		if (game.IsEndRequst()) {
			break;
		}

		//描画
		game.Draw();
	}
	//ゲームの終了
	game.Finalize();

	return 0;
}