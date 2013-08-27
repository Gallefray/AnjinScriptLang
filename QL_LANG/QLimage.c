#include "QL.h"

img loadImage(char *location, int type)
{
	img tempImg;
	if (type == BMP)
	{
		tempImg.img = SDL_LoadBMP(location);
		tempImg.type = BMP;
		tempImg.width = tempImg.img->w;
		tempImg.height = tempImg.img->h;

		// Make sure it clips to the edges of the screen:
		tempImg.pos->x = 0;
		tempImg.pos->y = 0;
		tempImg.pos->w = scrWidth;
		tempImg.pos->h = scrHeight;
		SDL_SetClipRect(screen, tempImg.pos);
	}
	else if (type == PNG)
	{

	}
	return tempImg;
}

void copySurface(SDL_Surface *source, SDL_Surface *dest, int x, int y)
{
	int px, py; // for the loop
	int retColour = colour; // This is so we can set the colour to before the copying :D
	Uint8 r, g, b;

	SDL_LockSurface(source);
	char *pixels = source->pixels;
		
	for (px = 0; px <= source->w; px++)
	{
		for (py = 0; py <= source->h; py++)
		{
			// `*((Uint32*)(pixels + (px*source->w + py)*3))` or `pixels[(px*source->w + py)*3]`
			// Thanks to antonijn :3
			SDL_GetRGB(pixels[(px*source->w + py)*3], source->format, &r, &g, &b);
			setColour(r, g, b, 255);
			pixel(px+x, py+y);
		}
	}
	SDL_UnlockSurface(source);
	colour = retColour; // set colour back to the previous value :P
}

void drawImage(img image, int x, int y)
{
	if (image.type == BMP)
	{
		if (x < 0 || y < 0) 
		{
			copySurface(image.img, screen, x, y);
		}
		else
		{
			image.pos->x = x;
			image.pos->y = y;
			SDL_UnlockSurface(screen);
			SDL_UnlockSurface(image.img);
			SDL_BlitSurface(screen, NULL, image.img, image.pos);
		}
	}
}