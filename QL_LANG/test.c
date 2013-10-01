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
	angle = 0;
	rad = 100;

	initWindow(400, 400, false, "test :3");
	while (keyInput.ESC != true)
	{
		clear();

		setColour(255, 0, 0, 255);
		line(x, y, h, w);
		pixel(x, y);
		setColour(0, 255, 0, 255);
		pixel(h, w);
		//circle("line", x, y, rad);

		update();
		w = cos(angle)*rad + x;
		h = sin(angle)*rad + y;
		if(keyInput.left)
		{
			angle -= 0.01; 
		}
		if(keyInput.right)
		{
			angle += 0.01;
		}
		capFrameRate(60);
	}
	printf("\n");
	return 0;
}