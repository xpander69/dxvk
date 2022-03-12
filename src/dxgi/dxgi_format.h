#pragma once

#include "dxgi_include.h"

#include "../dxvk/dxvk_device.h"
#include "../dxvk/dxvk_format.h"

namespace dxvk {
  
  /**
   * \brief Format mapping
   * 
   * Maps a DXGI format to a set of Vulkan formats.
   */
  struct DXGI_VK_FORMAT_MAPPING {
    DxvkFormat                  FormatColor   = DxvkFormat::Unknown;  ///< Corresponding color format
    DxvkFormat                  FormatDepth   = DxvkFormat::Unknown;  ///< Corresponding depth format
    DxvkFormat                  FormatRaw     = DxvkFormat::Unknown;  ///< Bit-compatible integer format
    VkImageAspectFlags          AspectColor   = 0;                    ///< Defined aspects for the color format
    VkImageAspectFlags          AspectDepth   = 0;                    ///< Defined aspects for the depth format
  };
  
  /**
   * \brief Format info
   * 
   * Stores a Vulkan image format for a given
   * DXGI format and some additional information
   * on how resources with the particular format
   * are supposed to be used.
   */
  struct DXGI_VK_FORMAT_INFO {
    const DxvkFormatProperties* pFormat     = nullptr;              ///< Format properties
    VkImageAspectFlags          Aspect      = 0;                    ///< Defined image aspect mask
  };
  
  /**
   * \brief Format lookup mode
   * 
   * When looking up an image format, additional information
   * might be needed on how the image is going to be used.
   * This is used to properly map typeless formats and color
   * formats to depth formats if they are used on depth images.
   */
  enum DXGI_VK_FORMAT_MODE {
    DXGI_VK_FORMAT_MODE_ANY   = 0,  ///< Color first, then depth
    DXGI_VK_FORMAT_MODE_COLOR = 1,  ///< Color only
    DXGI_VK_FORMAT_MODE_DEPTH = 2,  ///< Depth only
    DXGI_VK_FORMAT_MODE_RAW   = 3,  ///< Unsigned integer format
  };
  
  
  /**
   * \brief Format family
   * 
   * Stores a set of compatible formats. This can
   * be used to aggregate formats for the image
   * format list extension.
   */
  using DXGI_VK_FORMAT_FAMILY = DxvkTypedFormatList<DXGI_FORMAT>;
  
  
  /**
   * \brief Format table
   * 
   * Initializes a format table for a specific
   * device and provides methods to look up
   * formats.
   */
  class DXGIVkFormatTable {

  public:

    DXGIVkFormatTable(const Rc<DxvkDevice>& Device);
    ~DXGIVkFormatTable();

    /**
     * \brief Retrieves info for a given DXGI format
     * 
     * \param [in] Format The DXGI format to look up
     * \param [in] Mode the format lookup mode
     * \returns Format info
     */
    DXGI_VK_FORMAT_INFO GetFormatInfo(
            DXGI_FORMAT         Format,
            DXGI_VK_FORMAT_MODE Mode) const;

    /**
     * \brief Retrieves a format family
     * 
     * \param [in] Format The format to query
     * \returns Image format family
     */
    DXGI_VK_FORMAT_FAMILY GetFormatFamily(
            DXGI_FORMAT         Format) const;
    
  private:

    Rc<DxvkDevice> m_device;

    DXGI_VK_FORMAT_INFO GetFormatInfoFromMapping(
      const DXGI_VK_FORMAT_MAPPING* pMapping,
            DXGI_VK_FORMAT_MODE   Mode) const;

    const DXGI_VK_FORMAT_MAPPING* GetFormatMapping(
            DXGI_FORMAT           Format) const;

    const DXGI_VK_FORMAT_MAPPING* GetPackedFormatMapping(
            DXGI_FORMAT           Format) const;

  };
  
}