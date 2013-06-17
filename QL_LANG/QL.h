#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <time.h>
#include <assert.h>

#define true 1
#define false 0
#define bool int

uint16_t red, green, blue, alpha;

// Function definitions:
int randomNum(int min, int max);
bool initWindow(int height, int width, bool fullscreen, char *name);
bool rectRectCollision(int Ax, int Ay, int Ah, int Aw, int Bx, int By, int Bh, int Bw);
int setColour(uint16_t r, uint16_t g, uint16_t b, uint16_t a);
// bool keyInput(char key);
int rect(char *type, int16_t x, int16_t y, int16_t w, int16_t h);
// int setLineWidth(int width);
// int clear();
int update(int FPS);
int grabKeyInput();