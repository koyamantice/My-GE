#include"Basic.hlsli"

Texture2D<float4> tex : register(t0);
SamplerState smp : register(s0);

float4 main(VSOutput input) : SV_TARGET{
	float3 light = normalize(float3(1,-1,1));//�E����
	float diffuse = saturate(dot(-light, input.normal));//diffuse��[0,1]�͈̔͂�Clamp����
	float brightness = diffuse+1.0f;//�����ւ̃x�N�g���Ɩ@���x�N�g���̓���
	float4 texcolor = float4(tex.Sample(smp, input.uv));
	return float4(texcolor.rgb * brightness, texcolor.a) * color;
	//return float4(brightness,brightness,brightness,1);//�P�x��RGB�ɑ�����ďo��
}


//float4 main(VSOutput input) :SV_TARGET
//{
//	return float4(input.uv,1,1);
//	//return float4(tex.Sample(smp,input.uv));
//}
//cbuffer cbuff0:register(b0)
//{
//	float4 color;//�F
//}
//
//float4 main() : SV_TARGET
//{
//	return color;
//}