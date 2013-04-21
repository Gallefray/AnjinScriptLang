// Help given by: #ludumdare(Trangar(rand), Mario(CLI args), Fififox(gcc Commands), ninzine(gcc Commands))
// Requests by: #ludumdare(Cellusious(rand))

// Includes:
#include <SDL/SDL.h>
#include <time.h>
#include <stdio.h>

// Defines:
#define true 1
#define false 0
#define bool int
SDL_Surface *screen;

// Function definitions:
int randomNum(int min, int max);
bool initWindow(int height, int width, bool fullscreen, int bitPerPixel);


// ------------------------- Init's over, here's the funcs:

int main(int argc, char** argv) // argc will contain the number of elements in argv, where argv[0] is the executable file itself
{
	srand(time(NULL));

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init the SDL libs, if there's an error then catch and report it. Yeah, I'm initing all of them, eh.
	{ 
	    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
	    exit(1);
	}
	atexit(SDL_Quit);// Clean up everything when the program exits! :D
}

bool initWindow(int height, int width, bool fullscreen, int bitPerPixel)
{
	if (bitPerPixel == 0 || bitPerPixel == NULL )
	{
		bitPerPixel = 32;
	}

	if (fullscreen == true)
	{
		if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_HWSURFACE|SDL_FULLSCREEN) == -1)
		{
			printf("ASL | error. Maybe video memory rendering not supported on this system? Switching to system memory");
			if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_SWSURFACE|SDL_FULLSCREEN) == -1)
			{	
				if ( screen == NULL ) 
				{
				    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
				    exit(1);
				}
				return;
			}
		}
	}
	else
	{
		if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_HWSURFACE) == -1)
		{
			printf("ASL | error. Maybe video memory rendering not supported on this system? Switching to system memory");
			if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_SWSURFACE) == -1)
			{	
				if ( screen == NULL ) 
				{
				    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
				    exit(1);
				}
				return;
			}
		}
	}
}

int randomNum(int min, int max)
{	
	//(rand()%max);
	return min+(rand()%((max+1)-min)); // inclusive :D
}