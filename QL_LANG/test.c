#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

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
		update(25);	
		if (keyInput.left == true)
		{
			scrTransX--;
		}
		if (keyInput.right == true)
		{
			scrTransX++;	
		}
		if (keyInput.up == true)
		{
			scrTransY--;
		}
		if (keyInput.down == true)
		{
			scrTransY++;
		}
		if (keyInput.zero == true)
		{
			scrTransX = 0;
			scrTransY = 0;
		}
	}
	return 0;
}