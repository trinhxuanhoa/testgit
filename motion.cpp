
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "surface.h"
#include "main.h"
#include <SDL_mixer.h>
#include "motion.h"
using namespace std;
extern LTexture gDot[10];
extern LTexture gBG;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

Dot::Dot()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 420-90;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
      collx=mPosX;
      colly=mPosY;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {

            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL;break;
            case SDLK_UP:  mVelY =DOT_VEL;break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT: mVelX += DOT_VEL;break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
            case SDLK_UP:  mVelY -=DOT_VEL;break;
        }
    }
}

void Dot::move()
{
    //Move the dot left or right
    mPosX += mVelX;
    collx=mPosX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + 100> LEVEL_WIDTH )||vacham1(collx,colly)||vacham2(collx,colly)||vacham3(collx,colly)|vacham4(collx,colly))
    {
        mPosX -= mVelX;
        collx=mPosX;
    }

    if(mVelY>0&&v==0) {v=24;}

    if(v!=0||t!=0) {
double s=0.5*g*t*t-v*t;
t+=1;
mPosY+=-s+0.5*g*t*t-v*t;

colly=mPosY;

}

//cout << g << " " << v << endl;
if(vachamsan(collx,colly))
    {v=0;t=0;
    mPosY=330;
    colly=mPosY;}

   if( vacham1(collx,colly))
    {
       mPosY=337-90;
       colly=mPosY;
       v=0;t1=t;t=0;
    }
 if( vacham2(collx,colly))
    {
       mPosY=275-90;
       colly=mPosY;
       v=0;t1=t;t=0;
    }
    if( vacham3(collx,colly))
    {
       mPosY=210-90;
       colly=mPosY;
       v=0;t1=t;t=0;
    }
    if( vacham4(collx,colly))
    {
       mPosY=190-90;
       colly=mPosY;
       v=0;t1=t;t=0;
    }
/*if (e.type==SDL_KEYDOWN) switch (e.key.keysym.sym) {
    case SDLK_RIGHT:
 if( ( mPosX < 0 ) || ( mPosX + 100> LEVEL_WIDTH )||vacham(collx,colly)){
        mPosY-=2;  g=0;
        colly=mPosY;
    }

break;
}*/
}
bool Dot::vachamsan(int collx,int colly) {
 bool k = true;
     int right  = collx;
    int bottom = colly+90;

if (bottom<420)
k = false;

return k;
}

bool Dot::vacham1(int collx,int colly) {

    bool k = true;

if (collx+w-40<=103-camera.x)
{k= false;if(mPosY==337-90&&v==0) t = 20;}

if(collx>=130)
   {k=false;if(mPosY==337-90&&v==0) t = 20;}

 if (collx<130&&colly+h<=337)
k= false;

return k;
}

bool Dot::vacham2(int collx,int colly) {

    bool k = true;

if (collx+w-45<=200-camera.x)
{k= false;if(mPosY==275-90&&v==0) t = 20;}

if(collx>=230-camera.x)
   {k=false;if(mPosY==275-90&&v==0) t = 20;}

 if (collx<230&&colly+h<=275)
k= false;

return k;
}

bool Dot::vacham3(int collx,int colly) {

    bool k = true;

if (collx+w-45<=290-camera.x)
{k= false;if(mPosY==210-90&&v==0) t = 20;}

if(collx>=370-camera.x)
   {k=false;if(mPosY==210-90&&v==0) t = 20;}

 if (collx-camera.x<290&&colly+h<=210)
k= false;

return k;
}


bool Dot::vacham4(int collx,int colly) {

    bool k = true;

if (collx+w-45<=360)
{k= false;if(mPosY==190-90&&v==0) t = 20;}

if(collx>=405)
   {k=false;if(mPosY==190-90&&v==0) t = 20;}

 if (collx-camera.x<360&&colly+h<=190)
k= false;
if(colly>235)
    k=false;
cout << mPosX << " " << camera.x << endl;
return k;
}


void Dot::renderMove(SDL_Event &e,int camX, int nhay,int k )
{
    int a = mPosX-camX;
	gDot[0/4].renderMove(e,a,mPosY);
}

int Dot::getPosX()
{
	return mPosX;
}

int Dot::getPosY()
{
	return mPosY;
}
int Dot::getmVelY()
{
    return mVelY;
}


