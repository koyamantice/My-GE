#pragma once
/// <summary>
/// �����蔻��v���~�e�B�u
/// </summary>

#include<DirectXMath.h>
	/// <summary>
	/// ��
	/// </summary>
struct Sphere {
	//���S���W
	DirectX::XMVECTOR center = { 0,0,0,1 };
	//���a
	float radius = 1.0f;
};
/// <summary>
/// ����
/// </summary>
struct Plane {
	//�@���x�N�g��
	DirectX::XMVECTOR normal = { 0,1,0,0 };
	//���_(0,0,0)����̋���
	float distance = 1.0f;
};
/// <summary>
/// �@���t���O�p�`�i���v��肪�\�ʁj
/// </summary>
struct Triangle {
public:
	void ComputeNormal();
	//���_���W
	DirectX::XMVECTOR p0;
	DirectX::XMVECTOR p1;
	DirectX::XMVECTOR p2;
	//�@���x�N�g��
	DirectX::XMVECTOR normal;
};
struct Ray 	{
	DirectX::XMVECTOR start = { 0,0,0,1 };
	DirectX::XMVECTOR dir = { 1,0,0,0 };
};
class CollisionPrimitive {
public:
	/// <summary>
	/// �����蔻��w���p�[�N���X
	/// </summary>





};

