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
extern SDL_Renderer* renderer;
LTexture so;
LTexture sod;
void Startgame::renderbackgroundgame() {
    SDL_Texture*backgroundstartgame=loadTexture(renderer,"startgame/backgroundstartgame.png");
SDL_RenderCopy(renderer,backgroundstartgame,NULL,NULL);
SDL_DestroyTexture(backgroundstartgame);
backgroundstartgame=NULL;
}
void Startgame::rendergamestart(SDL_Event &e, double &start) {
    int k=0;
    int k2=2;
startgame[0]=loadTexture(renderer,"startgame/startgame01.png");
startgame[1]=loadTexture(renderer,"startgame/startgame02.png");
startgame[2]=loadTexture(renderer,"startgame/spacegame1.png");
startgame[3]=loadTexture(renderer,"startgame/spacegame2.png");

int x,y;
    SDL_GetMouseState(&x,&y);
    if(x>=147&&x<=456&&y>=111&&y<=161&&start==0.0) {
    k=1;

    }

    else
        k=0;
if(x>203&&x<392&&y>197&&y<218&&start==0.0) {
    k2=3;
    }
  else
  k2=2;
  //  cout << x << " " << y << endl;

if(e.type==SDL_MOUSEBUTTONDOWN) {


    if(x>=147&&x<=456&&y>=111&&y<=161&&start==0.0)
               start=1.0;
if(x>203&&x<392&&y>197&&y<218&&start==0.0)
             start=0.1;
}
SDL_RenderCopy(renderer,startgame[k],NULL,NULL);
SDL_RenderCopy(renderer,startgame[k2],NULL,NULL);
for (int i = 0;i < 4;i++) {
SDL_DestroyTexture(startgame[i]);
startgame[i]= NULL;
}
}

void Startgame::spacegame(SDL_Event &e ,double &start) {
    int k = 0;
spacegames[0] = loadTexture(renderer,"startgame/spacegame.png");
spacegames[1] = loadTexture(renderer,"startgame/back1.png");
spacegames[2] = loadTexture(renderer,"startgame/back2.png");
int x,y;
    SDL_GetMouseState(&x,&y);
    if(x>12&&x<85&&y>15&&y<=61&&start==0.1) {
    k=2;
    }
    else
        k=1;
        if(e.type==SDL_MOUSEBUTTONDOWN) {

 if(x>12&&x<85&&y>15&&y<=61&&start==0.1)
               start=0.0;
        }
SDL_RenderCopy(renderer,spacegames[0],NULL,NULL);
SDL_RenderCopy(renderer,spacegames[k],NULL,NULL);

for (int i = 0;i < 3;i++) {
SDL_DestroyTexture(spacegames[i]);
spacegames[i]= NULL;
}
}
void Startgame::renderbacksword (SDL_Event &e ,double &start) {
  int k=0;

backsword[0]=loadTexture(renderer,"startgame/backs1.png");
backsword[1]=loadTexture(renderer,"startgame/backs2.png");

//if(SDL_PollEvent(&e)!=0) {
int x,y;
    SDL_GetMouseState(&x,&y);
    if(x>495&&x<586&&y>14&&y<66&&start==1.0) {
    k=1;
    }
    else
    k=0;
 if(e.type==SDL_MOUSEBUTTONDOWN) {

 if(x>495&&x<586&&y>14&&y<66&&start==1.0)
               start=1.1;
        }
//}

SDL_RenderCopy(renderer,backsword[k],NULL,NULL);
for (int i = 0;i < 2;i++) {
    SDL_DestroyTexture(backsword[i]);
  backsword[i];
}
}
void Startgame::pause(SDL_Event &e ,double &start,int &r) {
int k1=3;
int k2=5;
backsword[2]=loadTexture(renderer,"startgame/pause.png");
backsword[3]=loadTexture(renderer,"startgame/continue1.png");
backsword[4]=loadTexture(renderer,"startgame/continue2.png");
backsword[5]=loadTexture(renderer,"startgame/exit1.png");
backsword[6]=loadTexture(renderer,"startgame/exit2.png");
SDL_RenderCopy(renderer,backsword[2],NULL,NULL);
int x,y;
    SDL_GetMouseState(&x,&y);
 if(x>224&&x<381&&y>152&&y<173&&start==1.1)
    k1=4;
    else
    k1=3;
   if(x>277&&x<354&&y>244&&y<265&&start==1.1)
    k2=6;
    else
    k2=5;
    SDL_RenderCopy(renderer,backsword[k1],NULL,NULL);
    SDL_RenderCopy(renderer,backsword[k2],NULL,NULL);

    if(e.type==SDL_MOUSEBUTTONDOWN) {
        if(x>224&&x<381&&y>152&&y<173&&start==1.1) start=1.0;
        if(x>277&&x<354&&y>244&&y<265&&start==1.1) {start=0.0;r=1;}
    }
for (int i = 2;i < 7;i++) {
    SDL_DestroyTexture(backsword[i]);
  backsword[i];
}
}
void Startgame::hp1(SDL_Event &e ,double &start,int &live,int &sodan) {
int k1=0;
int k2=1;
hpm[0]=loadTexture(renderer,"startgame/cong.png");
hpm[1]=loadTexture(renderer,"startgame/tru.png");


int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect a = {470,100,20,20};
SDL_Rect b = {280,110,20,20};
 SDL_Rect a1 = {470,294,20,20};
SDL_Rect b1 = {280,313,20,20};
if(x>470&&x<470+20&&y>100&&y<100+20&&start==0.1)
 a = {460,90,40,40};

  if(x>280&&x<280+20&&y>100&&y<110+20&&start==0.1)
b = {270,100,40,40};

    if(x>470&&x<470+20&&y>294&&y<294+20&&start==0.1)
 a1 = {460,284,40,40};

  if(x>280&&x<280+20&&y>313&&y<313+20&&start==0.1)
b1 = {270,303,40,40};

    SDL_RenderCopy(renderer,hpm[k1],NULL,&a);
    SDL_RenderCopy(renderer,hpm[k2],NULL,&b);
SDL_RenderCopy(renderer,hpm[k1],NULL,&a1);
    SDL_RenderCopy(renderer,hpm[k2],NULL,&b1);
switch (e.type) {
        case SDL_MOUSEBUTTONDOWN:

                mouseButtonPressed = true;

            break;
        case SDL_MOUSEBUTTONUP:

                mouseButtonPressed = false;

            break;

    }

            if (mouseButtonPressed ) {
                if(x>470&&x<470+20&&y>100&&y<100+20&&start==0.1) live++;
        if(x>280&&x<280+20&&y>100&&y<110+20&&start==0.1) live--;
        if(x>470&&x<470+20&&y>294&&y<294+20&&start==0.1) sodan++;
         if(x>280&&x<280+20&&y>313&&y<313+20&&start==0.1) sodan--;
            }

if(live<=1) live=1;
if(live>999999)live=999999;
if(sodan<=1) sodan=1;
if(sodan>=10) sodan=10;
so.rendertext(310,100,live);
so.rendertext(311,101,live);
so.rendertext(312,102,live);
sod.rendertext(310,302,sodan);
sod.rendertext(311,303,sodan);
sod.rendertext(312,304,sodan);
for (int i = 0;i < 2;i++) {
    SDL_DestroyTexture(hpm[i]);
  hpm[i];
}
nholive=live;
}

void Startgame::sw(bool &xske,bool &sw,bool &wn,SDL_Event &e) {

int static k1=2;
int static k2=2;
int static k3=3;

hpm[2]=loadTexture(renderer,"startgame/yes.png");
hpm[3]=loadTexture(renderer,"startgame/no.png");
 int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect a = {400,160,60,20};
SDL_Rect b = {400,230,60,20};
 SDL_Rect c = {400,365,60,20};
if(x>400&&x<400+60&&y>160&&y<160+20)
 a = {370,150,120,40};

  if(x>400&&x<400+60&&y>230&&y<230+20)
b = {370,220,120,40};
if(x>400&&x<400+60&&y>365&&y<365+20)
c = {370,355,120,40};


if(e.type==SDL_MOUSEBUTTONDOWN&&e.button.button==SDL_BUTTON_LEFT) {
      if(x>400&&x<400+60&&y>160&&y<160+20) {
        if(k1==2)
        {k1=3;xske=false;}
      else
        {k1=2;xske=true;}
        if(k1==3&&k2==3)
{

    k2=2;sw=true;
}
}
     if(x>400&&x<400+60&&y>230&&y<230+20)  {
        if(k2==2)
       {k2=3;sw=false;}
        else
       {k2=2;sw=true;}
       if(k1==3&&k2==3)
{
    k1=2;xske=true;

}
      }
if(x>400&&x<400+60&&y>365&&y<365+20){
        if(k3==2)
        {k3=3;wn=false;}
      else
        {k3=2;wn=true;}

    }
}
    SDL_RenderCopy(renderer,hpm[k1],NULL,&a);
    SDL_RenderCopy(renderer,hpm[k2],NULL,&b);
     SDL_RenderCopy(renderer,hpm[k3],NULL,&c);
    for (int i = 2;i < 4;i++) {
    SDL_DestroyTexture(hpm[i]);
  hpm[i];
}
}
