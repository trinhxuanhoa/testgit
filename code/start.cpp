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
LTexture am;
LTexture am1;
LTexture am2;
void Startgame::renderbackgroundgame() {
    SDL_Texture*backgroundstartgame=loadTexture(renderer,"startgame/backgroundstartgame.png");
SDL_RenderCopy(renderer,backgroundstartgame,NULL,NULL);
SDL_DestroyTexture(backgroundstartgame);
backgroundstartgame=NULL;
}
void Startgame::rendergamestart(SDL_Event &e, double &start) {
    int k=0;
    int k2=2;
    int k3=4;
startgame[0]=loadTexture(renderer,"startgame/startgame01.png");
startgame[1]=loadTexture(renderer,"startgame/startgame02.png");
startgame[2]=loadTexture(renderer,"startgame/spacegame1.png");
startgame[3]=loadTexture(renderer,"startgame/spacegame2.png");
startgame[4]=loadTexture(renderer,"startgame/music1.png");
startgame[5]=loadTexture(renderer,"startgame/music2.png");
int x,y;
    SDL_GetMouseState(&x,&y);
    if(x>=147&&x<=456&&y>=111&&y<=161&&start==0.0)
    k=1;
    else
    k=0;
if(x>203&&x<392&&y>197&&y<218&&start==0.0)
    k2=3;
  else
  k2=2;
  if(x>247&&x<344&&y>242&&y<263&&start==0.0)
    k3=5;
  else
  k3=4;
  //  cout << x << " " << y << endl;

if(e.type==SDL_MOUSEBUTTONDOWN) {


    if(x>=147&&x<=456&&y>=111&&y<=161&&start==0.0)
               start=3.0;
if(x>203&&x<392&&y>197&&y<218&&start==0.0)
             start=0.1;
 if(x>247&&x<344&&y>242&&y<263&&start==0.0)
   start=0.2;
}
SDL_RenderCopy(renderer,startgame[k],NULL,NULL);
SDL_RenderCopy(renderer,startgame[k2],NULL,NULL);
SDL_RenderCopy(renderer,startgame[k3],NULL,NULL);
for (int i = 0;i < 6;i++) {
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
    if(x>495&&x<586&&y>14&&y<66) {
    k=1;
    }
    else
    k=0;
 if(e.type==SDL_MOUSEBUTTONDOWN) {

 if(x>495&&x<586&&y>14&&y<66)
               start=1.1;
        }
//}

SDL_RenderCopy(renderer,backsword[k],NULL,NULL);
for (int i = 0;i < 2;i++) {
    SDL_DestroyTexture(backsword[i]);
  backsword[i];
}
}
void Startgame::pause(SDL_Event &e ,double &start,int &r,double &nhostart) {
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
 if(x>224&&x<381&&y>152&&y<173)
    k1=4;
    else
    k1=3;
   if(x>277&&x<354&&y>244&&y<265)
    k2=6;
    else
    k2=5;
    SDL_RenderCopy(renderer,backsword[k1],NULL,NULL);
    SDL_RenderCopy(renderer,backsword[k2],NULL,NULL);

    if(e.type==SDL_MOUSEBUTTONDOWN) {
        if(x>224&&x<381&&y>152&&y<173)
        start=nhostart;

        if(x>277&&x<354&&y>244&&y<265) {start=0.0;r=1;}
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

void Startgame::musical(double &start,SDL_Event &e)  {
    int k = 0;
music1[0] = loadTexture(renderer,"startgame/music3.png");
music1[1] = loadTexture(renderer,"startgame/back1.png");
music1[2] = loadTexture(renderer,"startgame/back2.png");
int x,y;
    SDL_GetMouseState(&x,&y);
    if(x>12&&x<85&&y>15&&y<=61&&start==0.2) {
    k=2;
    }
    else
        k=1;
        if(e.type==SDL_MOUSEBUTTONDOWN) {

 if(x>12&&x<85&&y>15&&y<=61&&start==0.2)
               start=0.0;
        }
SDL_RenderCopy(renderer,music1[0],NULL,NULL);
SDL_RenderCopy(renderer,music1[k],NULL,NULL);

for (int i = 0;i < 3;i++) {
SDL_DestroyTexture(music1[i]);
music1[i]= NULL;
}
}
void Startgame::chinh(int &volume, SDL_Event& e) {

amluong[0]=loadTexture(renderer,"startgame/cong.png");
amluong[1]=loadTexture(renderer,"startgame/tru.png");
 int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect a = {400,90,20,20};
SDL_Rect b = {290,100,20,20};
// SDL_Rect c = {400,365,60,20};
if(x>=400&&x<=400+20&&y>=90&&y<90+20)
 a = {390,80,40,40};

  if(x>=290&&x<=290+20&&y>=100&&y<=100+20)
b = {280,90,40,40};
//if(x>400&&x<400+60&&y>365&&y<365+20)
//c = {370,355,120,40};
if(e.type==SDL_MOUSEBUTTONDOWN) {
    if(x>=400&&x<=400+20&&y>=90&&y<90+20)
       volume++;
      if(x>=290&&x<=290+20&&y>=100&&y<=100+20)
       volume--;
      }
if (volume<0)
    volume=0;
if(volume>10)
    volume=10;

SDL_RenderCopy(renderer,amluong[0],NULL,&a);
SDL_RenderCopy(renderer,amluong[1],NULL,&b);
am.rendertext(330,100,volume);
am.rendertext(331,101,volume);
am.rendertext(332,102,volume);
for (int i = 0; i < 2; i++) {
    SDL_DestroyTexture(amluong[i]);
    amluong[i]==NULL;
}
}
void Startgame::chinhnen(int &volume1, SDL_Event& e) {

amluong[0]=loadTexture(renderer,"startgame/cong.png");
amluong[1]=loadTexture(renderer,"startgame/tru.png");
 int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect a = {435,160,20,20};
SDL_Rect b = {325,170,20,20};
// SDL_Rect c = {400,365,60,20};
if(x>=435&&x<=435+20&&y>=160&&y<160+20)
 a = {425,150,40,40};

  if(x>=325&&x<=325+20&&y>=170&&y<=170+20)
b = {315,160,40,40};
//if(x>400&&x<400+60&&y>365&&y<365+20)
//c = {370,355,120,40};
if(e.type==SDL_MOUSEBUTTONDOWN) {
   if(x>=435&&x<=435+20&&y>=160&&y<160+20)
       volume1++;
    if(x>=325&&x<=325+20&&y>=170&&y<=170+20)
       volume1--;
      }
if (volume1<0)
    volume1=0;
if(volume1>10)
    volume1=10;

SDL_RenderCopy(renderer,amluong[0],NULL,&a);
SDL_RenderCopy(renderer,amluong[1],NULL,&b);
am1.rendertext(360,170,volume1);
am1.rendertext(361,171,volume1);
am1.rendertext(362,172,volume1);
for (int i = 0; i < 2; i++) {
    SDL_DestroyTexture(amluong[i]);
    amluong[i]==NULL;
}
}
void Startgame::chinhnhacnen(int &chon, SDL_Event& e) {

amluong[2]=loadTexture(renderer,"startgame/cong.png");
amluong[3]=loadTexture(renderer,"startgame/tru.png");
 int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect a = {350,235,20,20};
SDL_Rect b = {240,245,20,20};
// SDL_Rect c = {400,365,60,20};
if(x>=350&&x<=359+20&&y>=235&&y<235+20)
 a = {340,225,40,40};

  if(x>=240&&x<=240+20&&y>=245&&y<=245+20)
b = {230,230,40,40};

if(e.type==SDL_MOUSEBUTTONDOWN) {
  if(x>=350&&x<=359+20&&y>=235&&y<235+20)
       chon++;
  if(x>=240&&x<=240+20&&y>=245&&y<=245+20)
       chon--;
      }
if (chon<0)
    chon=0;
if(chon>3)
    chon=3;

SDL_RenderCopy(renderer,amluong[2],NULL,&a);
SDL_RenderCopy(renderer,amluong[3],NULL,&b);
am2.rendertext(280,235,chon);
am2.rendertext(281,236,chon);
am2.rendertext(282,237,chon);
for (int i = 2; i < 4; i++) {
    SDL_DestroyTexture(amluong[i]);
    amluong[i]==NULL;
}
}

void Startgame::chon(SDL_Event &e,double&start,int mandaqua[]) {
    int k = 2;
    chedo[0]=loadTexture(renderer,"startgame/capdo1.png");
    chedo[1]=loadTexture(renderer,"startgame/capdospace.png");
    chedo[2]=loadTexture(renderer,"startgame/backs1.png");
    chedo[3]=loadTexture(renderer,"startgame/backs2.png");
    chedo[4]=loadTexture(renderer,"startgame/khoa.png");



    SDL_QueryTexture(chedo[1],NULL,NULL,&sx,&sy);
     SDL_QueryTexture(chedo[4],NULL,NULL,&kx,&ky);
    int x1= (600-sx)/2;
    int y1= 240;
    SDL_Rect a = {(600-sx)/2,240,sx,sy};
    SDL_Rect ka1={167,161,kx,ky};
    SDL_Rect ka2={273,161,kx,ky};
    SDL_Rect ka3={380,161,kx,ky};
    SDL_Rect ka4={486,161,kx,ky};
    int x, y;
      SDL_GetMouseState(&x,&y);
    if(x>=x1&&x<=x1+sx&&y>=y1&&y<=y1+sy)
        a = {x1-sx*0.25,y1-sy*0.25,sx*1.5,sy*1.5};
    if(x>15&&x<106&&y>14&&y<65)
        k=3;
        else k =2;
    if(e.type==SDL_MOUSEBUTTONDOWN) {
       if(x>=x1&&x<=x1+sx&&y>=y1&&y<=y1+sy) start=1.0;
     if(x>15&&x<106&&y>14&&y<65) start=0.0;
        if(x>=62&&x<=62+51&&y>=161&&y<=212) start=3.1;
        if(x>=167&&x<=167+51&&y>=161&&y<=212&&mandaqua[0]) start=3.2;
        if(x>=273&&x<=273+51&&y>=161&&y<=212&&mandaqua[1]) start=3.3;
         if(x>=380&&x<=380+51&&y>=161&&y<=212&&mandaqua[2]) start=3.4;
          if(x>=486&&x<=486+51&&y>=161&&y<=212&&mandaqua[3]) start=3.5;
    }


    SDL_RenderCopy(renderer,chedo[0],NULL,NULL);
    SDL_RenderCopy(renderer,chedo[1],NULL,&a);
    SDL_RenderCopyEx(renderer,chedo[k],NULL,NULL,0.0,NULL,SDL_FLIP_HORIZONTAL);
    if(!mandaqua[0])
    SDL_RenderCopy(renderer,chedo[4],NULL,&ka1);
     if(!mandaqua[1])
     SDL_RenderCopy(renderer,chedo[4],NULL,&ka2);
      if(!mandaqua[2])
      SDL_RenderCopy(renderer,chedo[4],NULL,&ka3);
       if(!mandaqua[3])
       SDL_RenderCopy(renderer,chedo[4],NULL,&ka4);
    for(int i=0; i < 5; i++) {
    SDL_DestroyTexture(chedo[i]);
    chedo[i]=NULL;
    }
}
void Startgame::ce(SDL_Event &e ,double &start,int &r) {
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
 if(x>224&&x<381&&y>152&&y<173)
    k1=4;
    else
    k1=3;
   if(x>277&&x<354&&y>244&&y<265)
    k2=6;
    else
    k2=5;
    SDL_RenderCopy(renderer,backsword[k1],NULL,NULL);
    SDL_RenderCopy(renderer,backsword[k2],NULL,NULL);

    if(e.type==SDL_MOUSEBUTTONDOWN) {
        if(x>224&&x<381&&y>152&&y<173)
        start=3.0;

        if(x>277&&x<354&&y>244&&y<265) {start=0.0;r=1;}
}
for (int i = 2;i < 7;i++) {
    SDL_DestroyTexture(backsword[i]);
  backsword[i];
}
}
void Startgame::tutorial(SDL_Event &e,double &start) {
    int k = 0;
tu[0]=loadTexture(renderer,"startgame/tutorial1.png");
tu[1]=loadTexture(renderer,"startgame/tutorial2.png");
int x,y;
SDL_GetMouseState(&x,&y);
if(x>219&&x<380&&y>283&&y<304)
    k=1;
    if(e.type==SDL_MOUSEBUTTONDOWN) {
      if(x>219&&x<380&&y>283&&y<304) start=0.3;
    }
SDL_RenderCopy(renderer,tu[k],NULL,NULL);
for(int i = 0; i < 2; i++) {
    SDL_DestroyTexture(tu[i]);
    tu[i]=NULL;
}
}
LTexture hd[5];
void Startgame::tt(SDL_Event &e,double &start) {
    int k = 5;
     chedo[5]=loadTexture(renderer,"startgame/backs1.png");
    chedo[6]=loadTexture(renderer,"startgame/backs2.png");
SDL_Texture*tuo=loadTexture(renderer,"startgame/tutorial.png");
int x, y;
SDL_GetMouseState(&x,&y);
if(x>15&&x<106&&y>14&&y<65)
        k=6;
        else k =5;
if(e.type==SDL_MOUSEBUTTONDOWN) {
    if(x>15&&x<106&&y>14&&y<65) start=0.0;
}

SDL_RenderCopy(renderer,tuo,NULL,NULL);
hd[0].rendertexttutorial(40,80,"Press right to move right");
hd[1].rendertexttutorial(40,120,"press left to move left");
hd[2].rendertexttutorial(40,160,"press up to jump");
hd[3].rendertexttutorial(40,200,"press down+up to jump higher");
hd[4].rendertexttutorial(40,240,"press space to attack");
 SDL_RenderCopyEx(renderer,chedo[k],NULL,NULL,0.0,NULL,SDL_FLIP_HORIZONTAL);
SDL_DestroyTexture(tuo);
tuo=NULL;
for(int i = 5; i < 7;i++) {
    SDL_DestroyTexture(chedo[i]);
    chedo[i]=NULL;
}
}
