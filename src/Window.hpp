// License: The Unlicense (https://unlicense.org)
#ifndef GOON_WINDOW_HPP
#define GOON_WINDOW_HPP

#include <SDL2/SDL.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class window {
  SDL_Window* m_window;
  int m_width;
  int m_height;

public:
  window(void);
  window(window const&) = delete;
  ~window(void) { SDL_DestroyWindow(m_window); }
  window& operator=(window const&) = delete;
  int width(void) const { return m_width; }
  int height(void) const { return m_height; }
  void process_event(const SDL_Event& p_event);
  SDL_Renderer* create_renderer(void) {
    return SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  }
};
#endif // GOON_WINDOW_HPP
