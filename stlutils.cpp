#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "sdlutils.h"
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include <SDL_mixer.h>
using namespace std;


void logSDLError(ostream& os,
 const string &msg, bool fatal)
{
 os << msg << " Error: " << SDL_GetError() << endl;
 if (fatal) {
 SDL_Quit();
 exit(1);
 }
}

void init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer,int SCREEN_WIDTH,int SCREEN_HEIGHT, const string &WINDOW_TITLE)
{

	if( SDL_Init( SDL_INIT_VIDEO|SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		gWindow = SDL_CreateWindow( WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				int imgFlags = IMG_INIT_PNG;

				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				}
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer không thể khởi tạo! Lỗi SDL_mixer: %s\n", Mix_GetError() );
                }
			}
		}
	}

}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,int SCREEN_WIDTH,int SCREEN_HEIGHT,const string &WINDOW_TITLE)
{
 if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
 logSDLError(std::cout, "SDL_Init", true);
 window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
 SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
 //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
 //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
 if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
 //Khi chạy trong môi trường bình thường (không chạy trong máy ảo)
 renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
 SDL_RENDERER_PRESENTVSYNC);
 //Khi chạy ở máy ảo (ví dụ tại máy tính trong phòng thực hành ở trường)
 //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
 if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
 SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
 SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}


void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
renderer=nullptr;
window=nullptr;
SDL_Quit();
}


void quitSDL_Image(SDL_Texture*texture) {
SDL_DestroyTexture(texture);
texture=nullptr;
//IMG_Quit;
}


void waitUntilKeyPressed()
{
 SDL_Event e;
 while (true) {
 if ( SDL_WaitEvent(&e) != 0 &&
 (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
 return;
 SDL_Delay(100);
 }
}


SDL_Texture* loadTexture (SDL_Renderer*renderer,string path) {
SDL_Texture *newTexture = nullptr;
SDL_Surface* loadedSurface = IMG_Load (path.c_str());
if (loadedSurface == nullptr)
    cout << "khong the load anh " << path << "SDL_image loi: "
    << IMG_GetError() << endl;
else {
    newTexture = SDL_CreateTextureFromSurface (renderer,loadedSurface);
    if (newTexture == nullptr)
        cout << "khong th tao texture tu " << path << " SDL loi: "
        << SDL_GetError() << endl;
    SDL_FreeSurface (loadedSurface);
}
 return newTexture;}



 SDL_Texture* loadFromFile( SDL_Renderer*renderer,string path) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "khong the load anh %s\n", path.c_str(), SDL_GetError() );
		}
		else
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;
}


void renderOriginal(SDL_Renderer*renderer,SDL_Texture*a, int x, int y) {
    int mwidth,mheight;
    SDL_QueryTexture(a,NULL,NULL,&mwidth,&mheight);
	SDL_Rect renderQuad = { x, y, mwidth, mheight };
	SDL_RenderCopy( renderer, a, NULL, &renderQuad );
}


void renderQuarterOriginal(SDL_Renderer*renderer,SDL_Texture*a,int x,int y,int local) {
    int width, height;
    SDL_QueryTexture(a,NULL,NULL,&width,&height);
    SDL_Rect renderQuad = { x, y, width/2, height/2 };
    SDL_Rect clip;
    switch (local) {
    case 1:clip = {0,0,width/2,height/2};break;
    case 2:clip = {width/2,0,width/2,height/2};break;
    case 3:clip = {width/2,height/2,width/2,height/2};break;
    case 4:clip = {0,height/2,width/2,height/2};break;
    default:break;
    }
    SDL_RenderCopy(renderer,a,&clip,&renderQuad);
}


void Motion (SDL_Renderer*renderer,SDL_Texture*people,const int WALKING_ANIMATION_FRAMES,const int speed,int width,SDL_Rect gSpriteClips[ ]) {
  int frame = 0,w,h;
SDL_Event e;
SDL_QueryTexture(people,NULL,NULL,&w,&h);
SDL_Rect local;
int swidth = 0;
for (int i = 0; i < WALKING_ANIMATION_FRAMES; i++) {
        gSpriteClips[ i ].x = swidth;
		gSpriteClips[ i ].y =   0;
		gSpriteClips[ i ].w =  64;
		gSpriteClips[ i ].h = 205;
        swidth+=width;
}
while(true) {
     if(SDL_PollEvent(&e)!=0) {
            if (e.type==SDL_QUIT) break;
     }

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );

    SDL_Rect* currentClip = &gSpriteClips[ frame / speed ];
    local = {( 1000 - currentClip->w ) / 2,(600- currentClip->h)/2,w,h};

    SDL_RenderCopy(renderer,people, currentClip,&local);
    SDL_RenderPresent( renderer );
    ++frame;
    if( frame / speed >= WALKING_ANIMATION_FRAMES )
    frame = 0;
}
}


void renderEx( SDL_Renderer*renderer,SDL_Texture*a,int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	int mwidth,mheight;
    SDL_QueryTexture(a,NULL,NULL,&mwidth,&mheight);
	SDL_Rect renderQuad = { x, y, mwidth, mheight };
	SDL_RenderCopyEx( renderer, a, clip, &renderQuad, angle, center, flip );
}


void xoay(SDL_Renderer*renderer,SDL_Texture*people) {
SDL_Event e;
			double degrees = 0;
			SDL_RendererFlip flipType = SDL_FLIP_NONE;
			int x, y;

SDL_QueryTexture(people,NULL,NULL,&x,&y);
while(true) {
    if(SDL_PollEvent(&e)!=0) {
        if (e.type==SDL_QUIT) break;
        else if (e.type==SDL_KEYDOWN) switch (e.key.keysym.sym){
            case SDLK_a:degrees -= 15;break;
            case SDLK_d:degrees += 15;break;
            case SDLK_q:flipType = SDL_FLIP_HORIZONTAL;break;
            case SDLK_w:flipType = SDL_FLIP_NONE;break;
            case SDLK_e:flipType = SDL_FLIP_VERTICAL;break;
            default:break;
            }
        }
       SDL_RenderClear(renderer);
       renderEx(renderer,people,(1000-x)/2,(600-x)/2,NULL,degrees,NULL,flipType);
       SDL_RenderPresent(renderer);
    }
}


SDL_Texture* loadFromRenderedText(SDL_Renderer* renderer, string textureText, SDL_Color textColor,TTF_Font* gFont) {
    SDL_Texture* mTexture = NULL;
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else {
        mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == NULL) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        SDL_FreeSurface(textSurface);
    }

    return mTexture;
}


void setPosition( int x, int y ,SDL_Point& mPosition){
	mPosition.x = x;
	mPosition.y = y;
}

 enum LButtonSprite {
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};
 SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
void handleEvent( SDL_Event* e,SDL_Point& mPosition ,const int BUTTON_WIDTH,const int BUTTON_HEIGHT){
    mPosition.x = 0;
	mPosition.y = 0;

    LButtonSprite mCurrentSprite;
    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;


	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

				case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}






