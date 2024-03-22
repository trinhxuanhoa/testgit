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

using namespace std;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

void Ai::move()
{if (abs(sPosX-mPosX)<=400) {
  if(sPosX+20<mPosX) {
    flip=SDL_FLIP_NONE;
    mVelX=-3;

  }
 if(sPosX-150>mPosX) {
    flip=SDL_FLIP_HORIZONTAL;
    mVelX=3;
  }
}
else mVelX=0;

  if(sPosY==mPosY) {
  if(sPosX-28<=mPosX&&sPosX+38>=mPosX&&flip==SDL_FLIP_NONE) {hesotim++;mVelX=0;}
  if(sPosX-87>=mPosX&&sPosX-136<=mPosX&&flip==SDL_FLIP_HORIZONTAL) {hesotim++;mVelX=0;}
  }
   if (sPosX>=1267&&sPosX<=1575&&sPosY+90>300)
        hesotim++;
    mPosX += mVelX;
    collx=mPosX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + 90> LEVEL_WIDTH )||vacham1(collx,colly)||vacham2(collx,colly)
       ||vacham3(collx,colly)||vacham4(collx,colly)||vacham5(collx,colly)||vacham6(collx,colly)
       ||vacham7(collx,colly)||vacham8(collx,colly)||vacham9(collx,colly)||vacham10(collx,colly))
    {
        mPosX -= mVelX;
        collx=mPosX;


    }

if(mPosX<68&&flip==SDL_FLIP_NONE) mVelY=0;
    if(mVelY>0&&v==0) {v=18;}

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
    SDL_Texture*skeleton[2];
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
 SDL_Rect skeleton1 = {x-camera.x,mPosY,100,90};
SDL_RenderCopyEx(renderer,skeleton[ske/6],NULL,&skeleton1,0.0,NULL,flip);
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












