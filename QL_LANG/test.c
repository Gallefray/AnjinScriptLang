#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int x, y, w, h, rad; 
float angle;

int main(int argc, char *argv[])
{
	// x = 200;
	// y = 200;
	// angle = 0;
	// rad = 100;

	initWindow(800, 600, false, "test :3");
	setScrColour(250, 250, 250, 255);
	while (!keyInput.ESC)
	{
		clear();
		setColour(255, 0, 0, 150);
		rect("fill", 20, 20, 32, 32);
		setColour(0, 255, 0, 150);
		rect("fill", 30, 30, 32, 32);
		line(100, 100, 200, 200);
		pixel(scrWidth/2, scrHeight/2);

		update();
		// w = cos(angle)*rad + x;
		// h = sin(angle)*rad + y;
		// if(keyInput.left)
		// {
		// 	angle -= 0.01; 
		// }
		// if(keyInput.right)
		// {
		// 	angle += 0.01;
		// }
		// capFrameRate(60);
	}
	quitQL();
	printf("\n");
	return 0;
}