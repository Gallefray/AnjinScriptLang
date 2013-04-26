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

// int red, green, blue, alpha;


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
		if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_OPENGL|SDL_FULLSCREEN) == -1)
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
		if (SDL_SetVideoMode(height, width, bitPerPixel, SDL_OPENGL) == -1)
		{
			if ( screen == NULL ) 
			{
			    printf("Couldn't set %dx%d video mode or mode not supported: %s\n", height, width, SDL_GetError());
			    exit(1);
			}
			return false;
		}
	}

	//Initialize OpenGL:
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    // gluPerspective(45.0f, ar, 1.0f, 100.0f);

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // setup depth buffer
    glClearDepth(1.0f);						
	glEnable(GL_DEPTH_TEST);						
	glDepthFunc(GL_LEQUAL);	

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glShadeModel(GL_SMOOTH);

	glOrtho(0,1,1,0,-1,1);  // Thanks to wzl. This should set the co ordinate system to the top left ^______^
	glViewport(0, 0, height, width);
    // GLenum error = glGetError();  // Error catching :3
    // if( error != GL_NO_ERROR )
    // {
    //     printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
    //     return false;
    // }

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

int setColour(float r, float g, float b, float a)
{
	return 0;
	glColor4f(r, g, b, a);
}

int rect(char *type, float x, float y, float w, float h)
{
	if (strcmp(type, "fill") == 0)
	{
	// glBegin( GL_QUADS );
		// 	glColor4i(red, green, blue, alpha); // set colour
		// 	glVertex2f(x, y); 
		// 	glVertex2f(x, y+h); 
		// 	glVertex2f(x+w, y+h); 
		// 	glVertex2f(x+w, y);
  	//     glEnd();
		glRectf(x, y, x+w, y+h);

	}
	else if (strcmp(type, "line") == 0)
	{
		glBegin( GL_LINE );
			// Top side:
            glVertex2f(x, y);
            glVertex2f(x+w, y);
            //fprintf(stdout, "WOOO WHEEE WOOO");

            // Left side:
            glVertex2f(x, y);
            glVertex2f(x,  y+h);

            // bottom side:
            glVertex2f(x, y+h);
            glVertex2f(x+w, y+h);

            // Right side:
            glVertex2f(x+w, y);
            glVertex2f(x+w, y+w);
        glEnd();
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
	glLineWidth(width);
	return 0;
}

int clear()
{
	glClear( GL_COLOR_BUFFER_BIT );
	return 0;
}

int update(int FPS)
{
	#ifdef EMSCRIPTEN
	emscripten_set_main_loop(main, FPS, 0);
	#else

	SDL_GL_SwapBuffers();
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