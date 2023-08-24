// License: The Unlicense (https://unlicense.org)
#include "Widget.hpp"

#include <cassert>
#include <cmath>
#include <cstdio>

static const int TEXTURE_WIDTH = 90;
static const int TEXTURE_HEIGHT = 90;

widget::widget(SDL_Renderer* p_renderer)
  : m_x_pos(0)
  , m_x_vel(0)
  , m_y_pos(0)
  , m_y_vel(0)
  , m_angle(0)
  , m_angle_momentum(0)
  , m_window_width(640)
  , m_window_height(480)
  , m_texture(SDL_CreateTexture(p_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TEXTURE_WIDTH,
                                TEXTURE_HEIGHT)) {
  assert(nullptr != m_texture);
  SDL_SetRenderTarget(p_renderer, m_texture);

  SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 0);
  SDL_RenderClear(p_renderer);
  SDL_SetRenderDrawColor(p_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderDrawLine(p_renderer, TEXTURE_WIDTH / 2, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
  SDL_RenderDrawLine(p_renderer, TEXTURE_WIDTH / 2, 0, 0, TEXTURE_HEIGHT);
  SDL_RenderDrawLine(p_renderer, TEXTURE_WIDTH / 2, TEXTURE_HEIGHT * 2 / 3, TEXTURE_WIDTH, TEXTURE_HEIGHT);
  SDL_RenderDrawLine(p_renderer, TEXTURE_WIDTH / 2, TEXTURE_HEIGHT * 2 / 3, 0, TEXTURE_HEIGHT);
}

void widget::render(SDL_Renderer* p_renderer) {
  // Update position
  m_angle += m_angle_momentum;
  m_x_pos += m_x_vel;
  m_y_pos += m_y_vel;
  if (m_x_pos > m_window_width / 2)
    m_x_pos -= m_window_width;
  else if (m_x_pos < m_window_width / -2)
    m_x_pos += m_window_width;
  if (m_y_pos > m_window_height / 2)
    m_y_pos -= m_window_height;
  else if (m_y_pos < m_window_height / -2)
    m_y_pos += m_window_height;

  SDL_Rect destination = {
      static_cast<int>(m_x_pos), // x
      static_cast<int>(m_y_pos), // y
      TEXTURE_WIDTH,             // w
      TEXTURE_HEIGHT             // h
  };

  SDL_RenderCopyEx(p_renderer, m_texture, nullptr, &destination, m_angle, nullptr, SDL_FLIP_NONE);
  destination.x += m_window_width;
  SDL_RenderCopyEx(p_renderer, m_texture, nullptr, &destination, m_angle, nullptr, SDL_FLIP_NONE);
  destination.y += m_window_height;
  SDL_RenderCopyEx(p_renderer, m_texture, nullptr, &destination, m_angle, nullptr, SDL_FLIP_NONE);
  destination.x -= m_window_width;
  SDL_RenderCopyEx(p_renderer, m_texture, nullptr, &destination, m_angle, nullptr, SDL_FLIP_NONE);
}

void widget::handle_keyboard_event(SDL_Keycode p_key) {
  switch (p_key) {
    case SDLK_SPACE:
      m_x_pos = 0;
      m_y_pos = 0;
      break;
    case SDLK_UP:
      m_x_vel += std::sin(m_angle * M_PI / 180.0) * 1;
      m_y_vel -= std::cos(m_angle * M_PI / 180.0) * 1;
      break;
    case SDLK_DOWN:
      // TODO: Figure out what ownship should do when down is pressed
      break;
    case SDLK_LEFT: m_angle_momentum -= 1; break;
    case SDLK_RIGHT: m_angle_momentum += 1; break;
    default: break;
  }
}

void widget::handle_window_event(SDL_WindowEvent p_e) {
  switch (p_e.event) {
    case SDL_WINDOWEVENT_SHOWN: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_HIDDEN: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_EXPOSED:
      // Received when window is resized
      printf("%d\n", __LINE__);
      break;
    case SDL_WINDOWEVENT_MOVED: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_RESIZED:
    case SDL_WINDOWEVENT_SIZE_CHANGED:
      m_window_width = p_e.data1;
      m_window_height = p_e.data2;
      break;
    case SDL_WINDOWEVENT_MINIMIZED: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_MAXIMIZED: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_RESTORED: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_ENTER: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_LEAVE: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_FOCUS_GAINED: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_FOCUS_LOST: printf("%d\n", __LINE__); break;
    case SDL_WINDOWEVENT_CLOSE: printf("%d\n", __LINE__); break;
    default: printf("%d\n", __LINE__); break;
  }
}

void widget::move_forward(void) {
  m_x_pos += std::sin(m_angle * M_PI / 180.0) * 10;
  m_y_pos += std::cos(m_angle * M_PI / 180.0) * 10;
}
