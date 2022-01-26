#include "SceneManager.h"

SceneManager::~SceneManager() {
	//�Ō�̃V�[���̏I���ƊJ��
	scene_->Finalize();
	delete scene_;
}

void SceneManager::Update() {
	//�V�[���؂�ւ�
	if (nextScene_) {
		//���V�[���̏I��
		if (scene_) {
			scene_->Finalize();
			delete scene_;
		}
		scene_ = nextScene_;
		nextScene_ = nullptr;
		//�V�[���}�l�[�W���[�Z�b�g
		scene_->SetSceneManager(this);
		scene_->Initialize();
	}
	scene_->Update();
}

void SceneManager::Draw() {
	scene_->Draw();
}
