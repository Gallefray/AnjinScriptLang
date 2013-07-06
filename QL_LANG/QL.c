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
	bool F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12; // Handled
	bool ESC, lSHIFT, rSHIFT, lCTRL, rCTRL, lWIN, rWIN, lALT, rALT, CAPS, NUM; // Handled
	bool one, two, three, four, five, six, seven, eight, nine, zero; // Handled
	bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z; // Handled
	bool tab, insert, home, delete, end, pgUp, pgDown, backspace; // Handled
	bool up, down, left, right; // Handled
	bool NUMone, NUMtwo, NUMthree, NUMfour, NUMfive, NUMsix, NUMseven, NUMeight, NUMnine, NUMzero; // Handled
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
	    		// Function keys start;
	    		case SDLK_F1:
	    			keyInput.F1 = true;
	    			break;
	    		case SDLK_F2:
	    			keyInput.F2 = true;
	    			break;
	    		case SDLK_F3:
	    			keyInput.F3 = true;
	    			break;
	    		case SDLK_F4:
	    			keyInput.F4 = true;
	    			break;
	    		case SDLK_F5:
	    			keyInput.F5 = true;
	    			break;
	    		case SDLK_F6:
	    			keyInput.F6 = true;
	    			break;
	    		case SDLK_F7:
	    			keyInput.F7 = true;
	    			break;
	    		case SDLK_F8:
	    			keyInput.F8 = true;
	    			break;
	    		case SDLK_F9:
	    			keyInput.F9 = true;
	    			break;
	    		case SDLK_F10:
	    			keyInput.F10 = true;
	    			break;
	    		case SDLK_F11:
	    			keyInput.F11 = true;
	    			break;
	    		case SDLK_F12:
	    			keyInput.F12 = true;
	    			break;
	    		// Function keys end;
	    		// Control Keys start;
	    		case SDLK_ESCAPE:
	          		keyInput.ESC = true;
	          		break;
	          	case SDLK_LSHIFT:
	          		keyInput.lSHIFT = true;
	          		break;
	          	case SDLK_RSHIFT:
	          		keyInput.rSHIFT = true;
	          		break;
	          	case SDLK_LCTRL:
	          		keyInput.lCTRL = true;
	          		break;
	          	case SDLK_RCTRL:
	          		keyInput.rCTRL = true;
	          		break;
	          	case SDLK_LSUPER:
	          		keyInput.lWIN = true;
	          		break;
	          	case SDLK_RSUPER:
	          		keyInput.rWIN = true;
	          		break;
	          	case SDLK_LALT:
	          		keyInput.lALT = true;
	          		break;
	          	case SDLK_RALT:
	          		keyInput.rALT = true;
	          		break;
	          	case SDLK_CAPSLOCK:
	            	keyInput.CAPS = true;
	            	break;
	            case SDLK_NUMLOCK:
	            	keyInput.NUM = true;
	            	break;
	          	// Control Keys end;
	          	// Number Keys start;
	          	case SDLK_0:
	          		keyInput.zero = true;
	          		break;
	          	case SDLK_1:
	          		keyInput.one = true;
	          		break;
	          	case SDLK_2:
	          		keyInput.two = true;
	          		break;
	          	case SDLK_3:
	          		keyInput.three = true;
	          		break;
	          	case SDLK_4:
	          		keyInput.four = true;
	          		break;
	          	case SDLK_5:
	          		keyInput.five = true;
	          		break;
	          	case SDLK_6:
	          		keyInput.six = true;
	          		break;
	          	case SDLK_7:
	          		keyInput.seven = true;
	          		break;
	          	case SDLK_8:
	          		keyInput.eight = true;
	          		break;
	          	case SDLK_9:
	          		keyInput.nine = true;
	          		break;
	          	// Number Keys end;
	          	// Letter Keys start;
	          	case SDLK_a:
	          		keyInput.a = true;
	          		break;
	          	case SDLK_b:
	          		keyInput.b = true;
	          		break;
	          	case SDLK_c:
	          		keyInput.c = true;
	          		break;
	          	case SDLK_d:
	          		keyInput.d = true;
	          		break;
	          	case SDLK_e:
	          		keyInput.e = true;
	          		break;
	          	case SDLK_f:
	          		keyInput.f = true;
	          		break;
	          	case SDLK_g:
	          		keyInput.g = true;
	          		break;
	          	case SDLK_h:
	          		keyInput.h = true;
	          		break;
	          	case SDLK_i:
	          		keyInput.i = true;
	          		break;
	          	case SDLK_j:
	          		keyInput.j = true;
	          		break;
	          	case SDLK_k:
	          		keyInput.k = true;
	          		break;
	          	case SDLK_l:
	          		keyInput.l = true;
	          		break;
	          	case SDLK_m:
	          		keyInput.m = true;
	          		break;
	          	case SDLK_n:
	          		keyInput.n = true;
	          		break;
	          	case SDLK_o:
	          		keyInput.o = true;
	          		break;
	          	case SDLK_p:
	          		keyInput.p = true;
	          		break;
	          	case SDLK_q:
	          		keyInput.q = true;
	          		break;
	          	case SDLK_r:
	          		keyInput.r = true;
	          		break;
	          	case SDLK_s:
	          		keyInput.s = true;
	          		break;
	          	case SDLK_t:
	          		keyInput.t = true;
	          		break;
	          	case SDLK_u:
	          		keyInput.u = true;
	          		break;
	          	case SDLK_v:
	          		keyInput.v = true;
	          		break;
	          	case SDLK_w:
	          		keyInput.w = true;
	          		break;
	          	case SDLK_x:
	          		keyInput.x = true;
	          		break;
	          	case SDLK_y:
	          		keyInput.y = true;
	          		break;
	          	case SDLK_z:
	          		keyInput.z = true;
	          		break;
	          	// Letter Keys end;
	          	// Editing Keys start;
		      	case SDLK_TAB:
	          		keyInput.tab = true;
	          		break;
	          	case SDLK_INSERT:
	          		keyInput.insert = true;
	          		break;
	          	case SDLK_HOME:
	           		keyInput.home = true;
	           		break;
	           	case SDLK_DELETE:
	          		keyInput.delete = true;
	          		break;
	           	case SDLK_END:
	           		keyInput.end = true;
	           		break;
	           	case SDLK_PAGEUP:
	           		keyInput.pgUp = true;
	           		break;
	           	case SDLK_PAGEDOWN:
	           		keyInput.pgDown = true;
	           		break;
	           	case SDLK_BACKSPACE:
	          		keyInput.backspace = true;
	          		break;
	          	// Editing Keys end;
	          	// Keypad Number Keys start;
	          	case SDLK_KP0:
	          		keyInput.NUMzero = true;
	          		break;
	          	case SDLK_KP1:
	          		keyInput.NUMone = true;
	          		break;
	          	case SDLK_KP2:
	          		keyInput.NUMtwo = true;
	          		break;
	          	case SDLK_KP3:
	          		keyInput.NUMthree = true;
	          		break;
	          	case SDLK_KP4:
	          		keyInput.NUMfour = true;
	          		break;
	          	case SDLK_KP5:
	          		keyInput.NUMfive = true;
	          		break;
	          	case SDLK_KP6:
	          		keyInput.NUMsix = true;
	          		break;
	          	case SDLK_KP7:
	          		keyInput.NUMseven = true;
	          		break;
	          	case SDLK_KP8:
	          		keyInput.NUMeight = true;
	          		break;
	          	case SDLK_KP9:
	          		keyInput.NUMnine = true;
	          		break;
	          	// Keypad Number Keys end;
	          	// Arrow Keys start;
	           	case SDLK_LEFT:
	          		keyInput.left = true;
	          		break;
	        	case SDLK_RIGHT:
	          		keyInput.right = true;
	          		break;
	        	case SDLK_UP:
	          		keyInput.up = true;
	          		break;
	        	case SDLK_DOWN:
	          		keyInput.down = true;
	          		break;
	          	// Arrow Keys end;

	        	default:
	          		break;
	    	}
	    	break;
	    case SDL_KEYUP:
	    	switch(event.key.keysym.sym)
	    	{
	    		// Function keys start;
	    		case SDLK_F1:
	    			keyInput.F1 = false;
	    			break;
	    		case SDLK_F2:
	    			keyInput.F2 = false;
	    			break;
	    		case SDLK_F3:
	    			keyInput.F3 = false;
	    			break;
	    		case SDLK_F4:
	    			keyInput.F4 = false;
	    			break;
	    		case SDLK_F5:
	    			keyInput.F5 = false;
	    			break;
	    		case SDLK_F6:
	    			keyInput.F6 = false;
	    			break;
	    		case SDLK_F7:
	    			keyInput.F7 = false;
	    			break;
	    		case SDLK_F8:
	    			keyInput.F8 = false;
	    			break;
	    		case SDLK_F9:
	    			keyInput.F9 = false;
	    			break;
	    		case SDLK_F10:
	    			keyInput.F10 = false;
	    			break;
	    		case SDLK_F11:
	    			keyInput.F11 = false;
	    			break;
	    		case SDLK_F12:
	    			keyInput.F12 = false;
	    			break;
	    		// Function keys end;
	    		// Control Keys start;
	    		case SDLK_ESCAPE:
	          		keyInput.ESC = true;
	          		break;
	          	case SDLK_LSHIFT:
	          		keyInput.lSHIFT = true;
	          		break;
	          	case SDLK_RSHIFT:
	          		keyInput.rSHIFT = true;
	          		break;
	          	case SDLK_LCTRL:
	          		keyInput.lCTRL = true;
	          		break;
	          	case SDLK_RCTRL:
	          		keyInput.rCTRL = true;
	          		break;
	          	case SDLK_LALT:
	          		keyInput.lALT = true;
	          		break;
	          	case SDLK_RALT:
	          		keyInput.rALT = true;
	          		break;
	          	case SDLK_CAPSLOCK:
	            	keyInput.CAPS = true;
	            	break;
	            case SDLK_NUMLOCK:
	            	keyInput.NUM = true;
	            	break;
	          	// Control Keys end;
	          	// Number Keys start;
	          	case SDLK_0:
	          		keyInput.zero = false;
	          		break;
	          	case SDLK_1:
	          		keyInput.one = false;
	          		break;
	          	case SDLK_2:
	          		keyInput.two = false;
	          		break;
	          	case SDLK_3:
	          		keyInput.three = false;
	          		break;
	          	case SDLK_4:
	          		keyInput.four = false;
	          		break;
	          	case SDLK_5:
	          		keyInput.five = false;
	          		break;
	          	case SDLK_6:
	          		keyInput.six = false;
	          		break;
	          	case SDLK_7:
	          		keyInput.seven = false;
	          		break;
	          	case SDLK_8:
	          		keyInput.eight = false;
	          		break;
	          	case SDLK_9:
	          		keyInput.nine = false;
	          		break;
	          	// Number Keys end;
	          	// Letter Keys start;
	          	case SDLK_a:
	          		keyInput.a = false;
	          		break;
	          	case SDLK_b:
	          		keyInput.b = false;
	          		break;
	          	case SDLK_c:
	          		keyInput.c = false;
	          		break;
	          	case SDLK_d:
	          		keyInput.d = false;
	          		break;
	          	case SDLK_e:
	          		keyInput.e = false;
	          		break;
	          	case SDLK_f:
	          		keyInput.f = false;
	          		break;
	          	case SDLK_g:
	          		keyInput.g = false;
	          		break;
	          	case SDLK_h:
	          		keyInput.h = false;
	          		break;
	          	case SDLK_i:
	          		keyInput.i = false;
	          		break;
	          	case SDLK_j:
	          		keyInput.j = false;
	          		break;
	          	case SDLK_k:
	          		keyInput.k = false;
	          		break;
	          	case SDLK_l:
	          		keyInput.l = false;
	          		break;
	          	case SDLK_m:
	          		keyInput.m = false;
	          		break;
	          	case SDLK_n:
	          		keyInput.n = false;
	          		break;
	          	case SDLK_o:
	          		keyInput.o = false;
	          		break;
	          	case SDLK_p:
	          		keyInput.p = false;
	          		break;
	          	case SDLK_q:
	          		keyInput.q = false;
	          		break;
	          	case SDLK_r:
	          		keyInput.r = false;
	          		break;
	          	case SDLK_s:
	          		keyInput.s = false;
	          		break;
	          	case SDLK_t:
	          		keyInput.t = false;
	          		break;
	          	case SDLK_u:
	          		keyInput.u = false;
	          		break;
	          	case SDLK_v:
	          		keyInput.v = false;
	          		break;
	          	case SDLK_w:
	          		keyInput.w = false;
	          		break;
	          	case SDLK_x:
	          		keyInput.x = false;
	          		break;
	          	case SDLK_y:
	          		keyInput.y = false;
	          		break;
	          	case SDLK_z:
	          		keyInput.z = false;
	          		break;
	          	// Letter Keys end;
	          	// Editing Keys start;
		      	case SDLK_TAB:
	          		keyInput.tab = false;
	          		break;
	          	case SDLK_INSERT:
	          		keyInput.insert = false;
	          		break;
	          	case SDLK_HOME:
	           		keyInput.home = false;
	           		break;
	           	case SDLK_DELETE:
	          		keyInput.delete = false;
	          		break;
	           	case SDLK_END:
	           		keyInput.end = false;
	           		break;
	           	case SDLK_PAGEUP:
	           		keyInput.pgUp = false;
	           		break;
	           	case SDLK_PAGEDOWN:
	           		keyInput.pgDown = false;
	           		break;
	           	case SDLK_BACKSPACE:
	          		keyInput.backspace = false;
	          		break;
	          	// Editing Keys end;
	          	// Keypad Number Keys start;
	          	case SDLK_KP0:
	          		keyInput.NUMzero = false;
	          		break;
	          	case SDLK_KP1:
	          		keyInput.NUMone = false;
	          		break;
	          	case SDLK_KP2:
	          		keyInput.NUMtwo = false;
	          		break;
	          	case SDLK_KP3:
	          		keyInput.NUMthree = false;
	          		break;
	          	case SDLK_KP4:
	          		keyInput.NUMfour = false;
	          		break;
	          	case SDLK_KP5:
	          		keyInput.NUMfive = false;
	          		break;
	          	case SDLK_KP6:
	          		keyInput.NUMsix = false;
	          		break;
	          	case SDLK_KP7:
	          		keyInput.NUMseven = false;
	          		break;
	          	case SDLK_KP8:
	          		keyInput.NUMeight = false;
	          		break;
	          	case SDLK_KP9:
	          		keyInput.NUMnine = false;
	          		break;
	          	// Keypad Number Keys end;
	          	// Arrow Keys start;
	           	case SDLK_LEFT:
	          		keyInput.left = false;
	          		break;
	        	case SDLK_RIGHT:
	          		keyInput.right = false;
	          		break;
	        	case SDLK_UP:
	          		keyInput.up = false;
	          		break;
	        	case SDLK_DOWN:
	          		keyInput.down = false;
	          		break;
	          	// Arrow Keys end;
		        default:
		          	break;
		    }
		// Ladies and gentlemen, I give you, the one, the only. SEG FAULT ROOT CAUSE!!!!!!! (Now commented out)
	  	case SDL_QUIT:
	  	//	SDL_Quit();
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