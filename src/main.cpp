#include "EventHandler.hpp"
#include "Keyboard.hpp"
#include "Window.hpp"

#include <SDL2/SDL.h>
#include <cstdio>

class Widget {
   int mXPos;
   int mYPos;
   //int mAngle;
public:
   Widget(int xPos, int yPos) : mXPos(xPos), mYPos(yPos) { }
   int& XPos(void) { return mXPos; }
   int& YPos(void) { return mYPos; }
};

//The window renderer
static SDL_Renderer* gRenderer = NULL;

int main(int argc, char* argv[]) {
   static_cast<void>(argc);
   static_cast<void>(argv);

   Widget ownship(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

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

      //Clear screen
      SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
      SDL_RenderClear(gRenderer);

      //Draw ship
      SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderDrawLine(gRenderer, ownship.XPos() + 5, ownship.YPos() + 5, ownship.XPos(), ownship.YPos() - 5);
      SDL_RenderDrawLine(gRenderer, ownship.XPos(), ownship.YPos() - 5, ownship.XPos() - 5, ownship.YPos() + 5);
      SDL_RenderDrawLine(gRenderer, ownship.XPos() + 5, ownship.YPos() + 5, ownship.XPos() - 5, ownship.YPos() + 5);
      ownship.XPos() += 1;

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
