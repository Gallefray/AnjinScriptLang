#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "ASL.h"

int main()
{
	initWindow(800, 600, false, "test :3");
	int i = 0;
	while (i < 900)
	{
		grabKeyInput();

		// clear();
		// setLineWidth(20);
		// setColour(255.0, 0.0, 0.0, 0.0);
		// rect("fill", 10.0, 10.0, 10.0, 10.0);
		// update(30);
		// glFlush();
		
	    //Clear color buffer
	    glClear( GL_COLOR_BUFFER_BIT );

	    //Render quad
	    if( renderQuad == true )
	    {
	        glBegin( GL_QUADS );
	            glVertex2f( -0.5f, -0.5f );
	            glVertex2f(  0.5f, -0.5f );
	            glVertex2f(  0.5f,  0.5f );
	            glVertex2f( -0.5f,  0.5f );
	        glEnd();
	    }

	    //Update screen
	    SDL_GL_SwapBuffers();
	}
		i++;
	}
}