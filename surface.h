

#ifndef surface_h
#define surface_h

#include <iostream>
#include <SDL.h>
#include <bits/stdc++.h>
#include "sdlutils.h"
#include <SDL_image.h>
#include "surface.h"
#include <SDL_mixer.h>
#include "Ai.h"
using namespace std;

class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		// defined(SDL_TTF_MAJOR_VERSION)
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );


		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip1 = SDL_FLIP_NONE );
void renderMove( SDL_Event &e,int camx,int mPosX,int mPosY,SDL_RendererFlip &flip,SDL_Rect* clip=NULL, double angle=0.0, SDL_Point* center=NULL);
//void renderDanh( SDL_Event &e,int &x,int mPosY,SDL_RendererFlip &flip,SDL_Rect* clip=NULL, double angle=0.0, SDL_Point* center=NULL);
		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;
SDL_RendererFlip flip;
		//Image dimensions
		int mWidth;
		int mHeight;
};
bool init();
bool loadMedia();
void close();

class LTimer
{
    public:
		//Initializes variables
		LTimer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks the status of the timer
		bool isStarted();
		bool isPaused();

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};


#endif
