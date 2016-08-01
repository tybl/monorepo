#include "Widget.hpp"

#include <cassert>
#include <cmath>

Widget::Widget(SDL_Renderer *renderer)
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

void Widget::Render(SDL_Renderer *renderer) {
   SDL_Rect destination = { static_cast<int>(mXPos), static_cast<int>(mYPos), 30, 30 };
   SDL_RenderCopyEx(renderer, mTexture, nullptr, &destination, mAngle, nullptr, SDL_FLIP_NONE);
}

void Widget::HandleKeyboardEvent(SDL_Keycode key) {
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
void Widget::MoveForward(void) {
   mXPos += std::sin(mAngle * M_PI / 180.0) * 10;
   mYPos += std::cos(mAngle * M_PI / 180.0) * 10;
}
