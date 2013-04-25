#include "ASL.h"

int main()
{
	initWindow(800, 600, false, "test :3");
	int x = 0;
	while (x == 0)
	{
		clear();
		setColour(255, 255, 255, 1);
		rect("fill", 20, 20, 50, 50);
		update();
	}
}