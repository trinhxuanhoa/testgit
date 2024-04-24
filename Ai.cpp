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
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
LTexture re[2];
LTexture wi[2];
bool vachamdan(int danx,int dany,int hd,int wd);
void Ai::move(int &hesotim)
{

dieukhien(hesotim);


if(abs(sPosX-mPosX)<=100&&sPosY<mPosY) mVelY=1;
    mPosX += mVelX;
    collx=mPosX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + 90> LEVEL_WIDTH )||vacham1(collx,colly)||vacham2(collx,colly)
       ||vacham3(collx,colly)||vacham4(collx,colly)||vacham5(collx,colly)||vacham6(collx,colly)
       ||vacham7(collx,colly)||vacham8(collx,colly)||vacham9(collx,colly)||vacham10(collx,colly))
    {
        mPosX -= mVelX;
        collx=mPosX;
        mVelY=1;
    }


if(mPosX<68&&flip==SDL_FLIP_NONE) mVelY=0;
    if(mVelY>0&&v==0) {
          if(sv==0) v=18;
else v=sv;

    if(mPosX==1104||mPosX==1200||mPosX==264||mPosX==1998||mPosX==2067||mPosX==2214||mPosX==2280||mPosX==1737||mPosX==2310||mPosX==2385) v = 24;
    }

    if(v!=0||t!=0) {
double s=0.5*g*t*t-v*t;
t+=1;
mPosY+=-s+0.5*g*t*t-v*t;

colly=mPosY;

}
colly=mPosY;
//cout << g << " " << v << endl;

if(vachamsan(collx,colly)){
        v=0;t=0;
    mPosY=330;   mVelY=0;
    colly=mPosY;}

   if( vacham1(collx,colly))
    {
       mPosY=290-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
 if( vacham2(collx,colly))
    {
       mPosY=223-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
    if( vacham3(collx,colly))
    {
       mPosY=325-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
    if( vacham4(collx,colly))
    {
       mPosY=147-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }

if( vacham5(collx,colly))
    {
       mPosY=250-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
if( vacham6(collx,colly))
    {
       mPosY=146-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
if( vacham7(collx,colly))
    {
       mPosY=291-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }

if( vacham8(collx,colly))
    {
       mPosY=213-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
if( vacham9(collx,colly))
    {
       mPosY=212-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
if( vacham10(collx,colly))
    {
       mPosY=224-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }

}
bool Ai::vachamsan(int collx,int colly) {
 bool k = true;



if (colly<330)
k = false;

return k;
}

bool Ai::vacham1(int collx,int colly) {

    bool k = true;

if (collx<=68)
{k= false;if(mPosY==290-90&&v==0) t = 20;}

if(collx>=192)
   {k=false;if(mPosY==290-90&&v==0) t = 20;}

 if (collx<192&&colly+h<=290)
k= false;

return k;
}

bool Ai::vacham2(int collx,int colly) {

    bool k = true;

if (collx<=266)
{k= false;if(mPosY==223-90&&v==0) t = 20;}

if(collx>=638)
   {k=false;if(mPosY==223-90&&v==0) t = 20;}

 if (collx<638&&colly+h<=223)
k= false;

return k;
}

bool Ai::vacham3(int collx,int colly) {

    bool k = true;

if (collx<=636)
{k= false;if(mPosY==325-90&&v==0) t = 20;}

if(collx>=768)
   {k=false;if(mPosY==325-90&&v==0) t = 20;}

 if (collx<768&&colly+h<=325)
k= false;

return k;
}


bool Ai::vacham4(int collx,int colly) {

    bool k = true;

if (collx<=1106)
{k= false;if(mPosY==147-90&&v==0) t = 20;}

if(collx>=1200)
   {k=false;if(mPosY==147-90&&v==0) t = 20;}

 if (collx<1200&&colly+h<=147)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}
bool Ai::vacham5(int collx,int colly) {

    bool k = true;

if (collx<=1516)
{k= false;if(mPosY==250-90&&v==0) t = 20;}

if(collx>=1656)
   {k=false;if(mPosY==250-90&&v==0) t = 20;}

 if (collx<1656&&colly+h<=250)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}


bool Ai::vacham6(int collx,int colly) {

    bool k = true;

if (collx<=1632)
{k= false;if(mPosY==146-90&&v==0) t = 20;}

if(collx>=1736)
   {k=false;if(mPosY==146-90&&v==0) t = 20;}

 if (collx<1736&&colly+h<=146)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Ai::vacham7(int collx,int colly) {

    bool k = true;

if (collx<=1832)
{k= false;if(mPosY==291-90&&v==0) t = 20;}

if(collx>=1896)
   {k=false;if(mPosY==291-90&&v==0) t = 20;}

 if (collx<1896&&colly+h<=291)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Ai::vacham8(int collx,int colly) {

    bool k = true;

if (collx<=2000)
{k= false;if(mPosY==213-90&&v==0) t = 20;}

if(collx>=2066)
   {k=false;if(mPosY==213-90&&v==0) t = 20;}

 if (collx<2066&&colly+90<=213)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Ai::vacham9(int collx,int colly) {

    bool k = true;

if (collx<=2216)
{k= false;if(mPosY==212-90&&v==0) t = 20;}

if(collx>=2280)
   {k=false;if(mPosY==212-90&&v==0) t = 20;}

 if (collx<2280&&colly+90<=212) {

k= false;}

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Ai::vacham10(int collx,int colly) {

    bool k = true;

if (collx<=2310)
{k= false;if(mPosY==224-90&&v==0) t = 20;}

if(collx>=2384)
   {k=false;if(mPosY==224-90&&v==0) t = 20;}

 if (collx<2384&&colly+h<=224)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

void Ai::rendermonster() {

  skeleton[0]=loadTexture(renderer,"monster/skeleton1.1.png");
skeleton[1]=loadTexture(renderer,"monster/skeleton1.2.png");
//cout << mPosX << endl;

 int x =0;
static int ske = 0;
ske++;
if(ske>11) ske = 0;
//cout << mPosX << endl;
if(flip==SDL_FLIP_NONE)
 x = mPosX;
if(flip==SDL_FLIP_HORIZONTAL)
x = mPosX+50;
 SDL_Rect skeleton1 = {x-camera.x,mPosY-camera.y,100,90};
 //cout << live << endl;
 if(live>0){
    SDL_RenderCopyEx(renderer,skeleton[ske/6],NULL,&skeleton1,0.0,NULL,flip);
   re[0].rendertext(mPosX +45-camera.x,mPosY-10-camera.y,live);
for (int i =0;i<2;i++){
    SDL_DestroyTexture(skeleton[i]);
    skeleton[i]=NULL;
   }
}
else
{mPosX=900;live=sg.nholive;}
}


void Ai::dieukhien(int &hesotim) {

    if(sPosX-38<=mPosX) {
         //   if(sPosY+90>=mPosY&&sPosY-70<=mPosY&&abs(mPosX-sPosX)<100&&danh>0)
   // live--;
    flip=SDL_FLIP_NONE;
     if(mVelY==0) mVelX=-vm;
if(sPosX+28>=mPosX&&sPosX-38<=mPosX&&sPosY+50>=mPosY&&sPosY-30<=mPosY)
   {hesotim++;mVelX=0;mVelY=0;}
  if(skilly+89>=mPosY&&skilly<=mPosY+90&&skill+80>mPosX&&skill<mPosX+80&&danh>0)
    live--;
  }
 else if(sPosX-94>=mPosX) {
       // if(sPosY+90>=mPosY&&sPosY-70<=mPosY&&abs(mPosX-sPosX)<150&&danh>0)
    //live--;
    flip=SDL_FLIP_HORIZONTAL;
   if(mVelY==0) mVelX=vm;
if(sPosX-94>=mPosX&&sPosX-136<=mPosX&&sPosY+50>=mPosY&&sPosY-30<=mPosY)
    {hesotim++;mVelX=0;mVelY=0;}
    if(skilly+89>=mPosY&&skilly<=mPosY+90&&skill<mPosX+80&&skill+80>mPosX&&danh>0)
    live--;
  }
else {
        if(skilly+89>=mPosY&&skilly<=mPosY+90&&skill+80>mPosX&&skill<mPosX+80&&danh>0)
    live--;
if(skilly+89>=mPosY&&skilly<=mPosY+90&&skill<mPosX-80&&skill+80>mPosX&&danh>0)
    live--;
    if( flip==SDL_FLIP_HORIZONTAL&&mVelY==0) {
        mVelX=vm;

    }
    if( flip==SDL_FLIP_NONE&&mVelY==0) {
        mVelX=-vm;

    }
}
if (sPosX>=1267&&sPosX<=1575&&sPosY+90>300)
        hesotim++;
}
void Ai::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	/*if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {

            case SDLK_a: mVelX -= 2;flip=SDL_FLIP_NONE;break;
            case SDLK_d: mVelX += 2;flip=SDL_FLIP_HORIZONTAL;break;
            case SDLK_w: mVelY+=1;break;

            case SDLK_s: nhaycao+=1 ;break;

        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_a: mVelX += 2;break;
            case SDLK_d: mVelX -= 2; break;
             case SDLK_w: mVelY-=1;break;

             case SDLK_s: nhaycao-=1 ;break;
             // case SDLK_a: danh -=1;break;
        }
    }*/
}




void Witch::move(int &hesotim)
{
if(vachamdan(skill,skilly,90,80))
    vachamskill=true;
dieukhien(hesotim);


if(wn&&sPosY<mPosY) mVelY=1;
    mPosX += mVelX;
    collx=mPosX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + 90> LEVEL_WIDTH )||vacham1(collx,colly)||vacham2(collx,colly)
       ||vacham3(collx,colly)||vacham4(collx,colly)||vacham5(collx,colly)||vacham6(collx,colly)
       ||vacham7(collx,colly)||vacham8(collx,colly)||vacham9(collx,colly)||vacham10(collx,colly))
    {
        mPosX -= mVelX;
        collx=mPosX;
        mVelY=1;
    }


//if(mPosX<60&&flip==SDL_FLIP_NONE) mVelY=0;

    if(mVelY>0&&v==0) {
        if(wn) {
         if(sv==0) v=24;
else  v=sv;
        }
v=24;
    if(mPosX==264||mPosX==1104||mPosX==1200||mPosX==1736||mPosX==2000||mPosX==2068||mPosX==2216||mPosX==2280||mPosX==2308||mPosX==2384) v = 24;
    }

    if(v!=0||t!=0) {
double s=0.5*g*t*t-v*t;
t+=1;
mPosY+=-s+0.5*g*t*t-v*t;

colly=mPosY;

}
colly=mPosY;
//cout << g << " " << v << endl;

if(vachamsan(collx,colly)){
        v=0;t=0;
    mPosY=330;   mVelY=0;
    colly=mPosY;}

   if( vacham1(collx,colly))
    {
       mPosY=290-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
 if( vacham2(collx,colly))
    {
       mPosY=223-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
    if( vacham3(collx,colly))
    {
       mPosY=325-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
    if( vacham4(collx,colly))
    {
       mPosY=147-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }

if( vacham5(collx,colly))
    {
       mPosY=250-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
if( vacham6(collx,colly))
    {
       mPosY=146-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
if( vacham7(collx,colly))
    {
       mPosY=291-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }

if( vacham8(collx,colly))
    {
       mPosY=213-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
if( vacham9(collx,colly))
    {
       mPosY=212-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }
if( vacham10(collx,colly))
    {
       mPosY=224-90;
       colly=mPosY;mVelY=0;
       v=0;t=0;
    }

}
bool Witch::vachamsan(int collx,int colly) {
 bool k = true;



if (colly<330)
k = false;

return k;
}

bool Witch::vacham1(int collx,int colly) {

    bool k = true;

if (collx<=60)
{k= false;if(mPosY==290-90&&v==0) t = 20;}

if(collx>=192)
   {k=false;if(mPosY==290-90&&v==0) t = 20;}

 if (collx<192&&colly+h<=290)
k= false;

return k;
}

bool Witch::vacham2(int collx,int colly) {

    bool k = true;

if (collx<=266)
{k= false;if(mPosY==223-90&&v==0) t = 20;}

if(collx>=638)
   {k=false;if(mPosY==223-90&&v==0) t = 20;}

 if (collx<638&&colly+h<=223)
k= false;

return k;
}

bool Witch::vacham3(int collx,int colly) {

    bool k = true;

if (collx<=636)
{k= false;if(mPosY==325-90&&v==0) t = 20;}

if(collx>=768)
   {k=false;if(mPosY==325-90&&v==0) t = 20;}

 if (collx<768&&colly+h<=325)
k= false;

return k;
}


bool Witch::vacham4(int collx,int colly) {

    bool k = true;

if (collx<=1106)
{k= false;if(mPosY==147-90&&v==0) t = 20;}

if(collx>=1200)
   {k=false;if(mPosY==147-90&&v==0) t = 20;}

 if (collx<1200&&colly+h<=147)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}
bool Witch::vacham5(int collx,int colly) {

    bool k = true;

if (collx<=1516)
{k= false;if(mPosY==250-90&&v==0) t = 20;}

if(collx>=1656)
   {k=false;if(mPosY==250-90&&v==0) t = 20;}

 if (collx<1656&&colly+h<=250)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}


bool Witch::vacham6(int collx,int colly) {

    bool k = true;

if (collx<=1632)
{k= false;if(mPosY==146-90&&v==0) t = 20;}

if(collx>=1736)
   {k=false;if(mPosY==146-90&&v==0) t = 20;}

 if (collx<1736&&colly+h<=146)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Witch::vacham7(int collx,int colly) {

    bool k = true;

if (collx<=1832)
{k= false;if(mPosY==291-90&&v==0) t = 20;}

if(collx>=1896)
   {k=false;if(mPosY==291-90&&v==0) t = 20;}

 if (collx<1896&&colly+h<=291)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Witch::vacham8(int collx,int colly) {

    bool k = true;

if (collx<=2000)
{k= false;if(mPosY==213-90&&v==0) t = 20;}

if(collx>=2066)
   {k=false;if(mPosY==213-90&&v==0) t = 20;}

 if (collx<2066&&colly+90<=213)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Witch::vacham9(int collx,int colly) {

    bool k = true;

if (collx<=2216)
{k= false;if(mPosY==212-90&&v==0) t = 20;}

if(collx>=2280)
   {k=false;if(mPosY==212-90&&v==0) t = 20;}

 if (collx<2280&&colly+90<=212) {

k= false;}

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Witch::vacham10(int collx,int colly) {

    bool k = true;

if (collx<=2310)
{k= false;if(mPosY==224-90&&v==0) t = 20;}

if(collx>=2384)
   {k=false;if(mPosY==224-90&&v==0) t = 20;}

 if (collx<2384&&colly+h<=224)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}


bool vachamdan(int danx,int dany,int hd,int wd)  {

int k = true;
if(dany+hd>97*3) {
if(danx+wd>52*3&&danx<84*3) {k=false;
//cout << "1" << endl;
}
}
if(dany+hd>74*3) {
if(danx+wd>118*3&&danx<233*3) {k= false;
//cout << "2" << endl;
}
}
if(dany+hd>108*3) {
if(danx+wd>233*3&&danx<277*3)  {k= false;

}
}
if(dany+hd>49*3) {
if(danx+wd>400*3&&danx<422*3) {k= false;}

}
if(dany+hd>84*3) {
if(danx+wd>535*3&&danx<574*3) {k= false;}

}
if(dany+hd>49*3) {
if(danx+wd>574*3&&danx<601*3) {k= false;}


}
if(dany+hd>96*3) {
if(danx+wd>639*3&&danx<653*3) {k= false;}


}
if(dany+hd>70*3) {
if(danx+wd>695*3&&danx<710*3) {k= false;}

}
if(dany+hd>70*3) {
if(danx+wd>766*3&&danx<782*3) {k= false;}

}
if(dany+hd>74*3) {
if((danx+wd>799*3||danx+30>987*3)&&danx<815*3) {k= false;}


}
return k;
}
void Witch::renderwitch(int &hesotim) {
  skeleton[2]=loadTexture(renderer,"monster/witch1.png");
//cout << mPosX << endl;


int x;
//cout << mPosX << endl;
if(flip==SDL_FLIP_NONE)
 x = mPosX;
if(flip==SDL_FLIP_HORIZONTAL)
x = mPosX+50;
 SDL_Rect skeleton1 = {x-camera.x,mPosY-camera.y,100,90};
 //cout << live << endl;
 if(live>0){
    SDL_RenderCopyEx(renderer,skeleton[2],NULL,&skeleton1,0.0,NULL,flip);
   wi[0].rendertext(mPosX +50-camera.x,mPosY-30-camera.y,live);

   dan(hesotim);

}
else
{mPosX=vitri;live=sg.nholive;}
SDL_DestroyTexture(skeleton[2]);
    skeleton[2]=NULL;
}

void Witch::dan(int &hesotim) {

SDL_Texture*dan1=loadTexture(renderer,"monster/dan.png");
SDL_Rect danak[10];
checkmusic=false;
if(mdan[0]==0)
checkmusic=true;


//cout << checkmusic << " " <<mdan[0] << endl;
for(int i =0; i < sodan; i++) {

if(dau[i]==0) {

if(smflip[i]==SDL_FLIP_NONE) {
    Mdan[i]=lanX[i]-10-mdan[i];
    if(Mdan[i]<=sPosX+30&&Mdan[i]>=sPosX+20&&lanY[i]+40+7>sPosY&&lanY[i]+40<sPosY+90)
        {hesotim+=5;dau[i]=1;}

}
else {
    Mdan[i]=lanX[i]+140+mdan[i];
     if(Mdan[i]+30>=sPosX&&Mdan[i]<=sPosX+20&&lanY[i]+40+7>sPosY&&lanY[i]+40<sPosY+90)
        {hesotim+=5;dau[i]=1;}
}
}

if(mdan[i]==0) {lanX[i]=mPosX;lanY[i]=mPosY;smflip[i]=flip;}
if(i==0||mdan[i-1]>=60||mdan[i]!=0) {

       if(!vachamdan(Mdan[i],lanY[i]+40,7,30)) {dau[i]=1;}
       if(dau[i]==0) {
 danak[i]= {Mdan[i]-camera.x,lanY[i]-camera.y+40,30,7};
SDL_RenderCopyEx(renderer,dan1,NULL,&danak[i],0.0,NULL,smflip[i]);
       }
//cout << mdan[i] <<" " << dau[i] << endl;
mdan[i]+=10;

}
if(mdan[i]>=400) {mdan[i]=0;dau[i]=0;}
}

SDL_DestroyTexture(dan1);
dan1=NULL;
}
void Witch::dieukhien(int &hesotim) {


if(sPosX+210<=mPosX) {

        flip=SDL_FLIP_NONE;
        mVelX=-vm;

         if(skilly+89>=mPosY&&skilly<=mPosY+90&&skill+80>mPosX&&skill<mPosX+80&&danh>0)
    live--;


}
else if(sPosX>=mPosX+300) {

         flip=SDL_FLIP_HORIZONTAL;
         mVelX=vm;

         if(skilly+89>=mPosY&&skilly<=mPosY+90&&skill<mPosX-80&&skill+80>mPosX&&danh>0)
    live--;
}
else {
 if(skilly+89>=mPosY&&skilly<=mPosY+90&&skill+80>mPosX&&skill<mPosX+80&&danh>0)
    live--;
    if(skilly+89>=mPosY&&skilly<=mPosY+90&&skill<mPosX+80&&skill+80>mPosX&&danh>0)
    live--;
if( flip==SDL_FLIP_NONE){
    //if(sPosY+90>=mPosY&&sPosY-70<=mPosY&&abs(mPosX-sPosX)<100&&danh>0)
    //live--;
mVelX=vm;
if(sPosX>=mPosX+50)
flip=SDL_FLIP_HORIZONTAL;
//cout << sPosX << " " << mPosX << endl;
if(abs(mPosX-sPosX)<210&&abs(mPosX-sPosX)>204)
    mVelX=0;
}
if(flip==SDL_FLIP_HORIZONTAL) {
        //if(sPosY+90>=mPosY&&sPosY-70<=mPosY&&abs(mPosX-sPosX)<150&&danh>0&&sflip==flip)
    //live--;

         mVelX=-vm;
if(sPosX-20<=mPosX)
    flip=SDL_FLIP_NONE;
if(abs(mPosX-sPosX)<300&&abs(mPosX-sPosX)>290)
mVelX=0;
}
}
if(mPosX<=120) {daudau=true;mVelY=1;}
if(mPosX>400) daudau=false;
if(daudau) mVelX=vm;
}
void Witch::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {

            case SDLK_a: mVelX -= 4;flip=SDL_FLIP_NONE;break;
            case SDLK_d: mVelX += 4;flip=SDL_FLIP_HORIZONTAL;break;
            case SDLK_w: mVelY+=1;break;

            case SDLK_s: nhaycao+=1 ;break;

        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_a: mVelX += 4;break;
            case SDLK_d: mVelX -= 4; break;
             case SDLK_w: mVelY-=1;break;

             case SDLK_s: nhaycao-=1 ;break;
             // case SDLK_a: danh -=1;break;
        }
    }
}













