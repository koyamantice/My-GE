#pragma once
/// <summary>
/// 当たり判定プリミティブ
/// </summary>

#include<DirectXMath.h>
	/// <summary>
	/// 球
	/// </summary>
struct Sphere {
	//中心座標
	DirectX::XMVECTOR center = { 0,0,0,1 };
	//半径
	float radius = 1.0f;
};
/// <summary>
/// 平面
/// </summary>
struct Plane {
	//法線ベクトル
	DirectX::XMVECTOR normal = { 0,1,0,0 };
	//原点(0,0,0)からの距離
	float distance = 1.0f;
};
/// <summary>
/// 法線付き三角形（時計回りが表面）
/// </summary>
struct Triangle {
public:
	void ComputeNormal();
	//頂点座標
	DirectX::XMVECTOR p0;
	DirectX::XMVECTOR p1;
	DirectX::XMVECTOR p2;
	//法線ベクトル
	DirectX::XMVECTOR normal;
};
struct Ray 	{
	DirectX::XMVECTOR start = { 0,0,0,1 };
	DirectX::XMVECTOR dir = { 1,0,0,0 };
};
class CollisionPrimitive {
public:
	/// <summary>
	/// 当たり判定ヘルパークラス
	/// </summary>





};

