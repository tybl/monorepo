#ifndef GOON_WINDOW_HPP
#define GOON_WINDOW_HPP

#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


class Window {
   //SDL_Window *mWindow;
   int mWidth;
   int mHeight;
public:
   Window(void)
      : mWidth(SCREEN_WIDTH),
      mHeight(SCREEN_HEIGHT)
   {
      // Intentionally left blank
   }
   int Width(void) const { return mWidth; }
   int Height(void) const { return mHeight; }
   void ProcessEvent(const SDL_Event &event);
};
#endif // GOON_WINDOW_HPP
