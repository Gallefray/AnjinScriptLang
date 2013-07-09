#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int dt;

int main() // error somewhere? :P
{
	initWindow(1024, 768, false, "test :3");
	int rX1 = 32;
	int rY1 = 32;
	int rX2 = 64;
	int rY2 = 64;
	while (keyInput.ESC != true)
	{
		setScrColour(0, 0, 255, 0);
		clear();
		rect("fill", rX1, rY1, 32, 32);
		setColour(255, 0, 0, 255);
		rect("fill", rX2, rY2, 32, 32);
		dt = update(50);	
		printf("|  Delta: %f  ", dt);
		if (keyInput.left == true)
		{
			scrTransX -= 1 * dt;
		}
		if (keyInput.right == true)
		{
			scrTransX += 1 * dt;	
		}
		if (keyInput.up == true)
		{
			scrTransY -= 1 * dt;
		}
		if (keyInput.down == true)
		{
			scrTransY += 1 * dt;	
		}
		if (keyInput.zero == true)
		{
			scrTransX = 0;
			scrTransY = 0;
		}
	}
	printf("\n");
	return 0;
}