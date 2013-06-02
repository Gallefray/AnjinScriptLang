// Includes:
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
// #include <GL/gl.h>
#include <GL/glu.h>
#include <time.h>
#include <stdio.h>

// Defines:
#define true 1
#define false 0
#define bool int

int red, green, blue, alpha;

// Init the keys
bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, space, enter, tab, shift, ctrl, del;

SDL_Surface *screen;
SDL_Event event;
const SDL_VideoInfo* info = NULL;

// Yes, yes. The library structure is a mess... I will reorganise it when the core libs are in :P

// ------------------------- Init's over, here's the funcs:

// int main(int argc, char** argv) // argc will contain the number of elements in argv, where argv[0] is the executable file itself
// {
	
// }

bool initWindow(int height, int width, bool fullscreen, char *name)
{
	srand(time(NULL));

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init the SDL libs, if there's an error then catch and report it. Yeah, I'm initing all of them, eh.
	{ 
	    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
	    exit(1);
	}

	info = SDL_GetVideoInfo( ); // Retrieve video information
	int bitPerPixel = info->vfmt->BitsPerPixel;  // Grabbing the bpp from the screen now ;)

	if (fullscreen == true)
	{
		if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN) == -1)
		{
			if ( screen == NULL ) 
			{
			    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
			    exit(1);
			}
			return false;
		}
	}
	else
	{
		if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_HWSURFACE | SDL_DOUBLEBUF) == -1)
		{
			if ( screen == NULL ) 
			{
			    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
			    exit(1);
			}
			return false;
		}
	}

	atexit(SDL_Quit);// Clean up everything when the program exits! :D
	SDL_WM_SetCaption(name, NULL ); // set the caption, as per the new 4th arg!

	// SDL_WM_GrabInput(SDL_GRAB_ON);  // This makes the window grab all input :P
	// NEVER. NEVER SET THAT UNLESS KYBOARD INPUT HAS BEEN ENABLED, AND YOU HAVE IT TOP CATCH THE ESC BUTTON. OR YOUR PC WILL DIE.
	// It *was* pretty funny, though xD
	return true;
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

// int error; if((error = glGetError()) != 0) print(AAAHHHHH); print(error)

int setColour(int r, int g, int b, int a)
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
	return 0;
}

int rect(char *type, int x, int y, int w, int h)
{
	int x2 = x + w;
	int y2 = y + h;
	if (strcmp(type, "fill") == 0)
	{
		// ??
	}
	else if (strcmp(type, "line") == 0)
	{
		rectangleRGBA(screen, x, y, x2, y2, red, green, blue, alpha);
	}
	else
	{
		printf("Incorrect first argument given to the rect function! D:\n");
		printf("%s\n", type);
		return 1;
	}

    return 0;
}

int setLineWidth(float width)
{
	// ????
	return 0;
}

int update()//int FPS)
{
	#ifdef EMSCRIPTEN
	emscripten_set_main_loop(main, FPS, 0);
	#else

	SDL_Flip(screen);
	return 0;
	#endif
}

int clear(int r, int g, int b)
{
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, r, g, b));
	return 0;
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