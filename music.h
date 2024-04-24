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

 Mix_Music *amthanhnen[10];
 Mix_Chunk *danh[2];

 int danh1=0;

bool loadMusic();
void handleMusic (int &volume);
void nhacnen(int &volume1,int &chon,int &nhochon);
void amthanhsung(int &volume);
void closeMusic();
};



#endif;
