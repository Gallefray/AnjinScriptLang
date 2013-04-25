#include "ASL.h"

int main()
{
	initWindow(800, 600, false, "test :3");
	int i = 0;
	while (i < 900)
	{
		clear();
		setLineWidth(20);
		setColour(255, 0, 0, 1);
		rect("fill", 20, 20, 50, 50);
		update();
		i++;
	}
}