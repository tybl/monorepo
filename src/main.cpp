#include "Keyboard.hpp"
#include "Window.hpp"

#include <SDL2/SDL.h>
#include <cstdio>

class Widget {
   int mXPos;
   int mYPos;
   int mAngle;
public:
   Widget(int xPos, int yPos) : mXPos(xPos), mYPos(yPos) { }
   int& XPos(void) { return mXPos; }
   int& YPos(void) { return mYPos; }
};

//The window renderer
static SDL_Renderer* gRenderer = NULL;

int EventFilter(void *userData, SDL_Event *event);

int main(int argc, char* argv[]) {
   static_cast<void>(argc);
   static_cast<void>(argv);

   Widget ownship(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

   //Initialize SDL
   if (0 > SDL_Init(SDL_INIT_VIDEO)) {
      fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
      return -1;
   }

   SDL_EventState(SDL_APP_TERMINATING, SDL_IGNORE);
   SDL_EventState(SDL_APP_LOWMEMORY, SDL_IGNORE);
   SDL_EventState(SDL_APP_WILLENTERBACKGROUND, SDL_IGNORE);
   SDL_EventState(SDL_APP_DIDENTERBACKGROUND, SDL_IGNORE);
   SDL_EventState(SDL_APP_WILLENTERFOREGROUND, SDL_IGNORE);
   SDL_EventState(SDL_APP_DIDENTERFOREGROUND, SDL_IGNORE);
   SDL_EventState(SDL_AUDIODEVICEADDED, SDL_IGNORE);
   SDL_EventState(SDL_AUDIODEVICEREMOVED, SDL_IGNORE);
   SDL_EventState(SDL_CLIPBOARDUPDATE, SDL_IGNORE);
   SDL_EventState(SDL_CONTROLLERAXISMOTION, SDL_IGNORE);
   SDL_EventState(SDL_CONTROLLERBUTTONDOWN, SDL_IGNORE);
   SDL_EventState(SDL_CONTROLLERBUTTONUP, SDL_IGNORE);
   SDL_EventState(SDL_CONTROLLERDEVICEADDED, SDL_IGNORE);
   SDL_EventState(SDL_CONTROLLERDEVICEREMAPPED, SDL_IGNORE);
   SDL_EventState(SDL_CONTROLLERDEVICEREMOVED, SDL_IGNORE);
   SDL_EventState(SDL_DOLLARGESTURE, SDL_IGNORE);
   SDL_EventState(SDL_DOLLARRECORD, SDL_IGNORE);
   SDL_EventState(SDL_DROPFILE, SDL_IGNORE);
   SDL_EventState(SDL_FINGERDOWN, SDL_IGNORE);
   SDL_EventState(SDL_FINGERMOTION, SDL_IGNORE);
   SDL_EventState(SDL_FINGERUP, SDL_IGNORE);
   SDL_EventState(SDL_JOYAXISMOTION, SDL_IGNORE);
   SDL_EventState(SDL_JOYBALLMOTION, SDL_IGNORE);
   SDL_EventState(SDL_JOYBUTTONDOWN, SDL_IGNORE);
   SDL_EventState(SDL_JOYBUTTONUP, SDL_IGNORE);
   SDL_EventState(SDL_JOYDEVICEADDED, SDL_IGNORE);
   SDL_EventState(SDL_JOYDEVICEREMOVED, SDL_IGNORE);
   SDL_EventState(SDL_JOYHATMOTION, SDL_IGNORE);
   SDL_EventState(SDL_KEYMAPCHANGED, SDL_IGNORE);
   SDL_EventState(SDL_KEYUP, SDL_IGNORE);
   SDL_EventState(SDL_LASTEVENT, SDL_IGNORE);
   SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
   SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
   SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
   SDL_EventState(SDL_MOUSEWHEEL, SDL_IGNORE);
   SDL_EventState(SDL_MULTIGESTURE, SDL_IGNORE);
   SDL_EventState(SDL_RENDER_TARGETS_RESET, SDL_IGNORE);
   SDL_EventState(SDL_RENDER_DEVICE_RESET, SDL_IGNORE);
   SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);
   SDL_EventState(SDL_TEXTEDITING, SDL_IGNORE);
   SDL_EventState(SDL_TEXTINPUT, SDL_IGNORE);
   SDL_EventState(SDL_USEREVENT, SDL_IGNORE);
   SDL_SetEventFilter(EventFilter, nullptr);

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

int EventFilter(void *, SDL_Event *event) {
   int result = 0;
   switch (event->type) {
      case SDL_QUIT:
      case SDL_WINDOWEVENT:
         result = 1;
         break;
      case SDL_KEYDOWN:
         switch (event->key.keysym.sym) {
            case SDLK_DOWN:
            case SDLK_UP:
            case SDLK_LEFT:
            case SDLK_RIGHT:
               result = 1;
               break;
            default:
               // Ignore all other keys
               break;
         }
         break;
      default:
         printf("Something happened!\n");
         break;
   }
   return result;
}
