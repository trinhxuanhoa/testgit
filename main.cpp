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
#include "start.h"
using namespace std;



TTF_Font* gFont = NULL;
SDL_Window*window = NULL;
SDL_Renderer*renderer = NULL;
Dot dot;
Startgame sg;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;

LTexture gDot[10];
LTexture gBG[2];



int main (int argc, char* argv[]) {
init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
SDL_SetRenderDrawColor(renderer,255,255,255,255);

SDL_Event e;

Ai ai[10];
Witch witch[10];
music Music;
int active=0;
double start = 0.0;
int saberx,sabery;
SDL_Texture*a=loadTexture(renderer,"saber/saber2.3.png");
SDL_QueryTexture(a,NULL,NULL,&saberx,&sabery);
SDL_DestroyTexture(a);
a=NULL;
int khung_hinh = 0;
SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

//gDot[0].loadFromFile("saber/saber1.png");
gDot[0].loadFromFile("saber/newsaber.png");
gDot[1].loadFromFile("saber/newsaber1.png");
gDot[2].loadFromFile("saber/sabere1.png");
gDot[3].loadFromFile("saber/sabere2.png");
gDot[4].loadFromFile("saber/sabere3.png");

Music.loadMusic();
SDL_Texture*gameover=loadTexture(renderer,"Game_Over.png");
SDL_Texture*backgroundgameover=loadTexture(renderer,"backgroundgameover.png");

bool s1=true,w1=true;
gBG[0].loadFromFile("pigmap.png");
gBG[1].loadFromFile("map2.png");
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

//witch[0].handleEvent(e);

}

if(start==0.0)

{
dot.resetdemlive=0;
dot.demsoluong(ai[0].live,witch[0].live);
SDL_RenderClear(renderer);
sg.renderbackgroundgame();
sg.rendergamestart(e,start);

}
if(start==0.1) {
sg.spacegame(e,start);
sg.sw(s1,w1,witch[0].wn,e);
sg.hp1(e,start,ai[0].live,witch[0].sodan);
witch[0].live=sg.nholive;
}
if (e.type==SDL_MOUSEBUTTONDOWN) {
    int x,y;
   // if(start==0)start=1;
    SDL_GetMouseState(&x,&y);
   // if(x>=147&&x<=456&&y>=111&&y<=161&&start==2.0) start=1.0;

  if(start==2.0) start=0.0;
   cout << x << " " << y << endl;
}
}
if (start==1.0) {

dot.move();
dot.resetdemlive=1;
SDL_Delay(10);
camera.x = dot.getPosX()+saberx/6-SCREEN_WIDTH/2;//cout << dot.getPosY() << endl;
camera.y = dot.getPosY()+sabery/6-SCREEN_HEIGHT/2;


if (camera.x<0) camera.x=0;
if(camera.x>LEVEL_WIDTH-SCREEN_WIDTH) camera.x=LEVEL_WIDTH-SCREEN_WIDTH;
if (camera.y>0) camera.y=0;
//if(camera.y<LEVEL_HEIGHT-SCREEN_HEIGHT) camera.y=LEVEL_HEIGHT-SCREEN_HEIGHT;
dot.camera=camera;

SDL_RenderClear(renderer);

gBG[0].render(-camera.x,-camera.y);
gBG[1].render(-camera.x,-450-camera.y);
sg.renderbacksword(e,start);
if(dot.hesotim>=120){

       dot.hesotim=0;dot.mPosX=0;

       ai[0].live=sg.nholive;
       ai[0].mPosX=1900;


       witch[0].live=sg.nholive;witch[0].mPosX=900;
       for(int i = 0; i < 10; i++) {
    witch[0].mdan[i]=0;
}
}

dot.tim();


if(dot.danh==0) {
dot.renderMove(e,camera.x,camera.y,nhay);
dot.mskill=0;

}
else{
dot.chem();

ai[0].danh=dot.danh;

witch[0].danh=dot.danh;
Music.danh1=dot.danh;
Music.handleMusic();
}
//ai[1].move();

if(s1){
ai[0].sv=dot.v;
ai[0].sPosX=dot.mPosX;
ai[0].sPosY=dot.mPosY;
ai[0].camera=camera;
ai[0].skill=dot.skill;
ai[0].skilly=dot.skilly;
ai[0].move(dot.hesotim);
}



if(w1) {
witch[0].sPosX=dot.mPosX;
witch[0].sPosY=dot.mPosY;
witch[0].camera=camera;
witch[0].skill=dot.skill;
witch[0].skilly=dot.skilly;
witch[0].move(dot.hesotim);
}

dot.demsoluong(ai[0].live,witch[0].live);
//cout << dot.mPosX << " " << ai.mPosX << " " << dot.skill << endl;
if(s1)
ai[0].rendermonster();
//ai[1].renderwitch();
if(w1)
witch[0].renderwitch(dot.hesotim);
SDL_Delay(20);

if(dot.hesotim>=119){

        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;

        ai[0].live=sg.nholive;ai[0].mPosX=900;



        start=2.0;
witch[0].live=sg.nholive;witch[0].mPosX=900;
for(int i = 0; i < 10; i++) {
    witch[0].mdan[i]=0;
}

}


}
if(start==1.1) {

int r=0;
sg.pause(e,start,r);
if (r==1)
{

   dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;

        ai[0].live=sg.nholive;ai[0].mPosX=900;

    witch[0].live=sg.nholive;witch[0].mPosX=900;
    for(int i = 0; i < 10; i++) {
    witch[0].mdan[i]=0;
}
}
}
if(start==2.0)
{
SDL_RenderCopy(renderer,backgroundgameover,NULL,NULL);
SDL_RenderCopy(renderer,gameover,NULL,NULL);

}

SDL_RenderPresent(renderer);

}
SDL_DestroyTexture(gameover);
SDL_DestroyTexture(backgroundgameover);
backgroundgameover=NULL;
gameover=NULL;
Music.closeMusic();
quitSDL(window,renderer);
return 0;
}
