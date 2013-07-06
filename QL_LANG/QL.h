#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <time.h>

#define true 1
#define false 0
#define bool int

typedef struct 
{
	bool F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12; // Handled
	bool ESC, lSHIFT, rSHIFT, lCTRL, rCTRL, lWIN, rWIN, lALT, rALT, CAPS, NUM; // Handled
	bool one, two, three, four, five, six, seven, eight, nine, zero; // Handled
	bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z; // Handled
	bool tab, insert, home, delete, end, pgUp, pgDown, backspace; // Handled
	bool up, down, left, right; // Handled
	bool NUMone, NUMtwo, NUMthree, NUMfour, NUMfive, NUMsix, NUMseven, NUMeight, NUMnine, NUMzero; // Handled
} keyObj;

keyObj keyInput;
SDL_Event event;
SDL_Surface *screen;
int colour;
int scrColour;
//uint16_t red, green, blue, alpha;

// Function definitions:
bool initWindow(int height, int width, bool fullscreen, char *name);
void pixel(int x, int y); // Blatantly copied from the SDL example
int randomNum(int min, int max);
bool rectRectCollision(int Ax, int Ay, int Ah, int Aw, int Bx, int By, int Bh, int Bw);
int setColour(int r, int g, int b, int a);
int setScrColour(int r, int g, int b, int a);
void line(int xi, int yi, int xii, int yii);
int rect(char *type, int16_t x, int16_t y, int16_t w, int16_t h);
void clear();
void grabKeyInput();
int update(int FPS);
