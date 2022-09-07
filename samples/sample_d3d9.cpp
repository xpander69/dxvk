#include "sample_common.h"
#include "sample_data_frog.h"

#include "../src/util/util_matrix.h"

#include <d3d9.h>
#include <d3dcompiler.h>

#include <iostream>
#include <array>

namespace sample {

  using namespace dxvk;

#if 0
  Matrix4 perspective(const Radian& fovy, float aspect, float zNear, float zFar) {
    const float tanHalfFovy = tan(0.5f * fovy);

    Matrix4 result{0.0f};

    result[0][0] = 1.0f / (aspect * tanHalfFovy);
    result[1][1] = 1.0f / (tanHalfFovy);
    result[2][2] = -(zFar + zNear) / (zFar - zNear);
    result[2][3] = -1.0f;
    result[3][2] = -2.0f * zFar * zNear / (zFar - zNear);

    return result;
  }
#endif

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

      constexpr std::array<D3DVERTEXELEMENT9, 4> elements = {{
        { .Offset = offsetof(StaticVertex, pos),    .Type = D3DDECLTYPE_FLOAT3, .Usage = D3DDECLUSAGE_POSITION },
        { .Offset = offsetof(StaticVertex, uv),     .Type = D3DDECLTYPE_FLOAT2, .Usage = D3DDECLUSAGE_TEXCOORD },
        { .Offset = offsetof(StaticVertex, normal), .Type = D3DDECLTYPE_FLOAT3, .Usage = D3DDECLUSAGE_NORMAL   },
        D3DDECL_END(),
      }};
      m_device->CreateVertexDeclaration(elements.data(), &m_frogDecl);
      if (FAILED(hr)) return false;

      hr = m_device->CreateVertexShader(reinterpret_cast<const DWORD*>(blob->GetBufferPointer()), &m_frogVs);
      if (FAILED(hr)) return false;

      hr = m_device->CreatePixelShader(reinterpret_cast<const DWORD*>(blob->GetBufferPointer()), &m_frogPs);
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

      m_device->SetStreamSource(0, m_frogVb.ptr(), 0, sizeof(StaticVertex));
      m_device->SetVertexDeclaration(m_frogDecl.ptr());
      m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 0, 0, sizeof(FrogIndices) / sizeof(FrogIndices[0]) / 3 );

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

    Com<IDirect3DVertexDeclaration9> m_frogDecl;
    Com<IDirect3DVertexBuffer9>      m_frogVb;
    Com<IDirect3DIndexBuffer9>       m_frogIb;
    Com<IDirect3DVertexShader9>      m_frogVs;
    Com<IDirect3DPixelShader9>       m_frogPs;

    Extent2D m_windowSize = { 1280, 720 };

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
