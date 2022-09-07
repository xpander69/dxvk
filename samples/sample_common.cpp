#include "sample_common.h"
#include <iostream>

using namespace sample;

#ifdef _WIN32
static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  switch (message) {
    case WM_CLOSE:
      PostQuitMessage(0);
      return 0;
  }

  return DefWindowProcW(hWnd, message, wParam, lParam);
}

BaseTestApp::BaseTestApp(HINSTANCE instance, const char* title, int w, int h)
  : m_instance(instance) {
  WNDCLASSEXA wc   = { };
  wc.cbSize        = sizeof(wc);
  wc.style         = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc   = WindowProc;
  wc.hInstance     = instance;
  wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
  wc.hbrBackground = HBRUSH(COLOR_WINDOW);
  wc.lpszClassName = "WindowClass";
  RegisterClassExW(&wc);

  m_window = CreateWindowExA(0, "WindowClass", title,
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT,
    w, h,
    nullptr, nullptr, instance, nullptr);
  ShowWindow(m_window, nCmdShow);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  return run_test(hInstance);
}
#else
#include <SDL2/SDL.h>

static int mainLoop(ISampleApp *sample) {
  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          running = false;
          break;
        default:
          break;
      }
    }

    if (!sample->frame())
      break;
  }

  return 0;
}

int main(int argc, char** argv) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
    std::cerr << "Failed to init SDL" << std::endl;
    return 1;
  }

  auto sample = ISampleApp::create();
  if (!sample) {
    std::cerr << "Failed to create sample" << std::endl;
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow(
    sample->title(),
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    sample->defaultWidth(), sample->defaultHeight(),
    SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
  if (!window) {
    std::cerr << "Failed create SDL window: " << SDL_GetError() << std::endl;
    return 1;
  }

  if (!sample->init(window)) {
    std::cerr << "Failed to init sample" << std::endl;
    return 1;
  }

  return mainLoop(sample.get());
}
#endif
