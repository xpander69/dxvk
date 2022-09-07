struct VSInput {
  float3 Position : POSITION;
  float2 UV       : TEXCOORD0;
  float3 Normal   : NORMAL;
};
struct VSOutput {
  float4 Position : POSITION;
};

VSOutput main(VSInput In) {
  VSOutput OUT;
  OUT.Position = float4(In.Position, 1.0f);
  return OUT;
}