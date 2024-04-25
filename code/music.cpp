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
#include "music.h"

using namespace std;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

bool music::loadMusic()
{

    bool success = true;
    amthanhnen[0] = Mix_LoadMUS( "music/y2mate.com - FateStay Night Heavens Feel III THE FOUR RINGS Spring Song OFFICIAL SOUNDTRACK SaberAlter vs Rider.mp3" );
    if( amthanhnen[0] == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
 amthanhnen[1] = Mix_LoadMUS( "music/mangchung.mp3" );
    if( amthanhnen[1] == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    amthanhnen[2] = Mix_LoadMUS( "music/FILE_20220619_183923_Alan x Walkers - Unity ( 128kbps ).mp3" );
    if( amthanhnen[2] == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

     amthanhnen[3] = Mix_LoadMUS( "music/FILE_20220619_184131_Em nguyện làm một người bình thường bên cạnh anh (remix) _Nhạc hot Tik Tok Trung Quốc __ TM ( 128kbps ).mp3" );
    if( amthanhnen[3] == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
   danh[0] = Mix_LoadWAV( "music/giong1.wav" );
    if( danh[0] == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

danh[1] = Mix_LoadWAV( "music/amthanhsung1.wav" );
    if( danh[1] == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    return success;
}


void music::handleMusic (int &volume) {
//int static k1=0;
//int static k2=1;
//int static k3=2;


Mix_Volume(0, MIX_MAX_VOLUME/10*volume);


if(danh1==6)  Mix_PlayChannel( 0, danh[0], 0 );



							//If music is being played
							/*else
							{
								//If the music is paused
								if( Mix_PausedMusic() == 1 )
								{
									//Resume the music
									Mix_ResumeMusic();
								}
								//If the music is playing
								else
								{
									//Pause the music
									Mix_PauseMusic();
								}
							}*/


}
void music::amthanhsung(int &volume) {

Mix_Volume(1, MIX_MAX_VOLUME/10*volume);


    Mix_PlayChannel( 1, danh[1], 0 );

}
void music::nhacnen(int &volume1,int &chon,int &nhochon){
Mix_VolumeMusic(MIX_MAX_VOLUME / 10*volume1);
    if( Mix_PlayingMusic() == 0)
    Mix_PlayMusic( amthanhnen[chon], -1 );
    if(nhochon!=chon) {
         Mix_HaltMusic();
         nhochon=chon;
    }
}
void music::closeMusic() {
    Mix_FreeChunk(danh[0]);
danh[0]=NULL;
Mix_FreeChunk(danh[1]);
danh[1]=NULL;
    for(int i = 0; i < 4; i++) {

Mix_FreeMusic(amthanhnen[i]);
amthanhnen[i]=NULL;
    }
Mix_Quit();
}





















