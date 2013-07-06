#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int main()
{
	initWindow(480, 320, false, "test :3");
	setColour(255, 0, 0, 255);
	while (keyInput.ESC != true)
	{
		if (keyInput.lWIN == true && keyInput.a == true)
		{
			rect("fill", 20, 20, 20, 20);
		}
		update(25);
	}
	return 0;
}