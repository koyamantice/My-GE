#include "Framework.h"

void Framework::Run() {
	//������
	Initialize();
	while (true)//�Q�[�����[�v
	{
		//���t���[���X�V
		Update();

		//�I�����N�G�X�g�������甲����
		if (IsEndRequst()) {
			break;
		}

		//�`��
		Draw();
	}
	//�Q�[���̏I��
	Finalize();

}

void Framework::Initialize() {
	winApp = new WinApp();
	winApp->Initialize();
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);
	// ���͂̏�����
	input = Input::GetInstance();
	input->Initialize(winApp);

	audio = Audio::GetInstance();
	audio->Initialize();	
	
	
	//�X�v���C�g�֌W
	// �X�v���C�g�ÓI������
	Sprite::StaticInitialize(dxCommon->GetDev(), dxCommon->GetCmdList(),WinApp::window_width, WinApp::window_height);

	const int debugTextTexNumber = 0;
	// �f�o�b�O�e�L�X�g�p�e�N�X�`���ǂݍ���
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/2d/debugfont.png")) {
		assert(0);
		return;
	}
	// �f�o�b�O�e�L�X�g������
	debugText = DebugText::GetInstance();
	debugText->Initialize(debugTextTexNumber);



	Object3d::StaticInitialize(dxCommon->GetDev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);
	// �}�E�X�J�[�\���̔�\��
	ShowCursor(TRUE);


}

void Framework::Finalize() {
	delete dxCommon;
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
