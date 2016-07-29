//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
static SDL_Window* gWindow = NULL;

class Widget {
   int mXPos;
   int mYPos;
public:
   Widget(int xPos, int yPos) : mXPos(xPos), mYPos(yPos) { }
   int XPos(void) const { return mXPos; }
   int YPos(void) const { return mYPos; }
};

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
   void ProcessEvent(const SDL_Event &event) {
      switch (event.window.event) {
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
            printf("Window has been moved to (%d, %d)\n", event.window.data1, event.window.data2);
            break;
         case SDL_WINDOWEVENT_RESIZED:
            mWidth = event.window.data1;
            mHeight = event.window.data2;
            printf("Window has been resized to %d x %d\n", event.window.data1, event.window.data2);
            break;
         case SDL_WINDOWEVENT_SIZE_CHANGED:
            printf("Window size changed to %d x %d\n", event.window.data1, event.window.data2);
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
   }
};

class Keyboard {
public:
   void ProcessEvent(const SDL_Event &event) {
      switch (event.key.keysym.sym) {
         case SDLK_0: printf("0"); break;
         case SDLK_1: printf("1"); break;
         case SDLK_2: printf("2"); break;
         case SDLK_3: printf("3"); break;
         case SDLK_4: printf("4"); break;
         case SDLK_5: printf("5"); break;
         case SDLK_6: printf("6"); break;
         case SDLK_7: printf("7"); break;
         case SDLK_8: printf("8"); break;
         case SDLK_9: printf("9"); break;
         case SDLK_a: printf("a"); break;
         case SDLK_b: printf("b"); break;
         case SDLK_c: printf("c"); break;
         case SDLK_d: printf("d"); break;
         case SDLK_e: printf("e"); break;
         case SDLK_f: printf("f"); break;
         case SDLK_g: printf("g"); break;
         case SDLK_h: printf("h"); break;
         case SDLK_i: printf("i"); break;
         case SDLK_j: printf("j"); break;
         case SDLK_k: printf("k"); break;
         case SDLK_l: printf("l"); break;
         case SDLK_m: printf("m"); break;
         case SDLK_n: printf("n"); break;
         case SDLK_o: printf("o"); break;
         case SDLK_p: printf("p"); break;
         case SDLK_q: printf("q"); break;
         case SDLK_r: printf("r"); break;
         case SDLK_s: printf("s"); break;
         case SDLK_t: printf("t"); break;
         case SDLK_u: printf("u"); break;
         case SDLK_v: printf("v"); break;
         case SDLK_w: printf("w"); break;
         case SDLK_x: printf("x"); break;
         case SDLK_y: printf("y"); break;
         case SDLK_z: printf("z"); break;
         case SDLK_BACKQUOTE: printf("`"); break;
         case SDLK_BACKSLASH: printf("\\"); break;
         case SDLK_BACKSPACE: printf("<backspace>"); break;
         case SDLK_COMMA: printf(","); break;
         case SDLK_DELETE: printf("<delete>"); break;
         case SDLK_DOWN: printf("<down arrow>"); break;
         case SDLK_END: printf("<end>"); break;
         case SDLK_EQUALS: printf("="); break;
         case SDLK_ESCAPE: printf("<escape>"); break;
         case SDLK_F1: printf("<F1>"); break;
         case SDLK_F2: printf("<F2>"); break;
         case SDLK_F3: printf("<F3>"); break;
         case SDLK_F4: printf("<F4>"); break;
         case SDLK_F5: printf("<F5>"); break;
         case SDLK_F6: printf("<F6>"); break;
         case SDLK_F7: printf("<F7>"); break;
         case SDLK_F8: printf("<F8>"); break;
         case SDLK_F9: printf("<F9>"); break;
         case SDLK_F10: printf("<F10>"); break;
         case SDLK_F11: printf("<F11>"); break;
         case SDLK_F12: printf("<F12>"); break;
         case SDLK_F13: printf("<F13>"); break;
         case SDLK_F14: printf("<F14>"); break;
         case SDLK_F15: printf("<F15>"); break;
         case SDLK_F16: printf("<F16>"); break;
         case SDLK_F17: printf("<F17>"); break;
         case SDLK_F18: printf("<F18>"); break;
         case SDLK_F19: printf("<F19>"); break;
         case SDLK_F20: printf("<F20>"); break;
         case SDLK_F21: printf("<F21>"); break;
         case SDLK_F22: printf("<F22>"); break;
         case SDLK_F23: printf("<F23>"); break;
         case SDLK_F24: printf("<F24>"); break;
         case SDLK_HOME: printf("<home>"); break;
         case SDLK_KP_0: printf("0"); break;
         case SDLK_KP_1: printf("1"); break;
         case SDLK_KP_2: printf("2"); break;
         case SDLK_KP_3: printf("3"); break;
         case SDLK_KP_4: printf("4"); break;
         case SDLK_KP_5: printf("5"); break;
         case SDLK_KP_6: printf("6"); break;
         case SDLK_KP_7: printf("7"); break;
         case SDLK_KP_8: printf("8"); break;
         case SDLK_KP_9: printf("9"); break;
         case SDLK_KP_DIVIDE: printf("/"); break;
         case SDLK_KP_ENTER: printf("<enter>"); break;
         case SDLK_KP_MINUS: printf("-"); break;
         case SDLK_KP_MULTIPLY: printf("*"); break;
         case SDLK_KP_PERIOD: printf("."); break;
         case SDLK_KP_PLUS: printf("+"); break;
         case SDLK_LALT: printf("<l alt>"); break;
         case SDLK_LCTRL: printf("<l ctrl>"); break;
         case SDLK_LEFT: printf("<left arrow>"); break;
         case SDLK_LEFTBRACKET: printf("["); break;
         case SDLK_LGUI: printf("<l gui>"); break;
         case SDLK_LSHIFT: printf("<l shift>"); break;
         case SDLK_MINUS: printf("-"); break;
         case SDLK_NUMLOCKCLEAR: printf("<numlock>"); break;
         case SDLK_PAGEDOWN: printf("<page down>"); break;
         case SDLK_PAGEUP: printf("<page up>"); break;
         case SDLK_PAUSE: printf("<pause>"); break;
         case SDLK_PERIOD: printf("."); break;
         case SDLK_PRINTSCREEN: printf("<print screen>"); break;
         case SDLK_QUOTE: printf("'"); break;
         case SDLK_RALT: printf("<r alt>"); break;
         case SDLK_RCTRL: printf("<r ctrl>"); break;
         case SDLK_RETURN: printf("<return>"); break;
         case SDLK_RETURN2: printf("<return2>"); break;
         case SDLK_RGUI: printf("<r gui>"); break;
         case SDLK_RIGHT: printf("<right arrow>"); break;
         case SDLK_RIGHTBRACKET: printf("]"); break;
         case SDLK_RSHIFT: printf("<r shift>"); break;
         case SDLK_SCROLLLOCK: printf("<scroll lock>"); break;
         case SDLK_SEMICOLON: printf(";"); break;
         case SDLK_SLASH: printf("/"); break;
         case SDLK_SPACE: printf("<space>"); break;
         case SDLK_TAB: printf("<tab>"); break;
         case SDLK_UP: printf("<up arrow>"); break;
         case SDLK_AC_BACK:
         case SDLK_AC_BOOKMARKS:
         case SDLK_AC_FORWARD:
         case SDLK_AC_HOME:
         case SDLK_AC_REFRESH:
         case SDLK_AC_SEARCH:
         case SDLK_AC_STOP:
         case SDLK_AGAIN:
         case SDLK_ALTERASE:
         case SDLK_APPLICATION:
         case SDLK_AUDIOMUTE:
         case SDLK_AUDIONEXT:
         case SDLK_AUDIOPLAY:
         case SDLK_AUDIOPREV:
         case SDLK_AUDIOSTOP:
         default:
            printf("unknown key event");
            break;
      }
      std::fflush(stdout);
   }
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

   SDL_EventState(SDL_APP_TERMINATING, SDL_IGNORE);
   SDL_EventState(SDL_APP_LOWMEMORY, SDL_IGNORE);
   SDL_EventState(SDL_APP_WILLENTERBACKGROUND, SDL_IGNORE);
   SDL_EventState(SDL_APP_DIDENTERBACKGROUND, SDL_IGNORE);
   SDL_EventState(SDL_APP_WILLENTERFOREGROUND, SDL_IGNORE);
   SDL_EventState(SDL_APP_DIDENTERFOREGROUND, SDL_IGNORE);
   SDL_EventState(SDL_AUDIODEVICEADDED, SDL_IGNORE);
   SDL_EventState(SDL_AUDIODEVICEREMOVED, SDL_IGNORE);
   SDL_EventState(SDL_DROPFILE, SDL_IGNORE);
   SDL_EventState(SDL_FINGERDOWN, SDL_IGNORE);
   SDL_EventState(SDL_FINGERMOTION, SDL_IGNORE);
   SDL_EventState(SDL_FINGERUP, SDL_IGNORE);
   SDL_EventState(SDL_KEYMAPCHANGED, SDL_IGNORE);
   SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
   SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
   SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
   SDL_EventState(SDL_MOUSEWHEEL, SDL_IGNORE);
   SDL_EventState(SDL_TEXTINPUT, SDL_IGNORE);

   //Set texture filtering to linear
   if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      printf( "Warning: Linear texture filtering not enabled!");
   }

   //Create window
   gWindow = SDL_CreateWindow("goon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   Window window;
   Keyboard kb;
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
               window.ProcessEvent(e);
               break;
            case SDL_SYSWMEVENT:
               printf("Event %d\n", __LINE__);
               break;
            case SDL_KEYDOWN:
               kb.ProcessEvent(e);
               break;
            case SDL_KEYUP:
               break;
            case SDL_TEXTEDITING:
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
