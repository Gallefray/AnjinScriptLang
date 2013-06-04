#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif
#include "ASL.h"
#include <stdio.h>

int main()
{
	printf("0");
	initWindow(800, 600, false, "test :3");
	printf("1");
	int i = 0;
	while (i < 900)
	{
		printf("2");
		clear();
		printf("3");
		setColour(255, 0, 0, 0);
		printf("4");
		rect("line", 10, 10, 10, 10);
		printf("5");
		update(25);
		printf("6");
	    //Update screen
	    
	i++;
	}
}