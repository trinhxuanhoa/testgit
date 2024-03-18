
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
        int sotim = 0;
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

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
void tim();
		//Shows the dot on the screen relative to the camera
		void render(int camX, int camY );
     void renderMove(SDL_Event &e,int camX, int camY ,int k);
		//Position accessors
		int getPosX();
		int getPosY();
        int  getmVelY();
    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;
  int collx,colly;
		//The velocity of the dot
		int mVelX, mVelY;
};







#endif
