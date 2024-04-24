#ifndef video_h
#define video_h



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

class Video {

SDL_Texture*invideo[292];
public:
void loadvideo();
void rendervideo(int &hinh);

void desvideo();
};
#endif
