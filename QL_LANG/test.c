#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "QL.h"

int main(int argc, char *argv[])
{
	initWindow(400, 400, false, "test :3");
	while (keyInput.ESC != true)
	{
		setColour(255, 255, 0, 255);
		clear();

		rect("line", 30, 30, 40, 40);

		update(30);
		capFrameRate(30);
	}
	printf("\n");
	return 0;
}