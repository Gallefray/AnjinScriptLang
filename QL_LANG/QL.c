// Includes:
#include <stdio.h> 	// standard input output library
#include <stdlib.h> // standard C library I believe?
#include <stdint.h> // this allows Sint16 and stuff like that
#include <time.h>   // Gives access to system time (used to set the seed :D )
#include <SDL/SDL.h>// SDL library
#include <SDL/SDL_gfxPrimitives.h> // SDL gfx library
#include <assert.h> // Checks if things exist ;)

// Defines:
#define true 1
#define false 0
#define bool int

uint16_t red, green, blue, alpha;

SDL_Event event;
const SDL_VideoInfo* info = NULL;
SDL_Surface *screen;


// Yes, yes. The library structure is a mess... I will reorganise it when the core libs are in :P


bool initWindow(int height, int width, bool fullscreen, char *name)
{
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init the SDL libs, if there's an error then catch and report it. Yeah, I'm initing all of them, eh.

	{ 
	    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
	    exit(1);
	}

	atexit(SDL_Quit);// Clean up everything when the program exits! :D

	info = SDL_GetVideoInfo( ); // Retrieve video information
	int bitPerPixel = info->vfmt->BitsPerPixel;  // Grabbing the bpp from the screen now ;)

	if (fullscreen == true)
	{
		screen = SDL_SetVideoMode(height, width, bitPerPixel, SDL_DOUBLEBUF |SDL_FULLSCREEN);// == -1)//SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN) == -1)
		//{
		if ( screen == NULL ) 
		{
			
		    fprintf(stderr, "Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
		    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
		    exit(1);
		}
		//	return false;
		//}
	}
	else
	{
		screen = SDL_SetVideoMode(height, width, bitPerPixel, SDL_DOUBLEBUF); //== -1)//SDL_HWSURFACE | SDL_DOUBLEBUF) == -1)
		//{
		if ( screen == NULL ) 
		{
		    fprintf(stderr, "Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
		    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
		    exit(1);
		}
		//	return false;
		//}
		// else
		// {
		// 	printf("screen data - width: %d, height: %d, BBP: %d \n", width, height, bitPerPixel);	// The SDL surface is def being created!! D:
		// }
	}
	//assert(screen != NULL); // Error above here!!!!

	SDL_WM_SetCaption(name, NULL ); // set the caption, as per the new 4th arg!

	// SDL_WM_GrabInput(SDL_GRAB_ON);  // This makes the window grab all input :P
	// NEVER. NEVER SET THAT UNLESS KYBOARD INPUT HAS BEEN ENABLED, AND YOU HAVE IT TOP CATCH THE ESC BUTTON. OR YOUR PC WILL DIE.
	// It *was* pretty funny, though xD
	if ( screen == NULL ) 
	{
		
	    fprintf(stderr, "Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
	    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
	    exit(1);
	}
	return true;
}

int randomNum(int min, int max)
{	
	//(rand()%max);
	return min+(rand()%((max+1)-min)); // inclusive :D
}

bool rectRectCollision(int Ax, int Ay, int Ah, int Aw, int Bx, int By, int Bh, int Bw)
{
	if (Ax + Aw >= Bx && Ax <= Bx+Bw && Ay + Ah >= By && Ay <= By+Bh)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int setColour(uint16_t r, uint16_t g, uint16_t b, uint16_t a)
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
	return 0;
}

int rect(char *type, int16_t x, int16_t y, int16_t w, int16_t h)
{
	if (strcmp(type, "fill") == 0)
	{
		//float 
		boxRGBA(screen, x, y, x+w, y+h, red, green, blue, alpha);
	}
	else if (strcmp(type, "line") == 0)
	{
		rectangleRGBA(screen, x, y, x+w, y+h, red, green, blue, alpha);	
	}
	else
	{
		printf("Incorrect first argument given to the rect function! D:\n");
		printf("You gave %s\n", type);
		printf("Only 'line' or 'fill' can be accepted.");
		return 1;
	}
	return 0;
}

// int setLineWidth(int width)
// {
	
// 	return 0;
// }

// int clear()
// {
	
// 	return 0;
// }

int update(int FPS)
{
	#ifdef EMSCRIPTEN
	emscripten_set_main_loop(main, FPS, 0);
	#else

	SDL_Flip(screen);
	return 0;
	#endif
}

int grabKeyInput()
{
	while( SDL_PollEvent( &event ) ){
	    /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
	    switch( event.type ){
	     	case SDL_KEYDOWN:
	       		printf( "Key press detected\n" );
	        	break;

	      	case SDL_KEYUP:
	        	printf( "Key release detected\n" );
	        	break;

	        case SDL_QUIT:
	        	// put something here to deInit openGL and SDL and quit :D
                break;
	      	default:
	        	break;
	    }
	}
    return 0;
}

// int grabMouseInput(float mouseX, float mouseY)
// {
// `
// }

// int doStuff = 0;
// bool keyInput(char key)
// {	
//     while(SDL_PollEvent(&event) )
//     {
//         if(event.type == SDLK_KEYDOWN)
//         {
//                 switch(event.key.keysym.sym)
//                 {
                	
//                 }
//         }
//         if(event.type == SDLK_KEYUP)
//         {
//                 switch(event.key.keysym.sym)
//                 {
                    
//                 }
//         }
//     }   
// }