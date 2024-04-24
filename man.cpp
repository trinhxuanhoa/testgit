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


/*if(start==3.1) {
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

//cout << ai[0].live << endl;
if(ai[0].live<=1) {
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
       witch[2].live=sg.nholive;witch[2].mPosX=900;
witch[2].live=100;
        start=3.0;
}

witch[2].move(dot.hesotim);
//dot.demsoluong(ai[1].live,witch[1].live);
witch[2].renderwitch(dot.hesotim);
SDL_Delay(20);

if(dot.hesotim>=119){
        dot.hesotim=0;dot.mPosX=0;dot.mPosY=330;
       witch[2].live=sg.nholive;witch[2].mPosX=900;
        start=2.0;
}
}
*/
