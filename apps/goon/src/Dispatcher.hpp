// License: The Unlicense (https://unlicense.org)
#ifndef GOON_DISPATCHER_HPP
#define GOON_DISPATCHER_HPP

#include <SDL2/SDL.h>

#include <functional>
#include <vector>

struct dispatcher {
  dispatcher(void);
  [[gnu::pure]] bool keep_running(void) const;
  void process_events(void);
  void add_keyboard_listener(std::function<void(SDL_Keycode)> p_func);
  void add_window_listener(std::function<void(SDL_WindowEvent)> p_func);

private:
  void opt_out_events(void);

private:
  std::vector<std::function<void(SDL_Keycode)>> m_keyboard_listeners;
  std::vector<std::function<void(SDL_WindowEvent)>> m_window_listeners;
  bool m_keep_running;
};
#endif // GOON_DISPATCHER_HPP
