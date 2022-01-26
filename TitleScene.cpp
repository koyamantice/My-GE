#include "TitleScene.h"
#include"SceneManager.h"

#include "Audio.h"
#include "input.h"
#include "DebugText.h"
#include"GamePlayScene.h"

void TitleScene::Initialize() {
	// �e�N�X�`���ǂݍ���
	Sprite::LoadTexture(1, L"Resources/2d/title.png");

	//�w�i�X�v���C�g����
	sprite = Sprite::Create(1, { 0.0f,0.0f });
	//�X�v���C�g����


}

void TitleScene::Finalize() {
	//�R���̃��f���̃f���[�g
	delete sprite;
}

void TitleScene::Update() {
	Input* input = Input::GetInstance();
	if (input->PushKey(DIK_RETURN)) {
		BaseScene* scene = new GamePlayScene();
		sceneManager_->SetNextScene(scene);
	}
	DebugText::GetInstance()->Print("Oh!MyGod!!", 200, 100, 1.0f);
}

void TitleScene::Draw() {
	sprite->PreDraw();
	//�w�i�p
	sprite->Draw();

	//�O�ʗp

}

