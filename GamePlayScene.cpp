#include "GamePlayScene.h"
#include "Audio.h"
#include "input.h"
#include "DebugText.h"

void GamePlayScene::Initialize() {
	//�I�u�W�F�N�g������
	objPin = Object3d::Create();
	// �e�N�X�`���ǂݍ���
	Sprite::LoadTexture(1, L"Resources/2d/title.png");
	Sprite::LoadTexture(2, L"Resources/2d/gameplay.png");

	//�w�i�X�v���C�g����
	sprite = Sprite::Create(2, { 0.0f,0.0f });
	//�X�v���C�g����

	// ���f���ǂݍ���
	modelPin = Model::CreateFromOBJ("Pin");
	objPin->SetModel(modelPin);
	objPin->SetScale({ 2.0f, 1.8f, 2.0f });

}

void GamePlayScene::Finalize() {
	//�R���̃��f���̃f���[�g

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
	//�w�i�p
	sprite->Draw();


	Object3d::PreDraw();
	//�w�i�p
	objPin->Draw();




	//�O�ʗp

}

