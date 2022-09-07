struct VS_OUTPUT {
  float4 Position : POSITION;
};

struct PS_OUTPUT {
  float4 Colour   : COLOR;
};
sampler g_texDepth : register( s0 );
PS_OUTPUT main( VS_OUTPUT IN ) {
  PS_OUTPUT OUT;
  OUT.Colour = tex2D(g_texDepth, float2(0, 0));
  OUT.Colour = 1.0;
  return OUT;
}