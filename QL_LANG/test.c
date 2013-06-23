#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int main()
{
	//assert(screen != NULL); // Error above here!!!!
	initWindow(1024, 768, false, "test :3");
	// printf("^ error");
	int i;
	for (i = 0; i < 900; i++)
	{
		setColour(255, 0, 0, 255);
		rect("fill", 10, 10, 50, 50);
		update(25);
	    //Update screen
	}
	return 0;
}