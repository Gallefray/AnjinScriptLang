#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int x, y, w, h, rad; 
float angle;

int main(int argc, char *argv[])
{
	x = 200;
	y = 200;
	// angle = 0;
	// rad = 100;

	initWindow(1280, 1024, false, "test :3");
	setScrColour(30, 30, 30, 255);
	while (!keyInput.ESC)
	{
		clear();
		setColour(255, 0, 0, 150);
		rect("fill", x, y, 32, 32);
		setColour(0, 255, 0, 150);
		rect("line", 30, 30, 32, 32);
		line(100, 100, 200, 200);     

		update();
		// w = cos(angle)*rad + x;
		// h = sin(angle)*rad + y;
		if(keyInput.left)
		{
		 	x -= 2;
		}
		if(keyInput.right)
		{
			x += 2;
		}
		capFrameRate(60);
	}
	quitQL();
	printf("\n");
	return 0;
}