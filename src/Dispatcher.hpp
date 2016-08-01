#ifndef GOON_DISPATCHER_HPP
#define GOON_DISPATCHER_HPP

#include <SDL2/SDL.h>
#include <functional>
#include <vector>

struct Dispatcher {
   Dispatcher(void);
   bool KeepRunning(void) const;
   void ProcessEvents(void);
   void AddKeyboardListener(std::function<void(SDL_Keycode)> func);
private:
   void OptOutEvents(void);
private:
   std::vector<std::function<void(SDL_Keycode)>> mKeyboardListeners;
   bool mKeepRunning;
};
#endif // GOON_DISPATCHER_HPP
