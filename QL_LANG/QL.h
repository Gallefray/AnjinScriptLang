#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <SDL/SDL.h>
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
	bool tab, insert, home, del, end, pgUp, pgDown, backspace; // Handled
	bool up, down, left, right; // Handled
	bool NUMone, NUMtwo, NUMthree, NUMfour, NUMfive, NUMsix, NUMseven, NUMeight, NUMnine, NUMzero; // Handled
} keyObj;

SDL_Surface *screen;
SDL_Event event;
keyObj keyInput;
int colour;
int scrColour;
int scrWidth, scrHeight;
int scrTransX,  scrTransY;


// Function definitions:
bool initWindow(int height, int width, bool fullscreen, char *name);
void pixel(int x, int y); // Blatantly copied from the SDL example
int randomNum(int min, int max);
bool rectRectCollision(int Ax, int Ay, int Ah, int Aw, int Bx, int By, int Bh, int Bw);
int setColour(int r, int g, int b, int a);
int setScrColour(int r, int g, int b, int a);
void setLineWidth(int width);
void line(int xi, int yi, int xii, int yii);
int rect(char *type, int x, int y, int w, int h);
int circle(char *type, int x, int y, float radius);
void clear();
void grabInput();
float update(int desFPS);
