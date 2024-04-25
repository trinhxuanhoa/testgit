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
#include "start.h"
extern Startgame sg;

class Ai{

public:

int mPosX=900;
int mPosY=420-90;
int sPosX;
int sPosY;
int mVelX=0;
int mVelY=0;
int vm = 3;
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
int skilly;
   SDL_Texture*skeleton[3];

 void closeai();
void move(int &hesotim);
void dieukhien(int& hesotim);
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
void renderwitch();
int sotim = 10;

        int nhaycao=0;
        int danh=0;
        int i = 0;
};

class Witch{

public:

int mPosX=900;
int mPosY=420-90;
int sPosX;
int sPosY;
int mVelX=0;
int mVelY=0;
int vm = 4;
int skilly;
bool daudau =false;
SDL_Rect camera;
        int  h=90;
        double g = 1;
        double t = 0;
        double v = 0;
        double sv = 0;
        int skill=0;
        int live = 100;
        int vitri=900;
        int Mdan[10]={0,0,0,0,0,0,0,0,0,0};
         int mdan[10]={0,0,0,0,0,0,0,0,0,0};
         int lanX[10]={0,0,0,0,0,0,0,0,0,0};
         bool dau[10]={0,0,0,0,0,0,0,0,0,0};
         int sodan=2;
         bool wn=false;
         bool checkmusic=false;

  int lanY[10]={0,0,0,0,0,0,0,0,0,0};
 int collx,colly;
 bool vachamskill= false;
 SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

SDL_RendererFlip smflip[10];
   SDL_Texture*skeleton[3];

 void closeai();
void move(int &hesotim);
void dieukhien(int& hesotim);
void dan(int &hesotim);
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
void renderwitch(int &hesotim);
int sotim = 10;

        int nhaycao=0;
        int danh=0;
        int i = 0;
};
#endif;
