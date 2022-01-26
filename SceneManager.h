#pragma once
#include "BaseScene.h"

/// <summary>
/// �V�[���}�l�[�W���[
/// </summary>
class SceneManager {
public:
	~SceneManager();
/// <summary>
/// �X�V
/// </summary>
	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();


public:
	//���V�[���\��
	void SetNextScene(BaseScene* nextScene) { nextScene_ = nextScene; }
private:
	//���̃V�[��
	BaseScene* scene_ = nullptr;
	//���̃V�[��
	BaseScene* nextScene_ = nullptr;

};

