struct VSInput {
  float3 Position : POSITION;
  float2 UV       : TEXCOORD0;
  float3 Normal   : NORMAL;
};

struct VSOutput {
  float4 Position : POSITION;
};

const float4x4 c_PerspectiveMatrix : register(c0);

VSOutput main(VSInput In) {
  VSOutput Out;
  Out.Position = mul(c_PerspectiveMatrix, float4(In.Position, 1.0f));
  return Out;
}