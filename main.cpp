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
#include "video.h"
using namespace std;



TTF_Font* gFont = NULL;
SDL_Window*window = NULL;
SDL_Renderer*renderer = NULL;
Dot dot;
Startgame sg;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000/SCREEN_FPS;

LTexture gDot[5];
LTexture gBG[2];



int main (int argc, char* argv[]) {
init(window,renderer,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
SDL_SetRenderDrawColor(renderer,255,255,255,255);
SDL_RenderClear(renderer);
SDL_Texture*dangload=loadTexture(renderer,"startgame/backgroundstartgame.png");
SDL_RenderCopy(renderer,dangload,NULL,NULL);
SDL_Texture*dangload1=loadTexture(renderer,"startgame/dangload.png");
SDL_RenderCopy(renderer,dangload1,NULL,NULL);
SDL_RenderPresent(renderer);

SDL_Event e;
int volume=2;
int volume1=2;
int chon=0;
int hinh = 0;
int nhochon=chon;
Ai ai[10];
Witch witch[10];
Video video;
music Music;
int active=0;
bool ds4=1,dw4=1,ds5=1,dw5=1,d1=1,d2=1,d3=1;
double start = 0.0;
double nhostart = start;
int mandaqua[4]={0,0,0,0};
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

//Music.nhacnen(volume1);
video.loadvideo();
while (true) {

Music.nhacnen(volume1,chon,nhochon);

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
sg.tutorial(e,start);
}
if(start==0.1) {
sg.spacegame(e,start);
sg.sw(s1,w1,witch[0].wn,e);
sg.hp1(e,start,ai[0].live,witch[0].sodan);
witch[0].live=sg.nholive;
}
if(start==0.2) {
SDL_RenderClear(renderer);
sg.musical(start,e);
sg.chinh(volume,e);
sg.chinhnen(volume1,e);
sg.chinhnhacnen(chon,e);
Music.nhacnen(volume1,chon,nhochon);
}
if(start==0.3) {
    sg.tt(e,start);
}
if (e.type==SDL_MOUSEBUTTONDOWN) {
    int x,y;
   // if(start==0)start=1;
    SDL_GetMouseState(&x,&y);
   // if(x>=147&&x<=456&&y>=111&&y<=161&&start==2.0) start=1.0;

  if(start==2.0) start=0.0;
  // cout << x << " " << y << endl;
}
}
if (start==3.0) {
        SDL_Delay(60);
        SDL_RenderClear(renderer);

    video.rendervideo(hinh);
     sg.chon(e,start,mandaqua);
    hinh++;
}

if(start==3.1) {
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
nhostart=start;
sg.renderbacksword(e,start);
    if(dot.hesotim>=120){

       dot.hesotim=0;dot.mPosX;
       ai[1].live=sg.nholive;
       ai[1].mPosX=1900;
}
dot.tim();
if(dot.danh==0) {
dot.renderMove(e,camera.x,camera.y,nhay);
dot.mskill=0;
}
else{
dot.chem();
ai[1].danh=dot.danh;

Music.danh1=dot.danh;
Music.handleMusic(volume);
}


ai[1].sv=dot.v;
ai[1].sPosX=dot.mPosX;
ai[1].sPosY=dot.mPosY;
ai[1].camera=camera;
ai[1].skill=dot.skill;
ai[1].skilly=dot.skilly;
//cout << ai[1].live << endl;
if(ai[1].live<=1) {
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
        ai[1].live=sg.nholive;ai[1].mPosX=900;
ai[1].live=100;
mandaqua[0]=1;
d1=0;
        start=4.0;
}
ai[1].move(dot.hesotim);

//dot.demsoluong(ai[1].live,witch[1].live);
if(d1)
ai[1].rendermonster();
d1=1;
SDL_Delay(20);

if(dot.hesotim>=119){
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
        ai[1].live=sg.nholive;ai[1].mPosX=900;
        start=2.0;
}

}
if(start==3.2) {
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
nhostart=start;
sg.renderbacksword(e,start);
    if(dot.hesotim>=120){

       dot.hesotim=0;dot.mPosX;
         witch[2].live=sg.nholive;witch[2].mPosX=900;
       for(int i = 0; i < 10; i++) {
    witch[2].mdan[i]=0;
}
}
dot.tim();
if(dot.danh==0) {
dot.renderMove(e,camera.x,camera.y,nhay);
dot.mskill=0;
}
else{
dot.chem();

witch[2].danh=dot.danh;
Music.danh1=dot.danh;
Music.handleMusic(volume);
}


witch[2].sPosX=dot.mPosX;
witch[2].sPosY=dot.mPosY;
witch[2].camera=camera;
witch[2].skill=dot.skill;
witch[2].skilly=dot.skilly;
//cout << witch[2].checkmusic << endl;
if(witch[2].checkmusic)
Music.amthanhsung(volume);
//cout << witch[2].live << endl;
if(witch[2].live<=2) {
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
       witch[2].live=sg.nholive;witch[2].mPosX=900;
witch[2].live=100;
mandaqua[1]=1;
d2=0;
        start=4.0;
}

witch[2].move(dot.hesotim);
//dot.demsoluong(ai[1].live,witch[1].live);
if(d2)
witch[2].renderwitch(dot.hesotim);
d2=1;
SDL_Delay(20);

if(dot.hesotim>=119){
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
       witch[2].live=sg.nholive;witch[2].mPosX=900;
        start=2.0;
}
}
if(start==3.3) {
witch[3].sodan=5;
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
nhostart=start;
sg.renderbacksword(e,start);
    if(dot.hesotim>=120){

       dot.hesotim=0;dot.mPosX;
         witch[3].live=sg.nholive;witch[2].mPosX=900;
       for(int i = 0; i < 10; i++) {
    witch[3].mdan[i]=0;
}
}
dot.tim();
if(dot.danh==0) {
dot.renderMove(e,camera.x,camera.y,nhay);
dot.mskill=0;
}
else{
dot.chem();

witch[3].danh=dot.danh;
Music.danh1=dot.danh;
Music.handleMusic(volume);
}


witch[3].sPosX=dot.mPosX;
witch[3].sPosY=dot.mPosY;
witch[3].camera=camera;
witch[3].skill=dot.skill;
witch[3].skilly=dot.skilly;
if(witch[3].checkmusic)
Music.amthanhsung(volume);
//cout << witch[3].live << endl;
if(witch[3].live<=2) {
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
       witch[3].live=sg.nholive;witch[3].mPosX=900;
witch[3].live=100;
mandaqua[2]=1;
d3=0;
        start=4.0;
}

witch[3].move(dot.hesotim);
//dot.demsoluong(ai[1].live,witch[1].live);
if(d3)
witch[3].renderwitch(dot.hesotim);
d3=1;
SDL_Delay(20);

if(dot.hesotim>=119){
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
       witch[3].live=sg.nholive;witch[3].mPosX=900;
        start=2.0;
}
}
if (start==3.4) {

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
nhostart=start;
sg.renderbacksword(e,start);

if(dot.hesotim>=120){

       dot.hesotim=0;dot.mPosX=0;

       ai[4].live=sg.nholive;
       ai[4].mPosX=1900;


       witch[4].live=sg.nholive;witch[4].mPosX=900;
       for(int i = 0; i < 10; i++) {
    witch[4].mdan[i]=0;
}
}

dot.tim();


if(dot.danh==0) {
dot.renderMove(e,camera.x,camera.y,nhay);
dot.mskill=0;

}
else{
dot.chem();

ai[4].danh=dot.danh;

witch[4].danh=dot.danh;
Music.danh1=dot.danh;
Music.handleMusic(volume);
}
//ai[1].move();

if(ds4) {
ai[4].sv=dot.v;
ai[4].sPosX=dot.mPosX;
ai[4].sPosY=dot.mPosY;
ai[4].camera=camera;
ai[4].skill=dot.skill;
ai[4].skilly=dot.skilly;
ai[4].move(dot.hesotim);
}

if(dw4) {
witch[4].sPosX=dot.mPosX;
witch[4].sPosY=dot.mPosY;
witch[4].camera=camera;
witch[4].skill=dot.skill;
witch[4].skilly=dot.skilly;
witch[4].move(dot.hesotim);
if(witch[4].checkmusic)
Music.amthanhsung(volume);
}
if(ai[4].live<=1)
ds4=0;
if(witch[4].live<=2)
dw4=0;
if(witch[4].live<=2&&ai[4].live<=1) {
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
       witch[4].live=sg.nholive;witch[4].mPosX=900;
witch[4].live=100;
dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
        ai[4].live=sg.nholive;ai[4].mPosX=900;
ai[4].live=100;
mandaqua[3]=1;
        start=4.0;
}
//dot.demsoluong(ai[0].live,witch[0].live);
//cout << dot.mPosX << " " << ai.mPosX << " " << dot.skill << endl;
if(ds4)
ai[4].rendermonster();
ds4=1;
//ai[1].renderwitch();
if(dw4)
witch[4].renderwitch(dot.hesotim);
dw4=1;
SDL_Delay(20);

if(dot.hesotim>=119){

        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;

        ai[4].live=sg.nholive;ai[4].mPosX=900;

        start=2.0;
witch[4].live=sg.nholive;witch[4].mPosX=900;
for(int i = 0; i < 10; i++) {
    witch[4].mdan[i]=0;
}

}
}
if (start==3.5) {
witch[5].sodan=5;
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
nhostart=start;
sg.renderbacksword(e,start);

if(dot.hesotim>=120){

       dot.hesotim=0;dot.mPosX=0;

       ai[5].live=sg.nholive;
       ai[5].mPosX=1900;


       witch[5].live=sg.nholive;witch[5].mPosX=900;
       for(int i = 0; i < 10; i++) {
    witch[5].mdan[i]=0;
}
}

dot.tim();


if(dot.danh==0) {
dot.renderMove(e,camera.x,camera.y,nhay);
dot.mskill=0;

}
else{
dot.chem();

ai[5].danh=dot.danh;

witch[5].danh=dot.danh;
Music.danh1=dot.danh;
Music.handleMusic(volume);
}
//ai[1].move();

if(ds5) {
ai[5].sv=dot.v;
ai[5].sPosX=dot.mPosX;
ai[5].sPosY=dot.mPosY;
ai[5].camera=camera;
ai[5].skill=dot.skill;
ai[5].skilly=dot.skilly;
ai[5].move(dot.hesotim);
}

if(dw5) {
witch[5].sPosX=dot.mPosX;
witch[5].sPosY=dot.mPosY;
witch[5].camera=camera;
witch[5].skill=dot.skill;
witch[5].skilly=dot.skilly;
witch[5].move(dot.hesotim);
if(witch[5].checkmusic)
Music.amthanhsung(volume);
}
if(ai[5].live<=1)
ds5=0;
if(witch[5].live<=2)
dw5=0;
if(witch[5].live<=2&&ai[5].live<=1) {
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
       witch[5].live=sg.nholive;witch[5].mPosX=900;
witch[5].live=100;
dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
        ai[5].live=sg.nholive;ai[5].mPosX=900;
ai[4].live=100;

        start=4.0;
}
//dot.demsoluong(ai[0].live,witch[0].live);
//cout << dot.mPosX << " " << ai.mPosX << " " << dot.skill << endl;
if(ds5)
ai[5].rendermonster();
ds5=1;
//ai[1].renderwitch();
if(dw5)
witch[5].renderwitch(dot.hesotim);
dw5=1;
SDL_Delay(20);

if(dot.hesotim>=119){

        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;

        ai[5].live=sg.nholive;ai[5].mPosX=900;

        start=2.0;
witch[5].live=sg.nholive;witch[5].mPosX=900;
for(int i = 0; i < 10; i++) {
    witch[5].mdan[i]=0;
}

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
nhostart=start;
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
Music.handleMusic(volume);
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
if(witch[0].checkmusic)
Music.amthanhsung(volume);
}

dot.demsoluong(ai[0].live,witch[0].live);
//cout << dot.mPosX << " " << ai.mPosX << " " << dot.skill << endl;
if(s1)
ai[0].rendermonster();
//ai[1].renderwitch();
if(w1)
witch[0].renderwitch(dot.hesotim);
SDL_Delay(10);

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
sg.pause(e,start,r,nhostart);
if (r==1)
{
int demman=0;
   dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
if(nhostart==1.0) demman=0;
if(nhostart==3.1) demman=1;
if(nhostart==3.2) demman=2;
if(nhostart==3.3) demman=3;
if(nhostart==3.4) demman=4;
if(nhostart==3.5) demman=5;
        ai[demman].live=sg.nholive;ai[demman].mPosX=900;

    witch[demman].live=sg.nholive;witch[demman].mPosX=900;
    for(int i = 0; i < 10; i++) {
    witch[demman].mdan[i]=0;
}
}
}
if(start==4.0) {

int r=0;
sg.ce(e,start,r);
if (r==1)
{
int demman=0;
   dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
if(nhostart==1.0) demman=0;
if(nhostart==3.1) demman=1;
if(nhostart==3.2) demman=2;
if(nhostart==3.3) demman=3;
if(nhostart==3.4) demman=4;
if(nhostart==3.5) demman=5;
        ai[demman].live=sg.nholive;ai[demman].mPosX=900;

    witch[demman].live=sg.nholive;witch[demman].mPosX=900;
    for(int i = 0; i < 10; i++) {
    witch[demman].mdan[i]=0;
}
}
}
if(start==2.0){
SDL_RenderCopy(renderer,backgroundgameover,NULL,NULL);
SDL_RenderCopy(renderer,gameover,NULL,NULL);

}

SDL_RenderPresent(renderer);

}
video.desvideo();
SDL_DestroyTexture(gameover);
SDL_DestroyTexture(backgroundgameover);
SDL_DestroyTexture(dangload);
SDL_DestroyTexture(dangload1);

dangload1=NULL;
dangload=NULL;
backgroundgameover=NULL;
gameover=NULL;
Music.closeMusic();
quitSDL(window,renderer);
return 0;
}
