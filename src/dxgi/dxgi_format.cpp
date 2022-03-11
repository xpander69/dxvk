#include "dxgi_format.h"

#include <array>

namespace dxvk {
  
  const std::array<DXGI_VK_FORMAT_MAPPING, 133> g_dxgiFormats = {{
    // DXGI_FORMAT_UNKNOWN
    { },
    // DXGI_FORMAT_R32G32B32A32_TYPELESS
    { DxvkFormat::RGBA32ui,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA32ui },
    // DXGI_FORMAT_R32G32B32A32_FLOAT
    { DxvkFormat::RGBA32sf,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32A32_UINT
    { DxvkFormat::RGBA32ui,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32A32_SINT
    { DxvkFormat::RGBA32si,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32_TYPELESS
    { DxvkFormat::RGB32ui,
      DxvkFormat::Unknown,
      DxvkFormat::RGB32ui },
    // DXGI_FORMAT_R32G32B32_FLOAT
    { DxvkFormat::RGB32sf,
      DxvkFormat::Unknown,
      DxvkFormat::RGB32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32_UINT
    { DxvkFormat::RGB32ui,
      DxvkFormat::Unknown,
      DxvkFormat::RGB32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32B32_SINT
    { DxvkFormat::RGB32si,
      DxvkFormat::Unknown,
      DxvkFormat::RGB32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_TYPELESS
    { DxvkFormat::RGBA16un,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA16ui },
    // DXGI_FORMAT_R16G16B16A16_FLOAT
    { DxvkFormat::RGBA16sf,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_UNORM
    { DxvkFormat::RGBA16un,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_UINT
    { DxvkFormat::RGBA16ui,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_SNORM
    { DxvkFormat::RGBA16sn,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16B16A16_SINT
    { DxvkFormat::RGBA16si,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32_TYPELESS
    { DxvkFormat::RG32ui,
      DxvkFormat::Unknown,
      DxvkFormat::RG32ui },
    // DXGI_FORMAT_R32G32_FLOAT
    { DxvkFormat::RG32sf,
      DxvkFormat::Unknown,
      DxvkFormat::RG32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32_UINT
    { DxvkFormat::RG32ui,
      DxvkFormat::Unknown,
      DxvkFormat::RG32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G32_SINT
    { DxvkFormat::RG32si,
      DxvkFormat::Unknown,
      DxvkFormat::RG32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32G8X24_TYPELESS
    { DxvkFormat::Unknown,
      DxvkFormat::D32S8,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_D32_FLOAT_S8X24_UINT
    { DxvkFormat::Unknown,
      DxvkFormat::D32S8,
      DxvkFormat::Unknown,
      0, VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT },
    // DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS
    { DxvkFormat::Unknown,
      DxvkFormat::D32S8,
      DxvkFormat::Unknown,
      0, VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_X32_TYPELESS_G8X24_UINT
    { DxvkFormat::Unknown,
      DxvkFormat::D32S8,
      DxvkFormat::Unknown,
      0, VK_IMAGE_ASPECT_STENCIL_BIT },
    // DXGI_FORMAT_R10G10B10A2_TYPELESS
    { DxvkFormat::RGB10A2un,
      DxvkFormat::Unknown,
      DxvkFormat::RGB10A2ui },
    // DXGI_FORMAT_R10G10B10A2_UNORM
    { DxvkFormat::RGB10A2un,
      DxvkFormat::Unknown,
      DxvkFormat::RGB10A2ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R10G10B10A2_UINT
    { DxvkFormat::RGB10A2ui,
      DxvkFormat::Unknown,
      DxvkFormat::RGB10A2ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R11G11B10_FLOAT
    { DxvkFormat::RGB11uf,
      DxvkFormat::Unknown,
      DxvkFormat::R32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_TYPELESS
    { DxvkFormat::RGBA8un,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA8ui },
    // DXGI_FORMAT_R8G8B8A8_UNORM
    { DxvkFormat::RGBA8un,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
    { DxvkFormat::RGBA8srgb,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_UINT
    { DxvkFormat::RGBA8ui,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_SNORM
    { DxvkFormat::RGBA8sn,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8B8A8_SINT
    { DxvkFormat::RGBA8si,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_TYPELESS
    { DxvkFormat::RG16un,
      DxvkFormat::Unknown,
      DxvkFormat::RG16ui },
    // DXGI_FORMAT_R16G16_FLOAT
    { DxvkFormat::RG16sf,
      DxvkFormat::Unknown,
      DxvkFormat::RG16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_UNORM
    { DxvkFormat::RG16un,
      DxvkFormat::Unknown,
      DxvkFormat::RG16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_UINT
    { DxvkFormat::RG16ui,
      DxvkFormat::Unknown,
      DxvkFormat::RG16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_SNORM
    { DxvkFormat::RG16sn,
      DxvkFormat::Unknown,
      DxvkFormat::RG16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16G16_SINT
    { DxvkFormat::RG16si,
      DxvkFormat::Unknown,
      DxvkFormat::RG16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32_TYPELESS
    { DxvkFormat::R32ui,
      DxvkFormat::D32,
      DxvkFormat::R32ui },
    // DXGI_FORMAT_D32_FLOAT
    { DxvkFormat::Unknown,
      DxvkFormat::D32,
      DxvkFormat::Unknown,
      0, VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_R32_FLOAT
    { DxvkFormat::R32sf,
      DxvkFormat::D32,
      DxvkFormat::R32ui,
      VK_IMAGE_ASPECT_COLOR_BIT,
      VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_R32_UINT
    { DxvkFormat::R32ui,
      DxvkFormat::Unknown,
      DxvkFormat::R32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R32_SINT
    { DxvkFormat::R32si,
      DxvkFormat::Unknown,
      DxvkFormat::R32ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R24G8_TYPELESS
    { DxvkFormat::Unknown,
      DxvkFormat::D24S8,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_D24_UNORM_S8_UINT
    { DxvkFormat::Unknown,
      DxvkFormat::D24S8,
      DxvkFormat::Unknown,
      0, VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT },
    // DXGI_FORMAT_R24_UNORM_X8_TYPELESS
    { DxvkFormat::Unknown,
      DxvkFormat::D24S8,
      DxvkFormat::Unknown,
      0, VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_X24_TYPELESS_G8_UINT
    { DxvkFormat::Unknown,
      DxvkFormat::D24S8,
      DxvkFormat::Unknown,
      0, VK_IMAGE_ASPECT_STENCIL_BIT },
    // DXGI_FORMAT_R8G8_TYPELESS
    { DxvkFormat::RG8un,
      DxvkFormat::Unknown,
      DxvkFormat::RG8ui },
    // DXGI_FORMAT_R8G8_UNORM
    { DxvkFormat::RG8un,
      DxvkFormat::Unknown,
      DxvkFormat::RG8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8_UINT
    { DxvkFormat::RG8ui,
      DxvkFormat::Unknown,
      DxvkFormat::RG8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8_SNORM
    { DxvkFormat::RG8sn,
      DxvkFormat::Unknown,
      DxvkFormat::RG8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8_SINT
    { DxvkFormat::RG8si,
      DxvkFormat::Unknown,
      DxvkFormat::RG8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16_TYPELESS
    { DxvkFormat::R16un,
      DxvkFormat::D16,
      DxvkFormat::R16ui },
    // DXGI_FORMAT_R16_FLOAT
    { DxvkFormat::R16sf,
      DxvkFormat::D16,
      DxvkFormat::R16ui,
      VK_IMAGE_ASPECT_COLOR_BIT,
      VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_D16_UNORM
    { DxvkFormat::Unknown,
      DxvkFormat::D16,
      DxvkFormat::Unknown,
      0, VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_R16_UNORM
    { DxvkFormat::R16un,
      DxvkFormat::D16,
      DxvkFormat::R16ui,
      VK_IMAGE_ASPECT_COLOR_BIT,
      VK_IMAGE_ASPECT_DEPTH_BIT },
    // DXGI_FORMAT_R16_UINT
    { DxvkFormat::R16ui,
      DxvkFormat::Unknown,
      DxvkFormat::R16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16_SNORM
    { DxvkFormat::R16sn,
      DxvkFormat::Unknown,
      DxvkFormat::R16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R16_SINT
    { DxvkFormat::R16si,
      DxvkFormat::Unknown,
      DxvkFormat::R16ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8_TYPELESS
    { DxvkFormat::R8un,
      DxvkFormat::Unknown,
      DxvkFormat::R8ui },
    // DXGI_FORMAT_R8_UNORM
    { DxvkFormat::R8un,
      DxvkFormat::Unknown,
      DxvkFormat::R8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8_UINT
    { DxvkFormat::R8ui,
      DxvkFormat::Unknown,
      DxvkFormat::R8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8_SNORM
    { DxvkFormat::R8sn,
      DxvkFormat::Unknown,
      DxvkFormat::R8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8_SINT
    { DxvkFormat::R8si,
      DxvkFormat::Unknown,
      DxvkFormat::R8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_A8_UNORM
    { DxvkFormat::A8un,
      DxvkFormat::Unknown,
      DxvkFormat::R8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R1_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_R9G9B9E5_SHAREDEXP
    { DxvkFormat::RGB9E5uf,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R8G8_B8G8_UNORM
    { DxvkFormat::RGBG8un_422,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_G8R8_G8B8_UNORM
    { DxvkFormat::GRGB8un_422,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC1_TYPELESS
    { DxvkFormat::BC1un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_BC1_UNORM
    { DxvkFormat::BC1un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC1_UNORM_SRGB
    { DxvkFormat::BC1srgb,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC2_TYPELESS
    { DxvkFormat::BC2un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_BC2_UNORM
    { DxvkFormat::BC2un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC2_UNORM_SRGB
    { DxvkFormat::BC2srgb,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC3_TYPELESS
    { DxvkFormat::BC3un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_BC3_UNORM
    { DxvkFormat::BC3un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC3_UNORM_SRGB
    { DxvkFormat::BC3srgb,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC4_TYPELESS
    { DxvkFormat::BC4un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_BC4_UNORM
    { DxvkFormat::BC4un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC4_SNORM
    { DxvkFormat::BC4sn,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC5_TYPELESS
    { DxvkFormat::BC5un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_BC5_UNORM
    { DxvkFormat::BC5un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC5_SNORM
    { DxvkFormat::BC5sn,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B5G6R5_UNORM
    { DxvkFormat::B5G6R5un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B5G5R5A1_UNORM
    { DxvkFormat::BGR5A1un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B8G8R8A8_UNORM
    { DxvkFormat::BGRA8un,
      DxvkFormat::Unknown,
      DxvkFormat::BGRA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B8G8R8X8_UNORM
    { DxvkFormat::BGRX8un,
      DxvkFormat::Unknown,
      DxvkFormat::BGRA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_B8G8R8A8_TYPELESS
    { DxvkFormat::BGRA8un,
      DxvkFormat::Unknown,
      DxvkFormat::BGRA8ui },
    // DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
    { DxvkFormat::BGRA8srgb,
      DxvkFormat::Unknown,
      DxvkFormat::BGRA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B8G8R8X8_TYPELESS
    { DxvkFormat::BGRX8un,
      DxvkFormat::Unknown,
      DxvkFormat::BGRA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_B8G8R8X8_UNORM_SRGB
    { DxvkFormat::BGRX8srgb,
      DxvkFormat::Unknown,
      DxvkFormat::BGRA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC6H_TYPELESS
    { DxvkFormat::BC6Huf,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_BC6H_UF16
    { DxvkFormat::BC6Huf,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC6H_SF16
    { DxvkFormat::BC6Hsf,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC7_TYPELESS
    { DxvkFormat::BC7un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown },
    // DXGI_FORMAT_BC7_UNORM
    { DxvkFormat::BC7un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_BC7_UNORM_SRGB
    { DxvkFormat::BC7srgb,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_AYUV
    { DxvkFormat::RGBA8un,
      DxvkFormat::Unknown,
      DxvkFormat::RGBA8ui,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_Y410
    { }, // Unsupported
    // DXGI_FORMAT_Y416
    { }, // Unsupported
    // DXGI_FORMAT_NV12
    { DxvkFormat::NV12_420,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT },
    // DXGI_FORMAT_P010
    { }, // Unsupported
    // DXGI_FORMAT_P016
    { }, // Unsupported
    // DXGI_FORMAT_420_OPAQUE
    { DxvkFormat::NV12_420,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT },
    // DXGI_FORMAT_YUY2
    { DxvkFormat::GRGB8un_422,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_Y210
    { }, // Unsupported
    // DXGI_FORMAT_Y216
    { }, // Unsupported
    // DXGI_FORMAT_NV11
    { }, // Unsupported
    // DXGI_FORMAT_AI44
    { }, // Unsupported
    // DXGI_FORMAT_IA44
    { }, // Unsupported
    // DXGI_FORMAT_P8
    { }, // Unsupported
    // DXGI_FORMAT_A8P8
    { }, // Unsupported
    // DXGI_FORMAT_B4G4R4A4_UNORM
    { DxvkFormat::BGRA4un,
      DxvkFormat::Unknown,
      DxvkFormat::Unknown,
      VK_IMAGE_ASPECT_COLOR_BIT },
    // DXGI_FORMAT_P208
    { }, // Unsupported
    // DXGI_FORMAT_V208
    { }, // Unsupported
    // DXGI_FORMAT_V408
    { }, // Unsupported
  }};


  const std::array<DXGI_VK_FORMAT_FAMILY, 133> g_dxgiFamilies = {{
    // DXGI_FORMAT_UNKNOWN
    { },
    // DXGI_FORMAT_R32G32B32A32_TYPELESS
    { VK_FORMAT_R32G32B32A32_UINT,
      VK_FORMAT_R32G32B32A32_SINT,
      VK_FORMAT_R32G32B32A32_SFLOAT },
    // DXGI_FORMAT_R32G32B32A32_FLOAT
    { },
    // DXGI_FORMAT_R32G32B32A32_UINT
    { },
    // DXGI_FORMAT_R32G32B32A32_SINT
    { },
    // DXGI_FORMAT_R32G32B32_TYPELESS
    { VK_FORMAT_R32G32B32_UINT,
      VK_FORMAT_R32G32B32_SINT,
      VK_FORMAT_R32G32B32_SFLOAT },
    // DXGI_FORMAT_R32G32B32_FLOAT
    { },
    // DXGI_FORMAT_R32G32B32_UINT
    { },
    // DXGI_FORMAT_R32G32B32_SINT
    { },
    // DXGI_FORMAT_R16G16B16A16_TYPELESS
    { VK_FORMAT_R16G16B16A16_UNORM,
      VK_FORMAT_R16G16B16A16_SNORM,
      VK_FORMAT_R16G16B16A16_UINT,
      VK_FORMAT_R16G16B16A16_SINT,
      VK_FORMAT_R16G16B16A16_SFLOAT },
    // DXGI_FORMAT_R16G16B16A16_FLOAT
    { },
    // DXGI_FORMAT_R16G16B16A16_UNORM
    { },
    // DXGI_FORMAT_R16G16B16A16_UINT
    { },
    // DXGI_FORMAT_R16G16B16A16_SNORM
    { },
    // DXGI_FORMAT_R16G16B16A16_SINT
    { },
    // DXGI_FORMAT_R32G32_TYPELESS
    { VK_FORMAT_R32G32_UINT,
      VK_FORMAT_R32G32_SINT,
      VK_FORMAT_R32G32_SFLOAT },
    // DXGI_FORMAT_R32G32_FLOAT
    { },
    // DXGI_FORMAT_R32G32_UINT
    { },
    // DXGI_FORMAT_R32G32_SINT
    { },
    // DXGI_FORMAT_R32G8X24_TYPELESS
    { },
    // DXGI_FORMAT_D32_FLOAT_S8X24_UINT
    { },
    // DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS
    { },
    // DXGI_FORMAT_X32_TYPELESS_G8X24_UINT
    { },
    // DXGI_FORMAT_R10G10B10A2_TYPELESS
    { VK_FORMAT_A2B10G10R10_UNORM_PACK32,
      VK_FORMAT_A2B10G10R10_UINT_PACK32 },
    // DXGI_FORMAT_R10G10B10A2_UNORM
    { },
    // DXGI_FORMAT_R10G10B10A2_UINT
    { },
    // DXGI_FORMAT_R11G11B10_FLOAT
    { },
    // DXGI_FORMAT_R8G8B8A8_TYPELESS
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_SNORM,
      VK_FORMAT_R8G8B8A8_SRGB,
      VK_FORMAT_R8G8B8A8_UINT,
      VK_FORMAT_R8G8B8A8_SINT },
    // DXGI_FORMAT_R8G8B8A8_UNORM
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_SRGB },
    // DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_SRGB },
    // DXGI_FORMAT_R8G8B8A8_UINT
    { },
    // DXGI_FORMAT_R8G8B8A8_SNORM
    { },
    // DXGI_FORMAT_R8G8B8A8_SINT
    { },
    // DXGI_FORMAT_R16G16_TYPELESS
    { VK_FORMAT_R16G16_UNORM,
      VK_FORMAT_R16G16_SNORM,
      VK_FORMAT_R16G16_UINT,
      VK_FORMAT_R16G16_SINT,
      VK_FORMAT_R16G16_SFLOAT },
    // DXGI_FORMAT_R16G16_FLOAT
    { },
    // DXGI_FORMAT_R16G16_UNORM
    { },
    // DXGI_FORMAT_R16G16_UINT
    { },
    // DXGI_FORMAT_R16G16_SNORM
    { },
    // DXGI_FORMAT_R16G16_SINT
    { },
    // DXGI_FORMAT_R32_TYPELESS
    { VK_FORMAT_R32_UINT,
      VK_FORMAT_R32_SINT,
      VK_FORMAT_R32_SFLOAT },
    // DXGI_FORMAT_D32_FLOAT
    { },
    // DXGI_FORMAT_R32_FLOAT
    { },
    // DXGI_FORMAT_R32_UINT
    { },
    // DXGI_FORMAT_R32_SINT
    { },
    // DXGI_FORMAT_R24G8_TYPELESS
    { },
    // DXGI_FORMAT_D24_UNORM_S8_UINT
    { },
    // DXGI_FORMAT_R24_UNORM_X8_TYPELESS
    { },
    // DXGI_FORMAT_X24_TYPELESS_G8_UINT
    { },
    // DXGI_FORMAT_R8G8_TYPELESS
    { VK_FORMAT_R8G8_UNORM,
      VK_FORMAT_R8G8_SNORM,
      VK_FORMAT_R8G8_UINT,
      VK_FORMAT_R8G8_SINT },
    // DXGI_FORMAT_R8G8_UNORM
    { },
    // DXGI_FORMAT_R8G8_UINT
    { },
    // DXGI_FORMAT_R8G8_SNORM
    { },
    // DXGI_FORMAT_R8G8_SINT
    { },
    // DXGI_FORMAT_R16_TYPELESS
    { VK_FORMAT_R16_UNORM,
      VK_FORMAT_R16_SNORM,
      VK_FORMAT_R16_UINT,
      VK_FORMAT_R16_SINT,
      VK_FORMAT_R16_SFLOAT },
    // DXGI_FORMAT_R16_FLOAT
    { },
    // DXGI_FORMAT_D16_UNORM
    { },
    // DXGI_FORMAT_R16_UNORM
    { },
    // DXGI_FORMAT_R16_UINT
    { },
    // DXGI_FORMAT_R16_SNORM
    { },
    // DXGI_FORMAT_R16_SINT
    { },
    // DXGI_FORMAT_R8_TYPELESS
    { VK_FORMAT_R8_UNORM,
      VK_FORMAT_R8_SNORM,
      VK_FORMAT_R8_UINT,
      VK_FORMAT_R8_SINT },
    // DXGI_FORMAT_R8_UNORM
    { },
    // DXGI_FORMAT_R8_UINT
    { },
    // DXGI_FORMAT_R8_SNORM
    { },
    // DXGI_FORMAT_R8_SINT
    { },
    // DXGI_FORMAT_A8_UNORM
    { },
    // DXGI_FORMAT_R1_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_R9G9B9E5_SHAREDEXP
    { },
    // DXGI_FORMAT_R8G8_B8G8_UNORM
    { },
    // DXGI_FORMAT_G8R8_G8B8_UNORM
    { },
    // DXGI_FORMAT_BC1_TYPELESS
    { VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
      VK_FORMAT_BC1_RGBA_SRGB_BLOCK },
    // DXGI_FORMAT_BC1_UNORM
    { VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
      VK_FORMAT_BC1_RGBA_SRGB_BLOCK },
    // DXGI_FORMAT_BC1_UNORM_SRGB
    { VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
      VK_FORMAT_BC1_RGBA_SRGB_BLOCK },
    // DXGI_FORMAT_BC2_TYPELESS
    { VK_FORMAT_BC2_UNORM_BLOCK,
      VK_FORMAT_BC2_SRGB_BLOCK },
    // DXGI_FORMAT_BC2_UNORM
    { VK_FORMAT_BC2_UNORM_BLOCK,
      VK_FORMAT_BC2_SRGB_BLOCK },
    // DXGI_FORMAT_BC2_UNORM_SRGB
    { VK_FORMAT_BC2_UNORM_BLOCK,
      VK_FORMAT_BC2_SRGB_BLOCK },
    // DXGI_FORMAT_BC3_TYPELESS
    { VK_FORMAT_BC3_UNORM_BLOCK,
      VK_FORMAT_BC3_SRGB_BLOCK },
    // DXGI_FORMAT_BC3_UNORM
    { VK_FORMAT_BC3_UNORM_BLOCK,
      VK_FORMAT_BC3_SRGB_BLOCK },
    // DXGI_FORMAT_BC3_UNORM_SRGB
    { VK_FORMAT_BC3_UNORM_BLOCK,
      VK_FORMAT_BC3_SRGB_BLOCK },
    // DXGI_FORMAT_BC4_TYPELESS
    { VK_FORMAT_BC4_UNORM_BLOCK,
      VK_FORMAT_BC4_SNORM_BLOCK },
    // DXGI_FORMAT_BC4_UNORM
    { },
    // DXGI_FORMAT_BC4_SNORM
    { },
    // DXGI_FORMAT_BC5_TYPELESS
    { VK_FORMAT_BC5_UNORM_BLOCK,
      VK_FORMAT_BC5_SNORM_BLOCK },
    // DXGI_FORMAT_BC5_UNORM
    { },
    // DXGI_FORMAT_BC5_SNORM
    { },
    // DXGI_FORMAT_B5G6R5_UNORM
    { },
    // DXGI_FORMAT_B5G5R5A1_UNORM
    { },
    // DXGI_FORMAT_B8G8R8A8_UNORM
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_B8G8R8X8_UNORM
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_B8G8R8A8_TYPELESS
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_B8G8R8X8_TYPELESS
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_B8G8R8X8_UNORM_SRGB
    { VK_FORMAT_B8G8R8A8_UNORM,
      VK_FORMAT_B8G8R8A8_SRGB },
    // DXGI_FORMAT_BC6H_TYPELESS
    { VK_FORMAT_BC6H_UFLOAT_BLOCK,
      VK_FORMAT_BC6H_SFLOAT_BLOCK },
    // DXGI_FORMAT_BC6H_UF16
    { },
    // DXGI_FORMAT_BC6H_SF16
    { },
    // DXGI_FORMAT_BC7_TYPELESS
    { VK_FORMAT_BC7_UNORM_BLOCK,
      VK_FORMAT_BC7_SRGB_BLOCK },
    // DXGI_FORMAT_BC7_UNORM
    { VK_FORMAT_BC7_UNORM_BLOCK,
      VK_FORMAT_BC7_SRGB_BLOCK },
    // DXGI_FORMAT_BC7_UNORM_SRGB
    { VK_FORMAT_BC7_UNORM_BLOCK,
      VK_FORMAT_BC7_SRGB_BLOCK },
    // DXGI_FORMAT_AYUV
    { VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_UINT },
    // DXGI_FORMAT_Y410
    { }, // Unsupported
    // DXGI_FORMAT_Y416
    { }, // Unsupported
    // DXGI_FORMAT_NV12
    { VK_FORMAT_R8_UNORM,
      VK_FORMAT_R8G8_UNORM,
      VK_FORMAT_R8_UINT,
      VK_FORMAT_R8G8_UINT },
    // DXGI_FORMAT_P010
    { }, // Unsupported
    // DXGI_FORMAT_P016
    { }, // Unsupported
    // DXGI_FORMAT_420_OPAQUE
    { VK_FORMAT_R8_UNORM,
      VK_FORMAT_R8G8_UNORM,
      VK_FORMAT_R8_UINT,
      VK_FORMAT_R8G8_UINT },
    // DXGI_FORMAT_YUY2
    { VK_FORMAT_G8B8G8R8_422_UNORM,
      VK_FORMAT_R8G8B8A8_UNORM,
      VK_FORMAT_R8G8B8A8_UINT },
    // DXGI_FORMAT_Y210
    { }, // Unsupported
    // DXGI_FORMAT_Y216
    { }, // Unsupported
    // DXGI_FORMAT_NV11
    { }, // Unsupported
    // DXGI_FORMAT_AI44
    { }, // Unsupported
    // DXGI_FORMAT_IA44
    { }, // Unsupported
    // DXGI_FORMAT_P8
    { }, // Unsupported
    // DXGI_FORMAT_A8P8
    { }, // Unsupported
    // DXGI_FORMAT_B4G4R4A4_UNORM
    { }, // Unsupported
    // DXGI_FORMAT_P208
    { }, // Unsupported
    // DXGI_FORMAT_V208
    { }, // Unsupported
    // DXGI_FORMAT_V408
    { }, // Unsupported
  }};
  
  
  DXGIVkFormatTable::DXGIVkFormatTable(const Rc<DxvkDevice>& Device)
  : m_device(Device) {

  }
  
  
  DXGIVkFormatTable::~DXGIVkFormatTable() {
    
  }
  
  
  DXGI_VK_FORMAT_INFO DXGIVkFormatTable::GetFormatInfo(
          DXGI_FORMAT         Format,
          DXGI_VK_FORMAT_MODE Mode) const {
    return GetFormatInfoFromMapping(
      GetFormatMapping(Format), Mode);
  }


  DXGI_VK_FORMAT_FAMILY DXGIVkFormatTable::GetFormatFamily(
          DXGI_FORMAT         Format,
          DXGI_VK_FORMAT_MODE Mode) const {
    if (Mode == DXGI_VK_FORMAT_MODE_DEPTH)
      return DXGI_VK_FORMAT_FAMILY();
    
    const size_t formatId = size_t(Format);

    return formatId < g_dxgiFamilies.size()
      ? g_dxgiFamilies[formatId]
      : g_dxgiFamilies[0];
  }


  DXGI_VK_FORMAT_INFO DXGIVkFormatTable::GetFormatInfoFromMapping(
    const DXGI_VK_FORMAT_MAPPING* pMapping,
          DXGI_VK_FORMAT_MODE     Mode) const {
    switch (Mode) {
      case DXGI_VK_FORMAT_MODE_ANY:
        return pMapping->FormatColor != DxvkFormat::Unknown
          ? DXGI_VK_FORMAT_INFO { &m_device->lookupFormat(pMapping->FormatColor), pMapping->AspectColor }
          : DXGI_VK_FORMAT_INFO { &m_device->lookupFormat(pMapping->FormatDepth), pMapping->AspectDepth };
      
      case DXGI_VK_FORMAT_MODE_COLOR:
        return { &m_device->lookupFormat(pMapping->FormatColor), pMapping->AspectColor };
      
      case DXGI_VK_FORMAT_MODE_DEPTH:
        return { &m_device->lookupFormat(pMapping->FormatDepth), pMapping->AspectDepth };
      
      case DXGI_VK_FORMAT_MODE_RAW:
        return { &m_device->lookupFormat(pMapping->FormatRaw), pMapping->AspectColor };

      default:
        Logger::err("DXGIVkFormatTable::GetFormatInfoFromMapping: Invalid format lookup mode");
        return DXGI_VK_FORMAT_INFO();
    }
  }


  const DXGI_VK_FORMAT_MAPPING* DXGIVkFormatTable::GetFormatMapping(
          DXGI_FORMAT         Format) const {
    const size_t formatId = size_t(Format);
    
    return formatId < g_dxgiFormats.size()
      ? &g_dxgiFormats[formatId]
      : &g_dxgiFormats[0];
  }
  
}