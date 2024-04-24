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
#include "video.h"
using namespace std;
extern SDL_Renderer* renderer;
void Video::loadvideo() {
for (int i = 0; i < 10; ++i) {
    string filename = "video/Saber Alter Excalibur Morgan [4K 60fps]_00" + std::to_string(i) + ".jpg";
    invideo[i] = loadTexture(renderer, filename.c_str());
}
for (int i = 10; i < 100; ++i) {
    string filename = "video/Saber Alter Excalibur Morgan [4K 60fps]_0" + std::to_string(i) + ".jpg";
    invideo[i] = loadTexture(renderer, filename.c_str());
}
for (int i = 100; i < 292; ++i) {
    string filename = "video/Saber Alter Excalibur Morgan [4K 60fps]_" + std::to_string(i) + ".jpg";
    invideo[i] = loadTexture(renderer, filename.c_str());
}
}

void Video::rendervideo(int &hinh) {
    if(hinh>=291) hinh=0;
    SDL_Rect a = {0,0,600,450};
    SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer,invideo[hinh],NULL,&a);
}

void Video::desvideo() {
for(int i = 0;i < 292; i++) {
SDL_DestroyTexture(invideo[i]);
invideo[i]=NULL;
}
}
