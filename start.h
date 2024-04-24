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
SDL_Texture*music1[10];
SDL_Texture*amluong[10];
 SDL_Texture*chedo[7];
 SDL_Texture*tu[2];
int hp = 100;
 int sx,sy,kx,ky;
bool  mouseButtonPressed = false;
public:
int nholive=100;
//bool inman[4] = {0,0,0,0};
void renderbackgroundgame();
void rendergamestart(SDL_Event &e,double &start);
void spacegame(SDL_Event &e,double &start);
void renderbacksword (SDL_Event &e ,double &start);
void pause(SDL_Event &e ,double &start,int &r,double &nhostart);
void hp1(SDL_Event &e ,double &start,int &live,int &sodan);
void sw(bool &xske,bool &sw,bool &wn,SDL_Event &e);
void musical(double &start,SDL_Event &e);
void chinh(int &volume, SDL_Event& e);
void chinhnen(int &volume1, SDL_Event& e);
void chinhnhacnen(int &chon, SDL_Event& e);
void chon(SDL_Event &e,double &start,int mandaqua[]);
void ce(SDL_Event &e ,double &start,int &r);
void tutorial(SDL_Event &e,double &start);
void tt(SDL_Event &e,double &start);
};
#endif
