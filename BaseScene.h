#pragma once

class SceneManager;

/// <summary>
/// �V�[���K��
/// </summary>
class BaseScene {
public:
	BaseScene(SceneManager*sceneManager);

	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize() =0;
	/// <summary>
	/// �I��
	/// </summary>
	virtual void Finalize()=0;
	/// <summary>
	/// ���t���[���X�V
	/// </summary>
	virtual void Update()=0;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw()=0;
protected:
	//�V�[���}�l�[�W���[�i�؂�Ă���j
	SceneManager* sceneManager = nullptr;

};

