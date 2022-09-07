#pragma once

#include <windows.h>
#include <memory>
#include "../src/util/com/com_pointer.h"

namespace sample {

  struct Extent2D {
    uint32_t w, h;
  };

  struct StaticVertex {
    float pos   [3];
    float uv    [2];
    float normal[3];
  };

  class ISampleApp {
  public:
    virtual bool init(HWND window) = 0;
    virtual bool frame() = 0;

    virtual const char* title() = 0;
    virtual int         defaultWidth()  = 0;
    virtual int         defaultHeight() = 0;

    static std::unique_ptr<ISampleApp> create();
  };

}
