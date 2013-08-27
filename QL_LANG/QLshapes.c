#include "QL.h"

int lineWidth;

void setColour(int r, int g, int b, int a)
{
	colour = SDL_MapRGBA(screen->format, r, g, b, a);
}

void setLineWidth(int width)
{
	lineWidth = width;
}

void pixel(int x, int y) // Blatantly copied from the SDL example
{
	int nx = x+scrTransX;
	int ny = y+scrTransY;
	if (nx >= 0 && nx < scrWidth && ny >= 0 && ny < scrHeight)
	{
		SDL_LockSurface(screen);
		int bpp = screen->format->BytesPerPixel;
	    /* Here p is the address to the pixel we want to set */
	    Uint8 *p = (Uint8 *)screen->pixels + ny * screen->pitch + nx * bpp; // Uint8

	    switch(bpp) {
		    case 1:
		        *p = colour;
		        break;

		    case 2:
		        *(Uint16 *)p = colour; // Uint16
		        break;

		    case 3:
		        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
		            p[0] = (colour >> 16) & 0xff;
		            p[1] = (colour >> 8) & 0xff;
		            p[2] = colour & 0xff;
		        } else {
		            p[0] = colour & 0xff;
		            p[1] = (colour >> 8) & 0xff;
		            p[2] = (colour >> 16) & 0xff;
		        }
		        break;

		    case 4:
		        *(Uint32 *)p = colour; // Unit32
		        break;
	    }
	    SDL_UnlockSurface(screen);
	}
}


void line(int x0, int y0, int x1, int y1)
{
	// int xi, yi, a; // x increment, y increment, angle
	// int px, py; // pixel x, y
	// int xDelta = abs(x1 - x0); // height
	// int yDelta = abs(y1 - y0); // width
	// a = giveAngle(x0, y0, x1, y1);

	// if (xDelta > yDelta)
	// {
	// 	for (xi = x0; )
	// }
	int targX, targY, origX, origY;
	if (x0 < x1)
	{
		origX = x0;
		targX = x1;
	}
	else if(x1 < x0)
	{
		origX = x1;
		targX = x0;	
	}
	if (y0 < y1)
	{
		origY = y0;
		targY = y1;
	}
	else if (y1 < y0)
	{
		origY = y1;
		targY = y0;	
	}

	int rad = 0;
	int px = origX; int py = origY;
	int xDelta = abs(targX - origX);
	int yDelta = abs(targX - origX);
	
	float angle = giveAngle(origX, origY, targX, targY);
	// for (rad = 0;  (abs(px) <= abs(xDelta) && xDelta != 0) || (abs(py) <= abs(yDelta) && yDelta != 0); rad++)
	// {
	// 	px = cos(angle)*rad + x0;
	// 	py = sin(angle)*rad + y0;
	// 	pixel(px, py);
	// }

	while((px <= xDelta) || (py <= yDelta))
	{
		rad++;
		px = cos(angle)*rad + origX;
		py = sin(angle)*rad + origY;
		pixel(px, py);
	}

}

bool rect(char *type, int x, int y, int w, int h)
{
	if (strcmp(type, "fill") == 0)
	{
		int px, py;
		for (py = y; py < y+h; py++)
		{
			for (px = x; px < (x+w); px++) 
			{
				pixel(px, py);
			}
			px = x;
		}
	}
	else if (strcmp(type, "line") == 0)
	{
		line(x, y, x+w, y);     // The top line
		line(x, y, x, y+h);     // The left line
		line(x, y+h, x+w, y+h); // The bottom line
		line(x+w, y, x+w, y+h); // The right line
	}
	else
	{
		printf("QuackLang - ERROR:");
		printf("Incorrect first argument given to the rect function! D:\n");
		printf("You gave %s\n", type);
		printf("Only 'line' or 'fill' can be accepted.");
		return false;
	}
	return true;
}

bool circle(char *type, int x, int y, float radius)
{
	float maxDegrees = 360.0;
	float r, angle;
	int px, py;
	if (strcmp(type, "line") == 0)
	{
		for (angle = 0.0; angle <= maxDegrees; angle += 1.0)
		{
			px = (cosf(angle)*radius + x);
			py = (sinf(angle)*radius + y);
			pixel(px, py);
		}
	}
	else if (strcmp(type, "fill") == 0)
	{
		// This might be an inefficient way of doing it, but I'm aiming for readability at this stage ;)
		// Step back through the radius until it becomes 0 and the entire circle has been plot

		//Scratch that. This needs MASSIVE optimisation. :O 
		for (r = radius; r >= 0; r -= 1.0)
		{
			for (angle = 0.0; angle <= maxDegrees; angle += 1.0)
			{
				px = (cosf(angle)*r + x);
				py = (sinf(angle)*r + y);
				pixel(px, py);
			}
		}
	}
	else
	{
		printf("QuackLang - ERROR:");
		printf("Incorrect first argument given to the rect function! D:\n");
		printf("You gave %s\n", type);
		printf("Only 'line' or 'fill' can be accepted.");
		return false;
	}
	return true;
}

bool ellipse(char *type, int x, int y, int w, int h)
{
	float maxDegrees = 360.0;
	float angle;
	int px, py;
	if (strcmp(type, "line") == 0)
	{
		for (angle = 0.0; angle <= maxDegrees; angle += 1.0)
		{
			px = (cosf(angle)*w + x);
			py = (sinf(angle)*h + y);
			pixel(px, py);
		}
	}
	// else if (strcmp(type, "fill") == 0)
	// {
	// 	// This might be an inefficient way of doing it, but I'm aiming for readability at this stage ;)
	// 	// Step back through the radius until it becomes 0 and the entire circle has been plot

	// 	// Scratch that. This needs MASSIVE optimisation. :O 
	// 	for (r = radius; r >= 0; r -= 1.0)
	// 	{
	// 		for (angle = 0.0; angle <= maxDegrees; angle += 1.0)
	// 		{
	// 			px = (cosf(angle)*w + x);
	// 			py = (sinf(angle)*h + y);
	// 			pixel(px, py);
	// 		}
	// 	}
	// }
	else
	{
		printf("QuackLang - ERROR:");
		printf("Incorrect first argument given to the rect function! D:\n");
		printf("You gave %s\n", type);
		printf("Only 'line' can be accepted.");
		return false;
	}
	return true;
}

void drawPartCircle(int x, int y, int r, float a, int c)
{
	// float maxDegrees = 360.0;
	float angle;
	int px, py;
	for (angle = degreesToRadians(a); angle <= c; angle += 1.0)
	{
		px = (cosf(angle)*r + x);
		py = (sinf(angle)*r + y);
		pixel(px, py);
	}
}