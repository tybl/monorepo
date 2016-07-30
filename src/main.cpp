#include "EventHandler.hpp"
#include "Keyboard.hpp"
#include "Window.hpp"

#include <SDL2/SDL.h>
#include <cassert>
#include <cstdio>

//The window renderer
static SDL_Renderer* gRenderer = NULL;

class Widget {
   int mXPos;
   int mYPos;
   double mAngle;
   SDL_Texture *mTexture;
public:
   Widget(SDL_Renderer *renderer, int xPos, int yPos)
      : mXPos(xPos),
      mYPos(yPos),
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
   int& XPos(void) { return mXPos; }
   int& YPos(void) { return mYPos; }
   void Render(SDL_Renderer *renderer) {
      SDL_Rect destination = { mXPos, mYPos, 30, 30 };
      SDL_RenderCopyEx(renderer, mTexture, nullptr, &destination, mAngle, nullptr, SDL_FLIP_NONE);
      mAngle += 0.5;
   }
};

int main(int argc, char* argv[]) {
   static_cast<void>(argc);
   static_cast<void>(argv);

   //Initialize SDL
   if (0 > SDL_Init(SDL_INIT_VIDEO)) {
      fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
      return -1;
   }

   SetUpEvents();

   //Set texture filtering to linear
   if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      printf( "Warning: Linear texture filtering not enabled!");
   }

   Window window;
   Keyboard kb;

   //Create vsynced renderer for window
   gRenderer = window.CreateRenderer();
   if (gRenderer == NULL) {
      printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
      return -1;
   }
   Widget ownship(gRenderer, 0, 0);
   //Initialize renderer color
   SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);

   bool keep_running = true;
   while (keep_running) {
      SDL_Event e;
      while (0 != SDL_PollEvent(&e)) {
         switch (e.type) {
            case SDL_QUIT:
               keep_running = false;
               break;
            case SDL_WINDOWEVENT:
               window.ProcessEvent(e);
               break;
            case SDL_KEYDOWN:
               kb.ProcessEvent(e);
               break;
            default:
               printf("Something happened!\n");
               break;
         } // switch
      } // while

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
