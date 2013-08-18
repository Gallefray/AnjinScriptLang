// Includes:
#include <stdlib.h> // standard C library I believe?
#include <SDL/SDL.h>// SDL library
#include <SDL/SDL_main.h> // for windows
#include <time.h>   // Gives access to system time (used to set the seed :D )
#include <math.h> 	// Pi, sin, cos, tan, etc :D
//#include <limits.h>
// #include <assert.h>
#include "QL.h" // EL.c's header file

// Defines:
#define true 1
#define false 0
#define bool int

typedef struct
{
	int x, y;
	bool button1, button2, button3, button4, button5, button6, button7, button8, button9;
} mouseObj;

typedef struct
{
	SDL_Surface img;
} bmpImg;

// SDL variables needed
SDL_Surface *screen;
SDL_Event event;

// Input
keyObj keyInput;
mouseObj mouseInput;

// Screen 
int scrWidth, scrHeight;
int scrTransX, scrTransY;
int scrScaleX, scrScaleY;
int scrColour;

// Framerate
int FPS, drawTime, timeDelta;
int timeOne, timeTwo;

// Shape displaying stuff
int colour;
int lineWidth;

const SDL_VideoInfo* info = NULL;
// Yes, yes. The library structure is a mess... I will reorganise it when the core libs are in :P

// long round(double x) {
// 	assert(x >= LONG_MIN-0.5);
// 	assert(x <= LONG_MAX+0.5);
// 	if (x >= 0)
// 	  return (long) (x+0.5);
// }

bool initWindow(int width, int height, bool fullscreen, char *name)
{
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init the SDL libs, if there's an error then catch and report it. Yeah, I'm initing all of them, eh.
	{ 
		printf("QuackLang - ERROR:");
	    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
	    exit(1);
	}

	atexit(SDL_Quit);// Clean up everything when the program exits! :D

	info = SDL_GetVideoInfo( ); // Retrieve video information
	int bitPerPixel = info->vfmt->BitsPerPixel;  // Grabbing the bpp from the screen now ;)

	if (fullscreen == true)
	{
		screen = SDL_SetVideoMode(width, height, bitPerPixel, SDL_DOUBLEBUF |SDL_FULLSCREEN);
		if ( screen == NULL ) 
		{
			printf("QuackLang - ERROR:");
		    fprintf(stderr, "Couldn't set %dx%d video mode or mode not supported: %s\n", width, height, SDL_GetError());
		    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", width, height, SDL_GetError());
		    exit(1);
		}
	}
	else
	{
		screen = SDL_SetVideoMode(width, height, bitPerPixel, SDL_DOUBLEBUF);
		if ( screen == NULL ) 
		{
			printf("QuackLang - ERROR:");
		    fprintf(stderr, "Couldn't set %dx%d video mode or mode not supported: %s\n", width, height, SDL_GetError());
		    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", width, height, SDL_GetError());
		    exit(1);
		}
	}

	colour = SDL_MapRGBA(screen->format, 255, 255, 255, 255); // Default colour is white.
	scrColour = SDL_MapRGBA(screen->format, 0, 0, 0, 255); // Default colour is white.
	scrWidth = width;
	scrHeight = height;
	SDL_WM_SetCaption(name, NULL); // set the caption, as per the new 4th arg!
	return true;
}

void clear()
{
	SDL_FillRect(screen, NULL, scrColour);
}

void grabInput()
{
	//printf("bloop\n");
	SDL_PollEvent(&event);   //Poll our SDL key event for any keystrokes.
    switch(event.type)
    {
    	//printf("bleep\n");
	    case SDL_KEYDOWN:
	    	//printf("0 - 1");
	    	switch(event.key.keysym.sym)
	    	{
	    		//printf("0 - 2");
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
	          		keyInput.del = true;
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
	    	//printf("1 - 1");
	    	switch(event.key.keysym.sym)
	    	{
	    		//printf("1 - 2");
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
	          		keyInput.del = false;
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
	  	// case SDL_MOUSEMOTION:
	  	// 	if (event.motion.type)
	   //  	{
  	}
}
#ifdef EMSCRIPTEN
void update(int desFPS, void main)
{
	emscripten_set_main_loop(main, FPS, 0);
	SDL_Flip(screen); // Hmm, does this need to be there? :P
	grabInput();
}

#else

void update() // Desired FPS
{
	timeOne = SDL_GetTicks();
	SDL_Flip(screen); // Draw the shapes/images/whatever
	grabInput();      // Get the input
}
#endif

void capFrameRate(int desFPS)
{
	drawTime = 1000/desFPS;
	timeTwo = SDL_GetTicks();

	timeDelta = (timeTwo - timeOne);
	if (timeDelta < drawTime)
	{
		SDL_Delay(drawTime - timeDelta);
	}
}

void pixel(int x, int y) // Blatantly copied from the SDL example
{
	int nx = x+scrTransX;
	int ny = y+scrTransY;
	if (nx >= 0 && nx < scrWidth && ny >= 0 && ny < scrHeight)
	{
		SDL_LockSurface(screen);
		int bpp = screen->format->BytesPerPixel;
	    /* Here p is the address to the pixel we want to set */
	    Uint8 *p = (Uint8 *)screen->pixels + ny * screen->pitch + nx * bpp; // Uint8

	    switch(bpp) {
	    case 1:
	        *p = colour;
	        break;

	    case 2:
	        *(Uint16 *)p = colour; // Uint16
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
	        *(Uint32 *)p = colour; // Unit32
	        break;
	    }
	    SDL_UnlockSurface(screen);
	}
}

// ----------------------------------------------------------------------
// Collision handling functions START
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
// Collision handling functions END
// ----------------------------------------------------------------------
// Set functions START (Funcs that set variables :D)
void setColour(int r, int g, int b, int a)
{
	colour = SDL_MapRGBA(screen->format, r, g, b, a);
	//printf("bloop");
}

void setScrColour(int r, int g, int b, int a)
{
	scrColour = SDL_MapRGBA(screen->format, r, g, b, a);
}

void setLineWidth(int width)
{
	lineWidth = width;
}
// Set functions END
// ----------------------------------------------------------------------
// Shape functions START
void line(int x0, int y0, int x1, int y1)
{
	// int xi, yi, a; // x increment, y increment, angle
	// int px, py; // pixel x, y
	// int xDelta = abs(x1 - x0); // height
	// int yDelta = abs(y1 - y0); // width
	// a = giveAngle(x0, y0, x1, y1);

	// if (xDelta > yDelta)
	// {
	// 	for (xi = x0; )
	// }
	int rad;
	int px = x0; int py = y0;
	int xDelta = abs(x1 - x0);
	int yDelta = abs(y1 - y0);
	
	float angle = giveAngle(x0, y0, x1, y1);
	for (rad = 0;  (abs(px) <= abs(xDelta) && xDelta != 0) || (abs(py) <= abs(yDelta) && yDelta != 0); rad++)
	{
		px = cos(angle)*rad + x0;
		py = sin(angle)*rad + y0;
		pixel(px, py);
	}

}

bool rect(char *type, int x, int y, int w, int h)
{
	if (strcmp(type, "fill") == 0)
	{
		int px, py;
		for (py = y; py < y+h; py++)
		{
			for (px = x; px < (x+w); px++) 
			{
				pixel(px, py);
			}
			px = x;
		}
	}
	else if (strcmp(type, "line") == 0)
	{
		line(x, y, x+w, y);     // The top line
		line(x, y, x, y+h);     // The left line
		line(x, y+h, x+w, y+h); // The bottom line
		line(x+w, y, x+w, y+h); // The right line
	}
	else
	{
		printf("QuackLang - ERROR:");
		printf("Incorrect first argument given to the rect function! D:\n");
		printf("You gave %s\n", type);
		printf("Only 'line' or 'fill' can be accepted.");
		return false;
	}
	return true;
}

bool circle(char *type, int x, int y, float radius)
{
	float maxDegrees = 360.0;
	float r, angle;
	int px, py;
	if (strcmp(type, "line") == 0)
	{
		for (angle = 0.0; angle <= maxDegrees; angle += 1.0)
		{
			px = (cosf(angle)*radius + x);
			py = (sinf(angle)*radius + y);
			pixel(px, py);
		}
	}
	else if (strcmp(type, "fill") == 0)
	{
		// This might be an inefficient way of doing it, but I'm aiming for readability at this stage ;)
		// Step back through the radius until it becomes 0 and the entire circle has been plot

		//Scratch that. This needs MASSIVE optimisation. :O 
		for (r = radius; r >= 0; r -= 1.0)
		{
			for (angle = 0.0; angle <= maxDegrees; angle += 1.0)
			{
				px = (cosf(angle)*r + x);
				py = (sinf(angle)*r + y);
				pixel(px, py);
			}
		}
	}
	else
	{
		printf("QuackLang - ERROR:");
		printf("Incorrect first argument given to the rect function! D:\n");
		printf("You gave %s\n", type);
		printf("Only 'line' or 'fill' can be accepted.");
		return false;
	}
	return true;
}

bool ellipse(char *type, int x, int y, int w, int h)
{
	float maxDegrees = 360.0;
	float angle;
	int px, py;
	if (strcmp(type, "line") == 0)
	{
		for (angle = 0.0; angle <= maxDegrees; angle += 1.0)
		{
			px = (cosf(angle)*w + x);
			py = (sinf(angle)*h + y);
			pixel(px, py);
		}
	}
	// else if (strcmp(type, "fill") == 0)
	// {
	// 	// This might be an inefficient way of doing it, but I'm aiming for readability at this stage ;)
	// 	// Step back through the radius until it becomes 0 and the entire circle has been plot

	// 	// Scratch that. This needs MASSIVE optimisation. :O 
	// 	for (r = radius; r >= 0; r -= 1.0)
	// 	{
	// 		for (angle = 0.0; angle <= maxDegrees; angle += 1.0)
	// 		{
	// 			px = (cosf(angle)*w + x);
	// 			py = (sinf(angle)*h + y);
	// 			pixel(px, py);
	// 		}
	// 	}
	// }
	else
	{
		printf("QuackLang - ERROR:");
		printf("Incorrect first argument given to the rect function! D:\n");
		printf("You gave %s\n", type);
		printf("Only 'line' can be accepted.");
		return false;
	}
	return true;
}
// Shape functions END
// ----------------------------------------------------------------------
// Misc functions START
float degreesToRadians(float deg) // Should go in QLmath
{
	return deg * M_PI / 180;
}

float radiansToDegrees(float rad) // Should go in QLmath
{
	return rad * 180 / M_PI;
}

float giveAngle(int x0, int y0, int x1, int y1) // Where z0 is the center and z1 are the coordinates you want the angle for.
{
	int xA = x1 - x0;
	int yA = y1 - y0;
	return atan2(yA, xA); // Returns it in Rad
}

int randomNum(int min, int max) // Should go in QLmath
{	
	return min + (rand() % ((max + 1) - min)); // inclusive :D
}

float randomNumF(float min, float max) // Should go in QLmath
{
	return ( rand() / (float)RAND_MAX * max ) + min; // Thanks to evilBetty from #ludumdare (This is inclusive)
}

// bool noiseGen(double *noise, double width, double height) // QLmath
// {
// 	int x, y;
// 	for (x = 0; x < width; x++)
// 	{
// 		for (y = 0; y < height; y++)
// 		{
// 			noise[x][y] = (rand() % 32768) / 32768.0;
// 		}
// 	}
// 	return true;
// }

// double smoothNoise(double *noise, double x, double y, double width, double height) // QLrand
// {  
// 	double fractX = x - int(x);
// 	double fractY = y - int(y);
   
// 	int x1 = x + width) % width;
// 	int y1 = y + height) % height;
	
// 	int x2 = (x1 + width - 1) % width;
// 	int y2 = (y1 + height - 1) % height;

// 	//smooth the noise!!! :D
// 	double value = 0.0;
// 	value += fractX * fractY * noise[x1][y1];
// 	value += fractX * (1 - fractY) * noise[x1][y2];
// 	value += (1 - fractX) * fractY * noise[x2][y1];
// 	value += (1 - fractX) * (1 - fractY) * noise[x2][y2];

//    return value;
// }

// double turbulentNoise(double x, double y, double scale) // QLrand
// {
//     double value = 0.0, initialScale = scale;
    
//     while(scale >= 1)
//     {
//         value += smoothNoise(x / scale, y / scale) * scale;
//         scale /= 2.0;
//     }
    
//     return(128.0 * value / initialScale);
// }

// bool noiseDraw(char *type, double noise[][], double width, double height, double scale) // QLrand
// {
// 	int r, g, b;
// 	int x, y;
// 	if(strcmp(type, "normal") || strcmp(type, "Normal"))
// 	{
// 		if (scale == 0)
// 		{ 
// 			for(x = 0; x < width; x++)
// 			{
//     			for(y = 0; y < height; y++)
//     			{
//     				r = g = b = int(256 * noise[x][y]);
//     				setColour(r, g, b, 255);
//         			pixel(x, y);
//     			}
// 			}
//     	}
//     	else 
//     	{
//     		for(x = 0; x < width; x++)
// 			{
//     			for(y = 0; y < height; y++)
//     			{
//     				r = g = b = int(256 * noise[x / scale][y / scale]);
//     				setColour(r, g, b, 255);
//         			pixel(x, y);
//     			}
// 			}
//     	}     
        
//     }
//     else if (strcmp(type, "smooth") || strcmp(type, "Smooth"))
//     {
//     	if (scale == 0)
// 		{ 
// 			for(x = 0; x < width; x++)
// 			{
//     			for(y = 0; y < height; y++)
//     			{
//     				r = g = b = int(256 * smoothNoise(noise[][], x, y, width, height));
//     				setColour(r, g, b, 255);
//         			pixel(x, y);
//     			}
// 			}
//     	}
//     	else 
//     	{
//     		for(x = 0; x < width; x++)
// 			{
//     			for(y = 0; y < height; y++)
//     			{
//     				r = g = b = int(256 * smoothNoise(noise[][], x / scale, y / scale, width, height));
//     				setColour(r, g, b, 255);
//         			pixel(x, y);
//     			}
// 			}
//     	}  
//     }
//     else if (strcmp(type, "turbulence") || strcmp(type, "Turbulence"))
//     {
//     	if (scale == 0)
//     	{
//     		printf("QuackLang - ERROR:");
//     		printf("Invalid argument given! For turbulent noise, scale must be > 0");
//     		return false;
//     	}
//     	else
//     	{
//     		r = g = b = int(256 * turbulentNoise(x, y, scale));
//     		setColour(r, g, b, 255);
//         	pixel(x, y);
//     	}
//     }
//     return true;
// }
// Misc functions END
// ----------------------------------------------------------------------
// Image functions START
// void loadBMP()