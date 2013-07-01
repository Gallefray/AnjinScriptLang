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
	for (i = 0; i < 900; i++)
	{
		setColour(255, 0, 0, 255);
		pixel(10, 10);
		update(25);
	    //Update screen
	}
	return 0;
}