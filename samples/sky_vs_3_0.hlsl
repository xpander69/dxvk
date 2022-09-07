struct VSInput {
  float2 Position : POSITION;
};

struct VSOutput {
  float4 Position : POSITION;
};

VSOutput main(VSInput In) {
  VSOutput Out;
  Out.Position = float4(In.Position, 0.0f, 1.0f);
  return Out;
}