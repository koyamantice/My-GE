#pragma once
#include"CollisionTypes.h"
#include"Object3d.h"
#include "CollisionInfo.h"


class BaseCollider {
public:
	BaseCollider() = default;


	inline void SetObject(Object3d* object) {
		this->object3d = object;
	}

	inline Object3d* GetObject3d() {
		return object3d;
	}
	///<summary>
	///�Փˎ��R�[���o�b�N�֐�
	/// </summary>
	/// <param name="info">�Փˏ��</param>
	inline void OnCollision(const CollisionInfo& info) {
		object3d->OnCollision(info);
	}
	///<summary>
	///�X�V
	///</summary>
	virtual void Update() = 0;
	//�`��^�C�v�擾
	inline CollisionShapeType GetShapeType() { return shapeType; }
protected:
	Object3d* object3d = nullptr;
	CollisionShapeType shapeType = SHAPE_UNKNOWN;

};

