#include <SDL2/SDL.h>

struct Widget {
   Widget(SDL_Renderer *renderer);

   void Render(SDL_Renderer *renderer);

   void HandleKeyboardEvent(SDL_Keycode key);

private:
   void MoveForward(void);

private:
   double mXPos;
   double mYPos;
   double mAngle;
   SDL_Texture *mTexture;
};
