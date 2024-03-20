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
//LTexture chem[10];


int main (int argc, char* argv[]) {
init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
SDL_SetRenderDrawColor(renderer,255,255,255,255);

SDL_Event e;
Dot dot;
int saberx,sabery;
SDL_Texture*a=loadTexture(renderer,"saber/saber2.3.png");
SDL_QueryTexture(a,NULL,NULL,&saberx,&sabery);
SDL_DestroyTexture(a);
a=NULL;
int khung_hinh = 0;
SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

//gDot[0].loadFromFile("saber/saber1.png");
gDot[0].loadFromFile("saber/newsaber.png");
gDot[1].loadFromFile("saber/sabere1.png");
gDot[2].loadFromFile("saber/sabere2.png");
gDot[3].loadFromFile("saber/sabere3.png");


gBG.loadFromFile("pigmap.png");
dot.w=saberx/3;dot.h=sabery/3;
int nhay=0;
int dem = 0;
while (true) {

if(SDL_PollEvent(&e)!=0) {
    if (e.type==SDL_QUIT) break;
if(e.type==SDL_KEYDOWN||e.type==SDL_KEYUP) {

dot.handleEvent(e);
dot.e = e;


}

if (e.type==SDL_MOUSEBUTTONDOWN) {
    int x,y;
    SDL_GetMouseState(&x,&y);
    cout << x << " " << y << endl;
}
}

dot.move();
SDL_Delay(10);
camera.x = dot.getPosX()+saberx/6-SCREEN_WIDTH/2;//cout << dot.getPosY() << endl;
camera.y = dot.getPosY()+sabery/6-SCREEN_HEIGHT/2;
if (camera.x<0) camera.x=0;
if(camera.x>LEVEL_WIDTH-SCREEN_WIDTH) camera.x=LEVEL_WIDTH-SCREEN_WIDTH;
dot.camera=camera;
SDL_RenderClear(renderer);
gBG.render(-camera.x,0);
dot.tim();


//cout << dot.getPosX() << endl;
if(dot.danh==0)
dot.renderMove(e,camera.x,nhay,khung_hinh);
else
dot.chem();
SDL_Delay(20);
SDL_RenderPresent(renderer);



}

quitSDL(window,renderer);
return 0;
}
