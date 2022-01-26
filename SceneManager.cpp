#include "SceneManager.h"

SceneManager::~SceneManager() {
	//最後のシーンの終了と開放
	scene_->Finalize();
	delete scene_;
}

void SceneManager::Update() {
	//シーン切り替え
	if (nextScene_) {
		//旧シーンの終了
		if (scene_) {
			scene_->Finalize();
			delete scene_;
		}
		scene_ = nextScene_;
		nextScene_ = nullptr;

		scene_->Initialize();
	}
	scene_->Update();
}

void SceneManager::Draw() {
	scene_->Draw();
}
