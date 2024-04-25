#ifndef SDL_util__h
#define SDL_util__h

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "sdlutils.h"
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include <SDL_mixer.h>
using namespace std;



void logSDLError(ostream& os,
 const string &msg, bool fatal);
void init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer,int SCREEN_WIDTH,int SCREEN_HEIGHT,const string &WINDOW_TITLE);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,int SCREEN_WIDTH,int SCREEN_HEIGHT,const string &WINDOW_TITLE);
void waitUntilKeyPressed();
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void quitSDL_Image(SDL_Texture*texture);
SDL_Texture* loadTexture (SDL_Renderer*renderer,string path);
//SDL_Texture* loadFromFile( SDL_Renderer*renderer,string path);
void renderOriginal(SDL_Renderer*renderer,SDL_Texture*a, int x, int y);
void renderQuarterOriginal(SDL_Renderer*renderer,SDL_Texture*a,int x,int y,int local);
void Motion (SDL_Renderer*renderer,SDL_Texture*people,const int WALKING_ANIMATION_FRAMES,const int speed,int width,SDL_Rect gSpriteClips[]);
void renderEx( SDL_Renderer*renderer,SDL_Texture*a,int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip );
void xoay(SDL_Renderer*renderer,SDL_Texture*a);
SDL_Texture *loadFromRenderedText(SDL_Renderer*renderer,string textureText, SDL_Color textColor,TTF_Font* gFont);
#endif

