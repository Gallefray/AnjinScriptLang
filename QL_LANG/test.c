#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int main() 
{
	initWindow(400, 400, false, "test :3");
	while (keyInput.ESC != true)
	{
		setScrColour(0, 0, 255, 0);
		setColour(255, 0, 0, 255);
		clear();
		rect("fill", 32, 32, 32, 32);
		update(1);
		// printf("DT: %f\n", (deltaTime));
		// printf("FPS: %d\n", FPS);
		if (keyInput.left == true)
		{
			scrTransX -= 60 * deltaTime; 
		}
		if (keyInput.right == true)
		{
			scrTransX += 60 * deltaTime; 
		}
	}
	printf("\n");
	return 0;
}