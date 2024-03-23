
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

            case SDLK_LEFT: mVelX -= DOT_VEL;   flip=SDL_FLIP_HORIZONTAL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL;   flip=SDL_FLIP_NONE;break;
            case SDLK_UP:  mVelY =DOT_VEL;break;
            case SDLK_DOWN: nhaycao+=1 ;break;
            case SDLK_w: if(danh==0) {danh = 9;i=0;}break;
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
             case SDLK_DOWN: nhaycao-=1 ;break;
             // case SDLK_a: danh -=1;break;
        }
    }
}
void Dot::tim() {

SDL_Texture*tim=loadTexture(renderer,"tim.png");
SDL_Rect tim1 = {210*(hesotim/sotim),0,210,35};
SDL_Rect tim2 = {0,0,210,35};
SDL_RenderCopy(renderer,tim,&tim1,&tim2);
SDL_DestroyTexture(tim);
tim=NULL;
}
void Dot::chem() {
    SDL_Texture *chem[3];
chem[0]=loadTexture(renderer,"saber/saberchem1.png");
chem[1]=loadTexture(renderer,"saber/saberchem2.png");
chem[2]=loadTexture(renderer,"saber/saberchem3.png");

SDL_Texture *ki = loadTexture(renderer,"saber/ki1.png");

if(flip==SDL_FLIP_NONE)
 {MPOSX=mPosX-camera.x-8;
 skill=mPosX+50+mskill;
 mskill+=15;}
if(flip==SDL_FLIP_HORIZONTAL)
{MPOSX=mPosX-camera.x-40;
skill=mPosX-50-mskill;
mskill+=15;}

SDL_Rect a = {MPOSX,mPosY,w,h};
SDL_Rect b = {skill-camera.x,mPosY,w,h};
SDL_RenderCopyEx(renderer,chem[i/2],NULL,&a,0.0,NULL, flip);
SDL_RenderCopyEx(renderer,ki,NULL,&b,0.0,NULL, flip);
danh--;

i++;
if(i>=6) i = 0;
for(int i2 = 0; i2 < 3; i2++)
{
    SDL_DestroyTexture(chem[i2]);
    chem[i2]=NULL;
}
}

void Dot::move()
{
    //Move the dot left or right
    mPosX += mVelX;
    collx=mPosX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + w> LEVEL_WIDTH )||vacham1(collx,colly)||vacham2(collx,colly)
       ||vacham3(collx,colly)||vacham4(collx,colly)||vacham5(collx,colly)||vacham6(collx,colly)
       ||vacham7(collx,colly)||vacham8(collx,colly)||vacham9(collx,colly)||vacham10(collx,colly))
    {
        mPosX -= mVelX;
        collx=mPosX;

    }

    if(mVelY>0&&v==0) {v=18;if(nhaycao>0)v=24;}

    if(v!=0||t!=0) {
double s=0.5*g*t*t-v*t;
t+=1;
mPosY+=-s+0.5*g*t*t-v*t;

colly=mPosY;

}

//cout << g << " " << v << endl;
if(vachamsan(collx,colly)){
        v=0;t=0;
    mPosY=330;
    colly=mPosY;}

   if( vacham1(collx,colly))
    {
       mPosY=290-90;
       colly=mPosY;
       v=0;t=0;
    }
 if( vacham2(collx,colly))
    {
       mPosY=223-90;
       colly=mPosY;
       v=0;t=0;
    }
    if( vacham3(collx,colly))
    {
       mPosY=325-90;
       colly=mPosY;
       v=0;t=0;
    }
    if( vacham4(collx,colly))
    {
       mPosY=147-90;
       colly=mPosY;
       v=0;t=0;
    }

if( vacham5(collx,colly))
    {
       mPosY=250-90;
       colly=mPosY;
       v=0;t=0;
    }
if( vacham6(collx,colly))
    {
       mPosY=146-90;
       colly=mPosY;
       v=0;t=0;
    }
if( vacham7(collx,colly))
    {
       mPosY=291-90;
       colly=mPosY;
       v=0;t=0;
    }

if( vacham8(collx,colly))
    {
       mPosY=213-90;
       colly=mPosY;
       v=0;t=0;
    }
if( vacham9(collx,colly))
    {
       mPosY=212-90;
       colly=mPosY;
       v=0;;t=0;
    }
if( vacham10(collx,colly))
    {
       mPosY=224-90;
       colly=mPosY;
       v=0;t=0;
    }

       /* if(flip==SDL_FLIP_NONE&&xs-22<mPosX&&xs+40>mPosX)
            hesotim++;
            if(flip==SDL_FLIP_HORIZONTAL&&xs+33<mPosX&&xs+103>mPosX)
           hesotim++;*/
           // cout << mPosX << endl;
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

if (collx+w-40<=160)
{k= false;if(mPosY==290-90&&v==0) t = 20;}

if(collx>=250)
   {k=false;if(mPosY==290-90&&v==0) t = 20;}

 if (collx<250&&colly+h<=290)
k= false;

return k;
}

bool Dot::vacham2(int collx,int colly) {

    bool k = true;

if (collx+w-40<=355)
{k= false;if(mPosY==223-90&&v==0) t = 20;}

if(collx>=705)
   {k=false;if(mPosY==223-90&&v==0) t = 20;}

 if (collx<705&&colly+h<=223)
k= false;

return k;
}

bool Dot::vacham3(int collx,int colly) {

    bool k = true;

if (collx+w-40<=705)
{k= false;if(mPosY==325-90&&v==0) t = 20;}

if(collx>=835)
   {k=false;if(mPosY==325-90&&v==0) t = 20;}

 if (collx<835&&colly+h<=325)
k= false;

return k;
}


bool Dot::vacham4(int collx,int colly) {

    bool k = true;

if (collx+w-40<=1200)
{k= false;if(mPosY==147-90&&v==0) t = 20;}

if(collx>=1265)
   {k=false;if(mPosY==147-90&&v==0) t = 20;}

 if (collx<1265&&colly+h<=147)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}
bool Dot::vacham5(int collx,int colly) {

    bool k = true;

if (collx+w-40<=1615)
{k= false;if(mPosY==250-90&&v==0) t = 20;}

if(collx>=1730)
   {k=false;if(mPosY==250-90&&v==0) t = 20;}

 if (collx<1730&&colly+h<=250)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}


bool Dot::vacham6(int collx,int colly) {

    bool k = true;

if (collx+w-40<=1730)
{k= false;if(mPosY==146-90&&v==0) t = 20;}

if(collx>=1805)
   {k=false;if(mPosY==146-90&&v==0) t = 20;}

 if (collx<1805&&colly+h<=146)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Dot::vacham7(int collx,int colly) {

    bool k = true;

if (collx+w-40<=1925)
{k= false;if(mPosY==291-90&&v==0) t = 20;}

if(collx>=1960)
   {k=false;if(mPosY==291-90&&v==0) t = 20;}

 if (collx<1960&&colly+h<=291)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Dot::vacham8(int collx,int colly) {

    bool k = true;

if (collx+w-40<=2091)
{k= false;if(mPosY==213-90&&v==0) t = 20;}

if(collx>=2128)
   {k=false;if(mPosY==213-90&&v==0) t = 20;}

 if (collx<2128&&colly+90<=213)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Dot::vacham9(int collx,int colly) {

    bool k = true;

if (collx+w-40<=2310)
{k= false;if(mPosY==212-90&&v==0) t = 20;}

if(collx>=2340)
   {k=false;if(mPosY==212-90&&v==0) t = 20;}

 if (collx<2340&&colly+90<=212) {

k= false;}

//cout << mPosX << " " << camera.x << endl;
return k;
}

bool Dot::vacham10(int collx,int colly) {

    bool k = true;

if (collx+w-40<=2410)
{k= false;if(mPosY==224-90&&v==0) t = 20;}

if(collx>=2440)
   {k=false;if(mPosY==224-90&&v==0) t = 20;}

 if (collx<2440&&colly+h<=224)
k= false;

//cout << mPosX << " " << camera.x << endl;
return k;
}
void Dot::renderMove(SDL_Event &e,int camX,int nhay,int k )
{

if (k1>12) k1 = 4;

    if (nhaycao>0) {
	gDot[k1/4].renderMove(e,camera.x,mPosX,mPosY,flip);
	k1++;
    }
	else
     gDot[0].renderMove(e,camera.x,mPosX,mPosY,flip);
//cout << MPOSX << endl;
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


