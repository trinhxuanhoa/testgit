
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
    mPosY = 230-107;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
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

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + 100> LEVEL_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }


}
void Dot::vacham(SDL_Event e,SDL_Rect camera,int w1,int h1) {
    int w = w1/2.5;
    int h = h1/2.5;
cout <<mPosX<< " " <<
   mPosY <<endl;
    if (e.type==SDL_KEYDOWN) {
   if(e.key.keysym.sym==SDLK_RIGHT) {

if (mPosX+20>=-camera.x&&mPosX+20<=50-camera.x ){

        mPosY = 230-h;
}
else if (mPosX>=80-20-camera.x&&mPosX+20<=133-camera.x ){

    mPosY=152-h;
}
else
     mPosY=323;
}
 if(e.key.keysym.sym==SDLK_LEFT) {

if (mPosX>=-camera.x&&mPosX<=50-camera.x ){

        mPosY = 230-h;
}
else if (mPosX>=83-camera.x&&mPosX<=133-camera.x ){

    mPosY=152-h;

}
else
     mPosY=323;
}
}
}
void Dot::renderMove(SDL_Event &e,int camX, int y,int k )
{

	gDot[k/4].renderMove(e,mPosX-camX,y,mPosY);


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


