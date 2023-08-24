// License: The Unlicense (https://unlicense.org)
#include "Window.hpp"

#include <cassert>
#include <cstdio>

window::window(void)
  : m_window(SDL_CreateWindow("goon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE))
  , m_width(SCREEN_WIDTH)
  , m_height(SCREEN_HEIGHT) {
  assert(nullptr != m_window);
}

void window::process_event(const SDL_Event& p_event) {
  switch (p_event.window.event) {
    case SDL_WINDOWEVENT_SHOWN: printf("Window has been shown\n"); break;
    case SDL_WINDOWEVENT_HIDDEN: printf("Window has been hidden\n"); break;
    case SDL_WINDOWEVENT_EXPOSED: printf("Window has been exposed and should be redrawn\n"); break;
    case SDL_WINDOWEVENT_MOVED:
      printf("Window has been moved to (%d, %d)\n", p_event.window.data1, p_event.window.data2);
      break;
    case SDL_WINDOWEVENT_RESIZED:
      m_width = p_event.window.data1;
      m_height = p_event.window.data2;
      printf("Window has been resized to %d x %d\n", p_event.window.data1, p_event.window.data2);
      break;
    case SDL_WINDOWEVENT_SIZE_CHANGED:
      printf("Window size changed to %d x %d\n", p_event.window.data1, p_event.window.data2);
      break;
    case SDL_WINDOWEVENT_MINIMIZED: printf("Window minimized\n"); break;
    case SDL_WINDOWEVENT_MAXIMIZED: printf("Window maximized\n"); break;
    case SDL_WINDOWEVENT_RESTORED: printf("Window restored\n"); break;
    case SDL_WINDOWEVENT_ENTER: printf("Mouse entered window\n"); break;
    case SDL_WINDOWEVENT_LEAVE: printf("Mouse left window\n"); break;
    case SDL_WINDOWEVENT_FOCUS_GAINED: printf("Window gained keyboard focus\n"); break;
    case SDL_WINDOWEVENT_FOCUS_LOST: printf("Window lost keyboard focus\n"); break;
    case SDL_WINDOWEVENT_CLOSE: printf("Window manager requests that the window be closed\n"); break;
    default: printf("Some window event happened!\n"); break;
  }
}
