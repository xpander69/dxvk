#include "sample_common.h"
#include "sample_data_frog.h"

#include "../src/util/util_matrix.h"
#include "../src/util/util_time.h"

#include "sky_vs_3_0.h"
#include "sky_ps_3_0.h"

#include "frog_vs_3_0.h"
#include "frog_ps_3_0.h"

#include <d3d9.h>
#include <d3dcompiler.h>

#include <iostream>
#include <array>

namespace sample {

  using namespace dxvk;

  static float degToRad(float deg) { return deg * (M_PI / 180.0f); }

  static Matrix4 perspective(float fovY, float aspect, float zNear, float zFar) {
    const float tanHalfFovy = tan(0.5f * fovY);

    Matrix4 result{0.0f};

    result[0][0] = 1.0f / (aspect * tanHalfFovy);
    result[1][1] = 1.0f / (tanHalfFovy);
    result[2][2] = -(zFar + zNear) / (zFar - zNear);
    result[2][3] = -1.0f;
    result[3][2] = -2.0f * zFar * zNear / (zFar - zNear);

    return result;
  }

  Matrix4 translate(const Vector4& v) {
	Matrix4 result;
	result[3] = v;
	return result;
  }

  Matrix4 rotate(float angle, const Vector4& v) {
      const float c = cosf(angle);
      const float s = sinf(angle);

      const Vector4 axis = normalize(Vector4(v.x, v.y, v.z, 0.0f));
      const Vector4 t = (1.0f - c) * axis;

      Matrix4 rot;
      rot[0][0] = c + t[0] * axis[0];
      rot[0][1] = 0 + t[0] * axis[1] + s * axis[2];
      rot[0][2] = 0 + t[0] * axis[2] - s * axis[1];
      rot[0][3] = 0;

      rot[1][0] = 0 + t[1] * axis[0] - s * axis[2];
      rot[1][1] = c + t[1] * axis[1];
      rot[1][2] = 0 + t[1] * axis[2] + s * axis[0];
      rot[1][3] = 0;

      rot[2][0] = 0 + t[2] * axis[0] + s * axis[1];
      rot[2][1] = 0 + t[2] * axis[1] - s * axis[0];
      rot[2][2] = c + t[2] * axis[2];
      rot[2][3] = 0;

      return rot;
  }

  struct SkyVertex {
    float pos[2];
  };

  static const SkyVertex SkyVertices[] = {
    { -1.0f,  3.0f },
    {  3.0f, -1.0f },
    { -1.0f, -1.0f },
  };

  class D3D9Sample final : public ISampleApp {
  public:
    bool init(HWND window) override {
      m_window = window;

      HRESULT hr = Direct3DCreate9Ex(D3D_SDK_VERSION, &m_d3d);
      if (FAILED(hr)) return false;

      D3DADAPTER_IDENTIFIER9 adapterId;
      UINT adapter = D3DADAPTER_DEFAULT;
      m_d3d->GetAdapterIdentifier(adapter, 0, &adapterId);

      std::cout << "Using adapter: " << adapterId.Description << std::endl;

      D3DPRESENT_PARAMETERS params = presentParams();
      hr = m_d3d->CreateDeviceEx(
        adapter, D3DDEVTYPE_HAL,
        m_window,
        D3DCREATE_HARDWARE_VERTEXPROCESSING,
        &params, nullptr,
        &m_device);
      if (FAILED(hr)) return false;


      hr = m_device->CreateVertexBuffer(sizeof(FrogVertices), D3DUSAGE_WRITEONLY, 0, D3DPOOL_DEFAULT, &m_frogVb, nullptr);
      if (FAILED(hr)) return false;
      {
        void* data = nullptr;
        m_frogVb->Lock(0, 0, &data, 0);
        memcpy(data, FrogVertices, sizeof(FrogVertices));
        m_frogVb->Unlock();
      }
      
      hr = m_device->CreateIndexBuffer(sizeof(FrogIndices), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &m_frogIb, nullptr);
      if (FAILED(hr)) return false;
      {
        void* data = nullptr;
        m_frogIb->Lock(0, 0, &data, 0);
        memcpy(data, FrogIndices, sizeof(FrogIndices));
        m_frogIb->Unlock();
      }

      constexpr std::array<D3DVERTEXELEMENT9, 4> frogElements = {{
        { 0, offsetof(StaticVertex, pos),     D3DDECLTYPE_FLOAT3, 0, D3DDECLUSAGE_POSITION, 0 },
        { 0, offsetof(StaticVertex, uv),      D3DDECLTYPE_FLOAT2, 0, D3DDECLUSAGE_TEXCOORD, 0 },
        { 0, offsetof(StaticVertex, normal),  D3DDECLTYPE_FLOAT3, 0, D3DDECLUSAGE_NORMAL,   0 },
        D3DDECL_END(),
      }};
      m_device->CreateVertexDeclaration(frogElements.data(), &m_frogDecl);
      if (FAILED(hr)) return false;

      hr = m_device->CreateVertexShader(reinterpret_cast<const DWORD *>(frog_vs_3_0), &m_frogVs);
      if (FAILED(hr)) return false;
      
      hr = m_device->CreatePixelShader(reinterpret_cast<const DWORD *>(frog_ps_3_0), &m_frogPs);
      if (FAILED(hr)) return false;


      hr = m_device->CreateVertexBuffer(sizeof(SkyVertices), D3DUSAGE_WRITEONLY, 0, D3DPOOL_DEFAULT, &m_skyVb, nullptr);
      if (FAILED(hr)) return false;
      {
        void* data = nullptr;
        m_skyVb->Lock(0, 0, &data, 0);
        memcpy(data, SkyVertices, sizeof(SkyVertices));
        m_skyVb->Unlock();
      }

      constexpr std::array<D3DVERTEXELEMENT9, 2> skyElements = {{
        { 0, 0, D3DDECLTYPE_FLOAT2, 0, D3DDECLUSAGE_POSITION, 0 },
        D3DDECL_END(),
      }};
      m_device->CreateVertexDeclaration(skyElements.data(), &m_skyDecl);
      if (FAILED(hr)) return false;

      hr = m_device->CreateVertexShader(reinterpret_cast<const DWORD *>(sky_vs_3_0), &m_skyVs);
      if (FAILED(hr)) return false;
      
      hr = m_device->CreatePixelShader(reinterpret_cast<const DWORD *>(sky_ps_3_0), &m_skyPs);
      if (FAILED(hr)) return false;

      return true;
    }
    
    bool frame() override {
      m_device->BeginScene();

      m_device->Clear(
        0,
        nullptr,
        D3DCLEAR_ZBUFFER,
        0, 1.0f,
        0);

      auto t0 = m_lastTime;
      m_lastTime = dxvk::high_resolution_clock::now();
      float time = std::chrono::duration_cast<std::chrono::duration<float>>(m_lastTime - m_startTime).count();

      // Sky
      {
        m_device->SetRenderState(D3DRS_ZENABLE, 0);
        m_device->SetRenderState(D3DRS_ZWRITEENABLE, 0);
        m_device->SetStreamSource(0, m_skyVb.ptr(), 0, sizeof(SkyVertex));
        m_device->SetIndices(nullptr);
        m_device->SetVertexDeclaration(m_skyDecl.ptr());
        m_device->SetVertexShader(m_skyVs.ptr());
        m_device->SetPixelShader(m_skyPs.ptr());
        m_device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
      }

      // Frog
      {
        Matrix4 matrix =
            perspective(degToRad(60.0f), m_windowSize.w / float(m_windowSize.h), 0.1f, 1024.0f)
          * translate(Vector4(20.0f, -20.0f, -60.0f, 1.0f))
          * rotate(degToRad(180.0f), Vector4(0.0f, 0.0f, 1.0f, 0.0f))
          * rotate(degToRad(time * 20.0f), Vector4(0.0f, 1.0f, 0.0f, 0.0f));

        m_device->SetVertexShaderConstantF(0, matrix.data[0].data, 4);

        m_device->SetRenderState(D3DRS_ZENABLE, 1);
        m_device->SetRenderState(D3DRS_ZWRITEENABLE, 1);
        m_device->SetStreamSource(0, m_frogVb.ptr(), 0, sizeof(StaticVertex));
        m_device->SetIndices(m_frogIb.ptr());
        m_device->SetVertexDeclaration(m_frogDecl.ptr());
        m_device->SetVertexShader(m_frogVs.ptr());
        m_device->SetPixelShader(m_frogPs.ptr());
        m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 0, 0, sizeof(FrogIndices) / sizeof(FrogIndices[0]) / 3);
      }

      m_device->EndScene();

      m_device->PresentEx(
        nullptr, nullptr,
        nullptr, nullptr,
        0);

      return true;
    }

    const char* title()         override { return "DXVK D3D9 Sample"; }
    int         defaultWidth()  override { return 1280; }
    int         defaultHeight() override { return 720; }

  private:
    HWND m_window = nullptr;

    Com<IDirect3D9Ex>           m_d3d;
    Com<IDirect3DDevice9Ex>     m_device;

    Com<IDirect3DVertexDeclaration9> m_skyDecl;
    Com<IDirect3DVertexBuffer9>      m_skyVb;
    Com<IDirect3DVertexShader9>      m_skyVs;
    Com<IDirect3DPixelShader9>       m_skyPs;

    Com<IDirect3DVertexDeclaration9> m_frogDecl;
    Com<IDirect3DVertexBuffer9>      m_frogVb;
    Com<IDirect3DIndexBuffer9>       m_frogIb;
    Com<IDirect3DVertexShader9>      m_frogVs;
    Com<IDirect3DPixelShader9>       m_frogPs;

    Extent2D m_windowSize = { 1280, 720 };

    dxvk::high_resolution_clock::time_point m_startTime =
      dxvk::high_resolution_clock::now();

    dxvk::high_resolution_clock::time_point m_lastTime =
      dxvk::high_resolution_clock::now();

    D3DPRESENT_PARAMETERS presentParams() const {
      D3DPRESENT_PARAMETERS params = {};
      params.AutoDepthStencilFormat     = D3DFMT_UNKNOWN;
      params.BackBufferCount            = 1;
      params.BackBufferFormat           = D3DFMT_X8R8G8B8;
      params.BackBufferWidth            = m_windowSize.w;
      params.BackBufferHeight           = m_windowSize.h;
      params.EnableAutoDepthStencil     = 0;
      params.Flags                      = 0;
      params.FullScreen_RefreshRateInHz = 0;
      params.hDeviceWindow              = m_window;
      params.MultiSampleQuality         = 0;
      params.MultiSampleType            = D3DMULTISAMPLE_NONE;
      params.PresentationInterval       = D3DPRESENT_INTERVAL_DEFAULT;
      params.SwapEffect                 = D3DSWAPEFFECT_DISCARD;
      params.Windowed                   = TRUE;
      return params;
    }

  };

  std::unique_ptr<ISampleApp> ISampleApp::create() {
    return std::make_unique<D3D9Sample>();
  }

}
