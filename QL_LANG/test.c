#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int main()
{
	//assert(screen != NULL); // Error above here!!!!
	initWindow(480, 320, false, "test :3");
	// printf("^ error");
	int i;
	// int rectX = 20; 
	setColour(255, 0, 0, 255);
	for (i = 0; i < 1000; i++)
	{
		clear();
		rect("fill", 20, 20, 50, 50);
		update(25);
		// rectX++;
	    //Update screen
	}
	return 0;
}