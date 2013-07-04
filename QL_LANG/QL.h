#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <time.h>

#define true 1
#define false 0
#define bool int

SDL_Surface *screen;

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
