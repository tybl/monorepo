// License: The Unlicense (https://unlicense.org)
#include "Dispatcher.hpp"
#include "Widget.hpp"
#include "Window.hpp"

#include <SDL2/SDL.h>

#include <cstdio>

// The window renderer
static SDL_Renderer* g_renderer = nullptr;

int main(int argc, char* argv[]) {
  static_cast<void>(argc);
  static_cast<void>(argv);

  // Initialize SDL
  if (0 > SDL_Init(SDL_INIT_VIDEO)) {
    fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    return -1;
  }

  // Set texture filtering to linear
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    printf("Warning: Linear texture filtering not enabled!");
  }

  window window;
  dispatcher dispatch;

  // Create vsynced renderer for window
  g_renderer = window.create_renderer();
  if (g_renderer == nullptr) {
    std::printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return -1;
  }
  widget ownship(g_renderer);
  dispatch.add_keyboard_listener([&](SDL_Keycode p_key) { ownship.handle_keyboard_event(p_key); });
  dispatch.add_window_listener([&](SDL_WindowEvent p_e) { ownship.handle_window_event(p_e); });

  while (dispatch.keep_running()) {
    dispatch.process_events();

    SDL_SetRenderTarget(g_renderer, nullptr);
    // Clear screen
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 0);
    SDL_RenderClear(g_renderer);

    ownship.render(g_renderer);

    // Update screen
    SDL_RenderPresent(g_renderer);
  } // while (keep_running)

  // Destroy window
  SDL_DestroyRenderer(g_renderer);
  g_renderer = nullptr;

  // Quit SDL subsystems
  SDL_Quit();
  return 0;
}
