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
#include "Ai.h"
#include "music.h"
using namespace std;



TTF_Font* gFont = NULL;
SDL_Window*window = NULL;
SDL_Renderer*renderer = NULL;

/*Mix_Music *amthanhnen= NULL;
Mix_Chunk *gScratch = NULL;
Mix_Chunk *gHigh = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;*/

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;

LTexture gDot[10];
LTexture gBG;



int main (int argc, char* argv[]) {
init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
SDL_SetRenderDrawColor(renderer,255,255,255,255);

SDL_Event e;
Dot dot;
Ai ai;
music Music;
int active=0;
int start = 2;
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
Music.loadMusic();
SDL_Texture*gameover=loadTexture(renderer,"Game_Over.png");
SDL_Texture*backgroundgameover=loadTexture(renderer,"backgroundgameover.png");
SDL_Texture*startgame=loadTexture(renderer,"menu.png");

gBG.loadFromFile("pigmap.png");
dot.w=saberx/3;dot.h=sabery/3;
int nhay=0;
int dem = 0;

Music.nhacnen();
while (true) {


if(SDL_PollEvent(&e)!=0) {
    if (e.type==SDL_QUIT) break;
if(e.type==SDL_KEYDOWN||e.type==SDL_KEYUP) {

dot.handleEvent(e);
dot.e = e;
//ai.handleEvent(e);

}
SDL_RenderClear(renderer);
if(start==2)
    SDL_RenderCopy(renderer,startgame,NULL,NULL);
if (e.type==SDL_MOUSEBUTTONDOWN) {
    int x,y;
   // if(start==0)start=1;

    SDL_GetMouseState(&x,&y);
    if(x>=147&&x<=456&&y>=111&&y<=161&&start==2) start=1;
  if(start==0) start=2;
    cout << x << " " << y << endl;
}
}
if (start==1) {
dot.move();
ai.sv=dot.v;
//xuong.mPosX=dot.mPosX;
//xuong.mPosY=dot.mPosY;
SDL_Delay(10);
camera.x = dot.getPosX()+saberx/6-SCREEN_WIDTH/2;//cout << dot.getPosY() << endl;
camera.y = dot.getPosY()+sabery/6-SCREEN_HEIGHT/2;
ai.sPosX=dot.mPosX;
ai.sPosY=dot.mPosY;
if (camera.x<0) camera.x=0;
if(camera.x>LEVEL_WIDTH-SCREEN_WIDTH) camera.x=LEVEL_WIDTH-SCREEN_WIDTH;
dot.camera=camera;
ai.camera=camera;
SDL_RenderClear(renderer);
gBG.render(-camera.x,0);

if(ai.hesotim>=120){ai.hesotim=0;dot.mPosX=0;ai.live=100;ai.mPosX=900;}

dot.hesotim=ai.hesotim;

dot.tim();


if(dot.danh==0) {
dot.renderMove(e,camera.x,nhay,khung_hinh);
dot.mskill=0;

}
else{
dot.chem();
ai.danh=dot.danh;
Music.danh1=dot.danh;
Music.handleMusic();
}
ai.move();
ai.skill=dot.skill;
//cout << dot.mPosX << " " << ai.mPosX << " " << dot.skill << endl;
ai.rendermonster();
SDL_Delay(20);
if(ai.hesotim>=120){
        ai.hesotim=0;dot.mPosX=0;ai.live=100;ai.mPosX=900;start=0;

start=0;
}
}
if(start==0)
{SDL_RenderCopy(renderer,backgroundgameover,NULL,NULL);
SDL_RenderCopy(renderer,gameover,NULL,NULL);
}

SDL_RenderPresent(renderer);
}
waitUntilKeyPressed();
SDL_DestroyTexture(gameover);
SDL_DestroyTexture(backgroundgameover);
backgroundgameover=NULL;
gameover=NULL;
Music.closeMusic();
quitSDL(window,renderer);
return 0;
}
