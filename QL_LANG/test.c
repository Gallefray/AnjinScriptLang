#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

SDL_Surface *screen;

int main()
{
	initWindow(800, 600, false, "test :3");
	// printf("^ error");
	int i;
	for (i = 0; i < 900; i++)
	{
		setColour(255, 0, 0, 0);
		rect("line", 10, 10, 10, 10);
		update(25);
	    //Update screen
	}
	return 0;
}