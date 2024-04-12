
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
extern LTexture gDot[2];
LTexture demq;
extern LTexture gBG;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

Dot::Dot()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 330;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
      collx=mPosX;
      colly=mPosY;
}

void Dot::handleEvent( SDL_Event& e )
{

	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {

        switch( e.key.keysym.sym )
        {

            case SDLK_LEFT: mVelX -= DOT_VEL;   flip=SDL_FLIP_HORIZONTAL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL;  flip=SDL_FLIP_NONE;break;
            case SDLK_UP:  mVelY =DOT_VEL;break;
            case SDLK_DOWN: nhaycao+=1 ;break;
            case SDLK_SPACE: if(danh==0) {danh = 7;i=0;}break;
        }
    }

    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {

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

    if(mskill==0)
        {vachamskill=false;
        }

    SDL_Texture*chem[3];
chem[0]=loadTexture(renderer,"saber/saberchem1.png");
chem[1]=loadTexture(renderer,"saber/saberchem2.png");
chem[2]=loadTexture(renderer,"saber/saberchem3.png");

SDL_Texture *ki = loadTexture(renderer,"saber/ki1.png");
if(mskill==0)
    skilly=mPosY;

if(danh==7)
flipskill=flip;

if(flip==SDL_FLIP_NONE)
 {MPOSX=mPosX-camera.x-8;
 //skill=mPosX+50+mskill;

}
if(flip==SDL_FLIP_HORIZONTAL)
{MPOSX=mPosX-camera.x-40;

}

if(flipskill==SDL_FLIP_NONE)
 skill=mPosX+50+mskill;
 if(flipskill==SDL_FLIP_HORIZONTAL) {
skill=mPosX-80-mskill;

 }
 //cout << mskill << endl;
mskill+=15;
//cout << demskill << endl;
if(mskill==90) demskill++;
if(demskill==10) {danh==9;skilldai=true;}
if(mskill>90&&demskill!=10&&!skilldai) mskill=0;
if(mskill>=120) skilldai=false;
if(demskill==10) demskill=0;
SDL_Rect a = {MPOSX,mPosY-camera.y,w,h};

SDL_Rect b = {skill-camera.x,skilly-camera.y,w,h};
SDL_RenderCopyEx(renderer,chem[i/2],NULL,&a,0.0,NULL, flip);
//if(!vachamdan(skill,skilly+45,0,0))///////////////////////////////////////////////////////////////////
   //{vachamskill=true;

   // mskill=0;
 //}


SDL_RenderCopyEx(renderer,ki,NULL,&b,0.0,NULL,flipskill);


danh--;

i++;
if(i>=6) i = 0;
for(int i2 = 0; i2 < 3; i2++)
{
    SDL_DestroyTexture(chem[i2]);
    chem[i2]=NULL;
}
SDL_DestroyTexture(ki);
ki=NULL;
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
void Dot::renderMove(SDL_Event &e,int camX,int camY,int nhay )
{

if (k1>=20) k1 = 8;
    if (nhaycao>0) {
	gDot[k1/4].renderMove(e,camera.x,camera.y,mPosX,mPosY,flip);
	k1++;
    }
	else
    {
        if(mVelX!=0)
        k++;
        else
        k=0;
       if(k>7) k=0;
        gDot[k/4].renderMove(e,camera.x,camera.y,mPosX,mPosY,flip);
    }
}
void Dot::demsoluong(int live1,int live2) {


SDL_Texture*dem=loadTexture(renderer,"monster/dem.png");
SDL_RenderCopy(renderer,dem,NULL,NULL);
if(!resetdemlive)
{
    demlive1=0;
    demlive2=0;
}
if(live1<=0) demlive1++;
if(live2<=0) demlive2++;
demq.rendertext(50,50,demlive1);
demq.rendertext(51,50,demlive1);
demq.rendertext(52,50,demlive1);
demq.rendertext(50,100,demlive2);
demq.rendertext(51,100,demlive2);
demq.rendertext(52,100,demlive2);
SDL_DestroyTexture(dem);
dem=NULL;
}
bool Dot::vachamdan(int &danx,int dany,int hd,int wd)  {

int k = true;
if(dany+hd>97*3) {
if(danx+wd>52*3&&danx<84*3) {k=false;
if(flipskill==SDL_FLIP_NONE) danx=52*3;
else danx=84*3;
cout << "1" << endl;
}
}
if(dany+hd>74*3) {
if(danx+wd>118*3&&danx<233*3) {k= false;
if(flipskill==SDL_FLIP_NONE) danx=118*3;
else danx=233*3;
cout << "2" << endl;
}
}
if(dany+hd>108*3) {
if(danx+wd>233*3&&danx<277*3)  {k= false;
if(flipskill==SDL_FLIP_NONE) danx=233*3;
else danx=277*3;
cout << "3" << endl;
}
}
if(dany+hd>49*3) {
if(danx+wd>400*3&&danx<422*3) {k= false;
if(flipskill==SDL_FLIP_NONE) danx=400*3;
else danx=422*3;
cout << "4" << endl;
}
}
if(dany+hd>84*3) {
if(danx+wd>535*3&&danx<574*3) {k= false;
if(flipskill==SDL_FLIP_NONE) danx=535*3;
else danx=574*3;
cout << "5" << endl;
}
}
if(dany+hd>49*3) {
if(danx+wd>574*3&&danx<601*3) {k= false;
if(flipskill==SDL_FLIP_NONE) danx=574*3;
else danx=601*3;
cout << "6" << endl;
}
}
if(dany+hd>96*3) {
if(danx+wd>639*3&&danx<653*3) {k= false;
if(flipskill==SDL_FLIP_NONE) danx=639*3;
else danx=653*3;
cout << "7" << endl;
}
}
if(dany+hd>70*3) {
if(danx+wd>695*3&&danx<710*3) {k= false;
if(flipskill==SDL_FLIP_NONE) danx=695*3;
else danx=710*3;
cout << "8" << endl;
}
}
if(dany+hd>70*3) {
if(danx+wd>766*3&&danx<782*3) {k= false;
if(flipskill==SDL_FLIP_NONE) danx=766*3;
else danx=782*3;
cout << "9" << endl;
}
}
if(dany+hd>74*3) {
if((danx+wd>799*3||danx+30>987*3)&&danx<815*3) {k= false;
if(flipskill==SDL_FLIP_NONE) danx=799*3;
else danx=987*3;
cout << "10" << endl;
}
}
return k;
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

