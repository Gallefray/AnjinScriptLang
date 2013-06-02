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

		clear();
		// setLineWidth(20);
		setColour(255, 0, 0, 0);
		//rect("line", 10.0, 10.0, 10.0, 10.0);
		update();
		// glFlush();

	    //Update screen
	    
	i++;
	}
}