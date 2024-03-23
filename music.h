#ifndef music_h
#define music_h


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "surface.h"
#include "main.h"
#include <SDL_mixer.h>
#include "music.h"

class music{

public:

 Mix_Music *amthanhnen = NULL;
 Mix_Chunk *danh = NULL;
 Mix_Chunk *gHigh = NULL;
 Mix_Chunk *gMedium = NULL;
 Mix_Chunk *gLow = NULL;
 int danh1=0;

bool loadMusic();
void handleMusic ();
void nhacnen();
void closeMusic();
};



#endif;
