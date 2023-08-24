// License: The Unlicense (https://unlicense.org)
#include <SDL2/SDL.h>

struct widget {
  widget(SDL_Renderer* p_renderer);

  void render(SDL_Renderer* p_renderer);

  void handle_keyboard_event(SDL_Keycode p_key);
  void handle_window_event(SDL_WindowEvent p_key);

private:
  void move_forward(void);

private:
  double m_x_pos;
  double m_x_vel;
  double m_y_pos;
  double m_y_vel;
  double m_angle;
  double m_angle_momentum;
  int m_window_width;
  int m_window_height;
  SDL_Texture* m_texture;
};
