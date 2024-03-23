#ifndef Ai_h
#define Ai_h


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "surface.h"
#include "main.h"
#include <SDL_mixer.h>
#include "motion.h"


class Ai{

public:

int mPosX=900;
int mPosY=420-90;
int sPosX;
int sPosY;
int mVelX=0;
int mVelY=0;
SDL_Rect camera;
        int  h=90;
        double g = 1;
        double t = 0;
        double v = 0;
        double sv = 0;
        int skill=0;
        int live = 100;
 int collx,colly;
 SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
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
void handleEvent( SDL_Event& e );

void rendermonster();

int sotim = 10;
        int hesotim=0;
        int nhaycao=0;
        int danh=0;
        int i = 0;
};


#endif;
