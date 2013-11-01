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

	initWindow(800, 600, false, "test :3");
	setScrColour(30, 30, 30, 255);
	while (!keyInput.ESC)
	{
		scale(.9, .9);
		clear();
		setColour(255, 0, 0, 150);
		rect("fill", 200, 200, 32, 32);
		setColour(0, 255, 0, 150);
		rect("line", 30, 30, 32, 32);
		line(100, 100, 200, 200);     
		rect("fill", 900, 300, 30, 30); 
		// ^ still not drawing if it's outside the window 
		// and I move the viewport so it should draw :S

		update();
		// w = cos(angle)*rad + x;
		// h = sin(angle)*rad + y;
		if (keyInput.up)
		{
			scrTransY -= 20;
		}
		if (keyInput.down)
		{
			scrTransY += 20;
		}
		if (keyInput.left)
		{
		 	scrTransX -= 20;
		}
		if (keyInput.right)
		{
			scrTransX += 20;
		}
		capFrameRate(60);
	}
	quitQL();
	printf("\n");
	return 0;
}