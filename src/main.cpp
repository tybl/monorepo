//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
static SDL_Window* gWindow = NULL;

//The window renderer
static SDL_Renderer* gRenderer = NULL;

int main(int argc, char* argv[]) {
   static_cast<void>(argc);
   static_cast<void>(argv);

   //Initialize SDL
   if (0 > SDL_Init(SDL_INIT_VIDEO)) {
      fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
      return -1;
   }

   SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
   SDL_EventState(SDL_FINGERMOTION, SDL_IGNORE);

   //Set texture filtering to linear
   if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      printf( "Warning: Linear texture filtering not enabled!");
   }

   //Create window
   gWindow = SDL_CreateWindow("goon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
   if (gWindow == NULL) {
      fprintf(stderr, "Window could not be created! SDL Error: %s\n", SDL_GetError());
      return -1;
   }

   //Create vsynced renderer for window
   gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
               switch (e.window.event) {
                  case SDL_WINDOWEVENT_SHOWN:
                     printf("Window has been shown\n");
                     break;
                  case SDL_WINDOWEVENT_HIDDEN:
                     printf("Window has been hidden\n");
                     break;
                  case SDL_WINDOWEVENT_EXPOSED:
                     printf("Window has been exposed and should be redrawn\n");
                     break;
                  case SDL_WINDOWEVENT_MOVED:
                     printf("Window has been moved to (%d, %d)\n", e.window.data1, e.window.data2);
                     break;
                  case SDL_WINDOWEVENT_RESIZED:
                     printf("Window has been resized to %d x %d\n", e.window.data1, e.window.data2);
                     break;
                  case SDL_WINDOWEVENT_SIZE_CHANGED:
                     printf("Window size changed to %d x %d\n", e.window.data1, e.window.data2);
                     break;
                  case SDL_WINDOWEVENT_MINIMIZED:
                     printf("Window minimized\n");
                     break;
                  case SDL_WINDOWEVENT_MAXIMIZED:
                     printf("Window maximized\n");
                     break;
                  case SDL_WINDOWEVENT_RESTORED:
                     printf("Window restored\n");
                     break;
                  case SDL_WINDOWEVENT_ENTER:
                     printf("Mouse entered window\n");
                     break;
                  case SDL_WINDOWEVENT_LEAVE:
                     printf("Mouse left window\n");
                     break;
                  case SDL_WINDOWEVENT_FOCUS_GAINED:
                     printf("Window gained keyboard focus\n");
                     break;
                  case SDL_WINDOWEVENT_FOCUS_LOST:
                     printf("Window lost keyboard focus\n");
                     break;
                  case SDL_WINDOWEVENT_CLOSE:
                     printf("Window manager requests that the window be closed\n");
                     break;
                  default:
                     printf("Some window event happened!\n");
                     break;
               }
               break;
            case SDL_SYSWMEVENT:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_APP_TERMINATING:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_APP_LOWMEMORY:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_APP_WILLENTERBACKGROUND:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_APP_DIDENTERBACKGROUND:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_APP_WILLENTERFOREGROUND:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_APP_DIDENTERFOREGROUND:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_KEYDOWN:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_KEYUP:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_TEXTEDITING:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_TEXTINPUT:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_KEYMAPCHANGED:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_MOUSEBUTTONDOWN:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_MOUSEBUTTONUP:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_MOUSEWHEEL:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_JOYAXISMOTION:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_JOYBALLMOTION:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_JOYHATMOTION:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_JOYBUTTONDOWN:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_JOYBUTTONUP:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_JOYDEVICEADDED:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_JOYDEVICEREMOVED:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_CONTROLLERAXISMOTION:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_CONTROLLERBUTTONDOWN:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_CONTROLLERBUTTONUP:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_CONTROLLERDEVICEADDED:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_CONTROLLERDEVICEREMOVED:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_CONTROLLERDEVICEREMAPPED:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_FINGERDOWN:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_FINGERUP:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_DOLLARGESTURE:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_DOLLARRECORD:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_MULTIGESTURE:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_CLIPBOARDUPDATE:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_DROPFILE:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_AUDIODEVICEADDED:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_AUDIODEVICEREMOVED:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_RENDER_TARGETS_RESET:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_RENDER_DEVICE_RESET:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_USEREVENT:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_LASTEVENT:
               printf("Event %d\n", __LINE__);
               break;
#if 0
            case SDL_MOUSEMOTION:
               printf("Mouse motion!\n");
               break;
            case SDL_FINGERMOTION:
               printf("Finger motion\n");
               break;
#endif
            default:
               printf("Something happened!\n");
               break;
         } // switch
      } // while

      //Clear screen
      SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
      SDL_RenderClear(gRenderer);

      //Update screen
      SDL_RenderPresent(gRenderer);
   } // while (keep_running)

   //Destroy window
   SDL_DestroyRenderer(gRenderer);
   SDL_DestroyWindow(gWindow);
   gWindow = NULL;
   gRenderer = NULL;

   //Quit SDL subsystems
   SDL_Quit();
   return 0;
}
