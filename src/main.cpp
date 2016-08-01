#include "Dispatcher.hpp"
#include "Window.hpp"

#include <SDL2/SDL.h>
#include <cassert>
#include <cmath>
#include <cstdio>

//The window renderer
static SDL_Renderer* gRenderer = NULL;

struct Widget {
   Widget(SDL_Renderer *renderer)
      : mXPos(0),
      mYPos(0),
      mAngle(0),
      mTexture(SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 30, 30))
   {
      assert(nullptr != mTexture);
      SDL_SetRenderTarget(renderer, mTexture);

      SDL_Rect fill_rect = { 10, 0, 10, 20 };
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderFillRect(renderer, &fill_rect);
      fill_rect.x = 0;
      fill_rect.y = 20;
      fill_rect.h = 10;
      SDL_RenderFillRect(renderer, &fill_rect);
      fill_rect.x = 20;
      SDL_RenderFillRect(renderer, &fill_rect);
   }

   void Render(SDL_Renderer *renderer) {
      SDL_Rect destination = { static_cast<int>(mXPos), static_cast<int>(mYPos), 30, 30 };
      SDL_RenderCopyEx(renderer, mTexture, nullptr, &destination, mAngle, nullptr, SDL_FLIP_NONE);
   }

   void HandleKeyboardEvent(SDL_Keycode key) {
      switch (key) {
         case SDLK_SPACE:
            mXPos = 0;
            mYPos = 0;
            break;
         case SDLK_UP:
            // TODO: Move ownship forward with respect to heading
            mXPos += std::sin(mAngle * M_PI / 180.0) * 10;
            mYPos -= std::cos(mAngle * M_PI / 180.0) * 10;
            break;
         case SDLK_DOWN:
            // TODO: Figure out what ownship should do when down is pressed
            break;
         case SDLK_LEFT:
            mAngle -= 5;
            break;
         case SDLK_RIGHT:
            mAngle += 5;
            break;
         default:
            break;
      }
   }
private:
   void MoveForward(void) {
      mXPos += std::sin(mAngle * M_PI / 180.0) * 10;
      mYPos += std::cos(mAngle * M_PI / 180.0) * 10;
   }
private:
   double mXPos;
   double mYPos;
   double mAngle;
   SDL_Texture *mTexture;
};

int main(int argc, char* argv[]) {
   static_cast<void>(argc);
   static_cast<void>(argv);

   //Initialize SDL
   if (0 > SDL_Init(SDL_INIT_VIDEO)) {
      fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
      return -1;
   }

   //Set texture filtering to linear
   if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      printf( "Warning: Linear texture filtering not enabled!");
   }

   Window window;
   Dispatcher dispatch;

   //Create vsynced renderer for window
   gRenderer = window.CreateRenderer();
   if (gRenderer == NULL) {
      printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
      return -1;
   }
   Widget ownship(gRenderer);
   dispatch.AddKeyboardListener([&] (SDL_Keycode key) { ownship.HandleKeyboardEvent(key); });
   //Initialize renderer color
   SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);

   while (dispatch.KeepRunning()) {
      dispatch.ProcessEvents();

      SDL_SetRenderTarget(gRenderer, nullptr);
      //Clear screen
      SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
      SDL_RenderClear(gRenderer);

      ownship.Render(gRenderer);

      //Update screen
      SDL_RenderPresent(gRenderer);
   } // while (keep_running)

   //Destroy window
   SDL_DestroyRenderer(gRenderer);
   gRenderer = NULL;

   //Quit SDL subsystems
   SDL_Quit();
   return 0;
}
