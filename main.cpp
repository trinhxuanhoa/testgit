#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "sdlutils.h"
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "surface.h"
#include "main.h"
#include <SDL_mixer.h>
#include "motion.h"
using namespace std;


TTF_Font* gFont = NULL;
SDL_Window*window = NULL;
SDL_Renderer*renderer = NULL;

Mix_Music *gMusic = NULL;
Mix_Chunk *gScratch = NULL;
Mix_Chunk *gHigh = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;

LTexture gDot[10];
LTexture gBG;



int main (int argc, char* argv[]) {
init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
SDL_SetRenderDrawColor(renderer,255,255,255,255);

SDL_Event e;
Dot dot;
int saberx,sabery;
SDL_Texture*a=loadTexture(renderer,"saber2.png");
SDL_QueryTexture(a,NULL,NULL,&saberx,&sabery);
SDL_DestroyTexture(a);
a=NULL;
int khung_hinh = 0;
SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

//gDot[0].loadFromFile("saber/saber1.png");
gDot[0].loadFromFile("saber/saber2.png");
gDot[1].loadFromFile("saber/saber3.png");
gBG.loadFromFile("map1.png");

int nhay=0;
int dem = 0;
while (true) {

if(SDL_PollEvent(&e)!=0) {
    if (e.type==SDL_QUIT) break;
if(e.type==SDL_KEYDOWN||e.type==SDL_KEYUP) {

dot.handleEvent(e);
dot.move();

camera.x = dot.getPosX()+saberx-SCREEN_WIDTH;//cout << dot.getPosY() << endl;
camera.y = dot.getPosY()+sabery-SCREEN_HEIGHT;

if (camera.x<0) camera.x=0;
if(camera.x>LEVEL_WIDTH-SCREEN_WIDTH) camera.x=LEVEL_WIDTH-SCREEN_WIDTH;
if (e.key.keysym.sym==SDLK_RIGHT||e.key.keysym.sym==SDLK_LEFT)
{khung_hinh++;
dot.vacham(e,camera,saberx,sabery);}
}
if(e.type==SDL_MOUSEBUTTONDOWN) {
    int x,y;
    SDL_GetMouseState(&x,&y);
    cout << x << " " << y << endl;
}
}

if (dot.getmVelY()>0&&nhay==0) dem = 80;

if(dem<=80&&dem>=71) nhay+=8;
if(dem<=70&&dem>=61) nhay+=6;
if(dem<=60&&dem>=51) nhay+=4;
if(dem<=50&&dem>=41) nhay+=2;
if(dem<=40&&dem>=31) nhay-=2;
if(dem<=30&&dem>=21) nhay-=4;
if(dem<=20&&dem>=11) nhay-=6;
if(dem<=10&&dem>=1 ) nhay-=8;
dem--;if (dem<0)dem=0;


SDL_RenderClear(renderer);
gBG.render(-camera.x,0);
gBG.render(SCREEN_WIDTH-camera.x,0);
if (khung_hinh>7) khung_hinh=0;
dot.renderMove(e,camera.x,nhay,khung_hinh);
SDL_RenderPresent(renderer);



}

quitSDL(window,renderer);
return 0;
}
