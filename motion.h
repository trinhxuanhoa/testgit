
#ifndef motion_h
#define motion_h


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "surface.h"
#include "main.h"
#include <SDL_mixer.h>
#include "Ai.h"
//Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


class Dot
{
    public:
        SDL_Event e;
        SDL_Rect camera;
        int w, h;
        double g = 1;
        double t = 0;
        double v = 0;
        int sotim = 10;
        int hesotim=0;
        int nhaycao=0;
        int danh=0;
        int i = 0;
        int MPOSX=0;
        int skill=0;
        int mskill=0;
        SDL_RendererFlip flipskill;
        int  demlive1=0;
        int resetdemlive=0;
        int skilly= 0;
        int demskill =0;
        bool skilldai = false;
        int vachamskill=false;
int  demlive2=0;
int k1 = 8;
int k=0;
SDL_RendererFlip flip=SDL_FLIP_NONE;	//The dimensions of the dot

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 7;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move();

        bool vacham1(int collx,int colly);
          bool vacham2(int collx,int colly);
            bool vacham3(int collx,int colly);
              bool vacham4(int collx,int colly);
               bool vacham5(int collx,int colly);
                 bool vacham6(int collx,int colly);
                 bool vacham7(int collx,int colly);
                 bool vacham8(int collx,int colly);
                 bool vacham9(int collx,int colly);
                 bool vacham10(int collx,int colly);

bool vachamsan(int collx,int colly);
void demsoluong(int live1,int live2);
void tim();
void chem();
bool vachamdan(int &danx,int dany,int hd,int wd);
		//Shows the dot on the screen relative to the camera
		void rendermonster();
		void render(int camX, int camY );
     void renderMove(SDL_Event &e,int camX,int camY, int camy);
		//Position accessors
		int getPosX();
		int getPosY();
        int  getmVelY();

		//The X and Y offsets of the dot
		int mPosX, mPosY;
  int collx,colly;
  int xs=0;
		//The velocity of the dot
		int mVelX=0, mVelY=0;
};




#endif
