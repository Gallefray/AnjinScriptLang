#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int main(int argc, char *argv[])
{
	initWindow(400, 400, false, "test :3");
	int cX = 32; int cY = 32;
	int r, g, b;
	g = 0; b = 0; r = 255;
	while (keyInput.ESC != true)
	{
		setScrColour(0, 0, 255, 0);
		setColour(r, g, b, 255);
		clear();
		ellipse("line", cX, cY, 8, 32);
		update();
		if (keyInput.left == true)
		{
			cX -= 6;
			r = 255;
			g = 255;
			b = 0; 
		}
		if (keyInput.right == true)
		{
			cX += 6; 
			r = 0;
			g = 255;
			b = 0; 
		}
		capFrameRate(30);
	}
	printf("\n");
	return 0;
}