struct VS_OUTPUT {
  float2 Position : VPOS;
};

struct PS_OUTPUT {
  float4 Colour : COLOR;
};

static const float2 c_Resolution = float2(1280.0, 720.0);

float sqr(float x) {
  return x * x;
}

float random(float2 st) {
  return frac(sin(dot(st.xy, float2(12.9898,78.233))) * 43758.5453123);
}

float noise(float2 st) {
  float2 i = floor(st);
  float2 f = frac(st);

  float a = random(i);
  float b = random(i + float2(1.0, 0.0));
  float c = random(i + float2(0.0, 1.0));
  float d = random(i + float2(1.0, 1.0));

  float2 u = f * f * (3.0 - 2.0 * f);

  return lerp(a, b, u.x) +
          (c - a)* u.y * (1.0 - u.x) +
          (d - b) * u.x * u.y;
}

#define OCTAVES 6
float fbm(float2 st) {
    float value = 0.0f;
    float amplitude = 0.5f;
    float frequency = 0.0f;

    for (int i = 0; i < OCTAVES; i++) {
        value += amplitude * noise(st);
        st *= 2.;
        amplitude *= .5;
    }
    return value;
}

PS_OUTPUT main(VS_OUTPUT In) {
  PS_OUTPUT Out;

  const float2 uv   = In.Position / c_Resolution.xy;
  const float2 uv_x = In.Position / c_Resolution.xx;
  const float2 uv_y = In.Position / c_Resolution.yy;
  const float aspect = c_Resolution.x / c_Resolution.y;

  float3 color = float3(0.1f, 0.1f, 0.1f);

  const float moonSize = 0.35f;
  const float3 moonColor = float3(0.9f, 0.9f, 0.9f);
  float moonLen = length(uv_y - float2(0.5 * aspect, 0.7));
  if (moonLen < moonSize)
    color = moonColor * 1.1f;
  else
    color += saturate(sqr(1.0f - saturate((moonLen - moonSize)))) * moonColor * 0.3f;

  color *= fbm(uv_y * 3.0f) * float3(0.54, 0.64, 0.65) * 2.0f;

  Out.Colour = float4(color, 1.0f);
  return Out;
}
