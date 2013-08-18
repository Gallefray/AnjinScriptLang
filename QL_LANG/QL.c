#include "QL.h" // QL.c's header file


SDL_Surface *screen;

// Screen 
int scrWidth, scrHeight;
int scrTransX, scrTransY;
int scrScaleX, scrScaleY;
int scrColour;
int colour; // It should be in QLshapes.c but it gets set upon initWindow, so...

// Framerate
int FPS, drawTime, timeDelta;
int timeOne, timeTwo;

const SDL_VideoInfo* info = NULL;

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

void setScrColour(int r, int g, int b, int a)
{
	scrColour = SDL_MapRGBA(screen->format, r, g, b, a);
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