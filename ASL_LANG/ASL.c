// Includes:
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
// #include <GL/gl.h>
// #include <GL/glu.h>
#include <time.h>
#include <stdio.h>

// Defines:
#define true 1
#define false 0
#define bool int
SDL_Surface *screen;
const SDL_VideoInfo* info = NULL;

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
    info = SDL_GetVideoInfo( ); // Retrieve video information
}

bool initWindow(int height, int width, bool fullscreen, char *name)
{
	int bitPerPixel = info->vfmt->BitsPerPixel;  // Grabbing the bpp from the screen now ;)

	if (fullscreen == true)
	{
		if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_OPENGL|SDL_FULLSCREEN) == -1)
		{
			if ( screen == NULL ) 
			{
			    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
			    exit(1);
			}
			return;
		}
	}
	else
	{
		if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_OPENGL) == -1)
		{
			if ( screen == NULL ) 
			{
			    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
			    exit(1);
			}
			return;
		}
	}

	SDL_WM_SetCaption(name, NULL ); // set the caption, as per the new 4th arg!

	// SDL_WM_GrabInput(SDL_GRAB_ON);  // This makes the window grab all input :P
	// NEVER. NEVER SET THAT UNLESS KYBOARD INPUT HAS BEEN ENABLED, AND YOU HAVE IT TOP CATCH THE ESC BUTTON. OR YOUR PC WILL DIE.
	// It *was* pretty funny, though xD
}

int randomNum(int min, int max)
{	
	//(rand()%max);
	return min+(rand()%((max+1)-min)); // inclusive :D
}

bool rectRectCollision(float Ax, float Ay, float Ah, float Aw, float Bx, float By, float Bh, float Bw)
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

rect(int x, int y, int w, int h)
{
	glRecti(x, y, (x+w), (y + h));
}

// int doStuff = 0;
// char keyboardInput()
// {
//     SDL_Event event;
//     while(SDL_PollEvent(&event) )
//     {
//         if(event.type == SDLK_KEYDOWN)
//         {
//                 switch(event.key.keysym.sym)
//                 {
//                     case SDLK_RETURN:
//                         doStuff = 1
//                         break;
//                     default:
//                         break;
//                 }
//         }
//         if(event.type == SDLK_KEYUP)
//         {
//                 switch(event.key.keysym.sym)
//                 {
//                     case SDLK_RETURN:
//                         doStuff = 0;
//                         break;
//                     default:
//                         break;
//                 }
//         }
//     }   
// }