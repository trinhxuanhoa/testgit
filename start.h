#ifndef start_h
#define start_h

#include <iostream>
#include <SDL.h>
#include <bits/stdc++.h>
#include "sdlutils.h"
#include <SDL_image.h>
#include "surface.h"
#include <SDL_mixer.h>
#include "Ai.h"
using namespace std;
extern SDL_Renderer* renderer;

class Startgame {
    SDL_Texture*startgame[10];
    SDL_Texture*spacegames[10];
    SDL_Texture*backsword[10];
    SDL_Texture*hpm[10];

int hp = 100;
bool  mouseButtonPressed = false;
public:
int nholive=100;
void renderbackgroundgame();
void rendergamestart(SDL_Event &e,double &start);
void spacegame(SDL_Event &e,double &start);
void renderbacksword (SDL_Event &e ,double &start);
void pause(SDL_Event &e ,double &start,int &r);
void hp1(SDL_Event &e ,double &start,int &live,int &sodan);
void sw(bool &xske,bool &sw,bool &wn,SDL_Event &e);
};
#endif
