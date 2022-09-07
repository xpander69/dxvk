struct VS_OUTPUT {
  float4 Position : POSITION;
  float2 UV       : TEXCOORD0;
};

struct PS_OUTPUT {
  float4 Colour : COLOR;
};

sampler s_Texture : register(s0);

PS_OUTPUT main(VS_OUTPUT In) {
  PS_OUTPUT OUT;
  OUT.Colour = tex2D(s_Texture, In.UV);
  return OUT;
}