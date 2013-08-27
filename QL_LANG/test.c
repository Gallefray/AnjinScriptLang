#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int main(int argc, char *argv[])
{
	initWindow(400, 400, false, "test :3");
	// int x, y; int angle, rad;
	// angle = 30;
	// rad = 100;
	int num = sign(10);
	printf("%d", num);
	while (keyInput.ESC != true)
	{
		// img testImg = loadImage("testRes", BMP);
		// x = cos(degreesToRadians(angle))*rad + 200;
		// y = sin(degreesToRadians(angle))*rad + 200;
		clear();
		// setColour(0, 255, 0, 255);
		// line(200, 200, x, y);

		update();
		// if(keyInput.left)
		// {
		// 	angle--;
		// }
		// if(keyInput.right)
		// {
		// 	angle++;
		// }
		capFrameRate(60);
	}
	printf("\n");
	return 0;
}