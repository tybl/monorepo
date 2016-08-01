#include <SDL2/SDL.h>

struct Widget {
   Widget(SDL_Renderer *renderer);

   void Render(SDL_Renderer *renderer);

   void HandleKeyboardEvent(SDL_Keycode key);

private:
   void MoveForward(void);

private:
   double mXPos;
   double mXVelocity;
   double mYPos;
   double mYVelocity;
   double mAngle;
   double mAngleMomentum;
   SDL_Texture *mTexture;
};
