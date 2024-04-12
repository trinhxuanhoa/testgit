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

    amthanhnen = Mix_LoadMUS( "music/y2mate.com - FateStay Night Heavens Feel III THE FOUR RINGS Spring Song OFFICIAL SOUNDTRACK SaberAlter vs Rider.mp3" );
    if( amthanhnen == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

   danh = Mix_LoadWAV( "music/giong1.wav" );
    if( danh == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }


    return success;
}

void music::handleMusic () {
Mix_Volume(-1, MIX_MAX_VOLUME / 5);



if(danh1==8)  Mix_PlayChannel( -1, danh, 0 );



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
void music::nhacnen(){
Mix_VolumeMusic(MIX_MAX_VOLUME / 5);
    if( Mix_PlayingMusic() == 0 )
    Mix_PlayMusic( amthanhnen, -1 );
}
void music::closeMusic() {
Mix_FreeChunk(danh);
danh=NULL;
Mix_FreeMusic(amthanhnen);
amthanhnen=NULL;
Mix_Quit();
}





















