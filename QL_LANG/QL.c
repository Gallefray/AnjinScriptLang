// Includes:
#include <stdio.h> 	// standard input output library
#include <stdlib.h> // standard C library I believe?
#include <stdint.h> // this allows Sint16 and stuff like that
#include <time.h>   // Gives access to system time (used to set the seed :D )
#include <SDL/SDL.h>// SDL library
#include <SDL/SDL_gfxPrimitives.h> // SDL gfx library. Yeah, so what. I'm using SDL_gfx. And?
#include <assert.h>

// Defines:
#define true 1
#define false 0
#define bool int

typedef struct 
{
	bool F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12;
	bool ESC, SHIFT, CTRL, ALT, TAB, CAPS;
	bool one, two, three, four, five, six, seven, eight, nine, zero;
	bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
	bool A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
	bool insert, home, delete, end, pgUp, pgDown;
	bool up, down, left, right;
	bool NUMone, NUMtwo, NUMthree, NUMfour, NUMfive, NUMsix, NUMseven, NUMeight, NUMnine, NUMzero;
} keyObj;

keyObj keyInput;

//uint16_t red, green, blue, alpha;

SDL_Event event;
const SDL_VideoInfo* info = NULL;
SDL_Surface *screen;

int colour;
int scrColour;
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
		screen = SDL_SetVideoMode(height, width, bitPerPixel, SDL_DOUBLEBUF |SDL_FULLSCREEN);
		if ( screen == NULL ) 
		{
			
		    fprintf(stderr, "Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
		    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
		    exit(1);
		}
	}
	else
	{
		screen = SDL_SetVideoMode(height, width, bitPerPixel, SDL_DOUBLEBUF);
		if ( screen == NULL ) 
		{
		    fprintf(stderr, "Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
		    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
		    exit(1);
		}
	}

	colour = SDL_MapRGBA(screen->format, 255, 255, 255, 255); // Default colour is white.
	scrColour = SDL_MapRGBA(screen->format, 0, 0, 0, 255); // Default colour is white.
	SDL_WM_SetCaption(name, NULL ); // set the caption, as per the new 4th arg!
	return true;
}

void pixel(int x, int y) // Blatantly copied from the SDL example
{
	SDL_LockSurface(screen);
	int bpp = screen->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = colour;
        break;

    case 2:
        *(Uint16 *)p = colour;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (colour >> 16) & 0xff;
            p[1] = (colour >> 8) & 0xff;
            p[2] = colour & 0xff;
        } else {
            p[0] = colour & 0xff;
            p[1] = (colour >> 8) & 0xff;
            p[2] = (colour >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = colour;
        break;
    }
    SDL_LockSurface(screen);
}

int randomNum(int min, int max)
{	
	return min + (rand() % ((max + 1) - min)); // inclusive :D
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

int setColour(int r, int g, int b, int a)
{
	colour = SDL_MapRGBA(screen->format, r, g, b, a);
	return 0;
}

int setScrColour(int r, int g, int b, int a)
{
	scrColour = SDL_MapRGBA(screen->format, r, g, b, a);
	return 0;
}

void line(int xi, int yi, int xii, int yii) // This needs to be changed to int later on.
{
	int xdelta = xi - xii;
	int ydelta = yi - yii;
	if (xdelta > ydelta)
	{
		SDL_LockSurface(screen);
		
		SDL_UnlockSurface(screen);
	}
	else if (ydelta < xdelta)
	{
		SDL_LockSurface(screen);
		
		SDL_UnlockSurface(screen);
	}

}

int rect(char *type, int16_t x, int16_t y, int16_t w, int16_t h)
{
	if (strcmp(type, "fill") == 0)
	{
		//float 
		//	boxRGBA(screen, x, y, x+w, y+h, red, green, blue, alpha);
		int px, py;
		if (x < x+w)
		{
			for (py = y; py < y+h; py++)
			{
				for (px = x; px < (x+w); px++) 
				{
					pixel(px, py);
				}
				px = x;
			}
		}

	}
	else if (strcmp(type, "line") == 0)
	{
	//	rectangleRGBA(screen, x, y, x+w, y+h, red, green, blue, alpha);	
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

void clear()
{
	assert(screen != NULL);
	SDL_FillRect(screen, NULL, scrColour);
}

void grabKeyInput()
{
	SDL_PollEvent(&event);   //Poll our SDL key event for any keystrokes.
    switch(event.type)
    {
	    case SDL_KEYDOWN:
	    	switch(event.key.keysym.sym)
	    	{
	        	case SDLK_LEFT:
	          		keyInput.left = true;
	          		printf("OH NOES! 1");
	          		break;
	        	case SDLK_RIGHT:
	          		keyInput.right = true;
	          		printf("OH NOES! 1");
	          		break;
	        	case SDLK_UP:
	        		printf("OH NOES! 1");
	          		keyInput.up = true;
	          		break;
	        	case SDLK_DOWN:
	        		printf("OH NOES! 1");
	          		keyInput.down = true;
	          		break;
	        	default:
	          		break;
	    	}
	    	break;
	    case SDL_KEYUP:
	    	switch(event.key.keysym.sym)
	    	{
	        	case SDLK_LEFT:
	        		printf("OH NOES! 2");
	          		keyInput.left = false;
	          		break;
	        	case SDLK_RIGHT:
	        		printf("OH NOES! 2");
	          		keyInput.right = false;
	          		break;
	        	case SDLK_UP:
	        		printf("OH NOES! 2");
	          		keyInput.up = false;
	          		break;
	        	case SDLK_DOWN:
	        		printf("OH NOES! 2");
	          		keyInput.down = false;
	          		break;
		        default:
		          	break;
		    }
	  	case SDL_QUIT:
	  		printf("OH NOES!3");
	  		SDL_Quit();
	  		break;
  	}
}

int update(int FPS)
{
	#ifdef EMSCRIPTEN
	emscripten_set_main_loop(main, FPS, 0);
	#else
	SDL_Flip(screen);
	grabKeyInput();
	return 0;
	#endif
}


// int grabKeyInput()
// {
// 	while( SDL_PollEvent() ){
// 	    /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
// 	    switch( event.type ){
// 	     	case SDL_KEYDOWN:
// 	     		switch(keyevent.key.keysym.sym)
// 	     		{
// 		       		printf("Key press detected\n" );
// 		       	}
// 	        	break;

// 	      	case SDL_KEYUP:
// 	        	printf( "Key release detected\n" );
// 	        	break;

// 	        case SDL_QUIT:
// 	        	SDL_QUIT();
//                 break;
// 	    }
// 	}
//     return 0;
// }

// int grabInput()
// {
	// SDL_WM_GrabInput(SDL_GRAB_ON);  // This makes the window grab all input :P
	// NEVER. NEVER SET THAT UNLESS KYBOARD INPUT HAS BEEN ENABLED, AND YOU HAVE IT TOP CATCH THE ESC BUTTON. OR YOUR PC WILL DIE.
	// It *was* pretty funny, though xD
// }

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