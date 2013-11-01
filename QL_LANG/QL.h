#ifndef QL_H  // Thanks to http://www.github.com/antonijn for the
#define QL_H  // include guard :3

// #define GLFW_INCLUDE_ES1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <GLFW/glfw3.h>
#ifndef _WIN32
#include <pthread.h>
#else
#include <windows.h>
#endif

#define true 1
#define false 0
typedef char bool;

#define sq(x) (x * x)
#define Pi M_PI
#define Tau Pi*2

typedef struct 
{
	bool F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12;
	bool ESC, lSHIFT, rSHIFT, lCTRL, rCTRL, lWIN, rWIN, lALT, rALT, CAPS, NUM;
	bool one, two, three, four, five, six, seven, eight, nine, zero;
	bool a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
	bool tab, insert, home, del, end, pgUp, pgDown, backspace, spacebar;
	bool up, down, left, right;
	bool NUMone, NUMtwo, NUMthree, NUMfour, NUMfive, NUMsix, NUMseven, NUMeight, NUMnine, NUMzero;
} keyObj;

typedef struct
{
	int x, y;
	//bool button1, button2, button3, button4, button5, button6, button7, button8; // A nice round number! :D
	bool leftButton, rightButton, middleButton; // same as 1, 2, 3
} mouseObj;

enum { BMP, PNG }; // imgType

// *POP* GOES IMAGE SUPPORT ;_;
// typedef struct
// {
// 	SDL_Surface *img;
// 	SDL_Rect *pos;
// 	int type;
// 	int width, height;
// } img;

typedef struct
{
	int x, y;
	int angle;
} vect;

// GLFW variables that are needed
extern GLFWmonitor  *monitor;
extern GLFWwindow *window;

// Input
extern keyObj keyInput;
extern mouseObj mouseInput;

// Screen 
extern int scrWidth, scrHeight;
extern int scrTransX, scrTransY;
extern float scrScaleX, scrScaleY;

// Framerate
extern int FPS, drawTime, timeDelta;
extern double timeOne, timeTwo;

// Shape displaying stuff
extern int lineWidth;

// Function definitions:
// QLmath:
float degreesToRadians(float deg); // Returns a float containing the radians.
float radiansToDegrees(float rad); // Returns a float containing the degrees.
int randomNum(int min, int max); // Returns a random number, is inclusive.
float randomNumF(float min, float max); // Returns a random number of floating point. (is inclusive?)
float giveAngle(int x0, int y0, int x1, int y1); // Where z0 is the center and z1 are the coordinates you want the angle for.
int sign(int num); // Returns -1 if the number is less than 0, 1 if the number is bigger than 0 and 0 if the number is equal to 0;
float signf(float num); // as above but for floating point numbers

// bool noiseGen(double *noise, double width, double height); // Returns an array full of noise.
// double smoothNoise(double noise[][], double x, double y, double width, double height); // Smooths the noise. Don't use this, it's only for the noiseDraw() function.
// double turbulentNoise(double x, double y, double scale); // Applies turbulence to the noise. Don't use this, it's only for the noiseDraw() function.
// bool noiseDraw(char *type, double noise[][], double width, double height, double scale) // Draws noise created with noiseGen(). Supported args are "normal", "smooth" and "turbulence" (Don't use turbulence with a scale value of 0)


// QLcollisionHand:
bool rectRectCollision(int Ax, int Ay, int Ah, int Aw, int Bx, int By, int Bh, int Bw); // Returns true if a collision is detected
bool circleCircleCollision(int Ax, int Ay, int Ar, int Bx, int By, int Br);
bool pointCircleCollision(int pX, int pY, int cX, int cY, int cR);

// QLinput:
void grabKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);


// QL:
void quitQL(); // Cleans up and quits
bool initWindow(int height, int width, bool fullscreen, char *name); // Creates a window, this must be done before any graphics - related operations. Returns true if successful 
void clear(void);
void setScrColour(int r, int g, int b, int a); // Sets the background of the window to the r, g, b, a specified;
void setTitle(char *name); // Sets the title of the window to name
void scale(double x, double y);
void update(void);
void capFrameRate(int desFPS); // Caps the frame rate, then updates FPS.


// QLshapes:
void setColour(int r, int g, int b, int a);   // Sets the current colour to the r, g, b, a specified.
void setLineWidth(int width); // Does nothing as there's no un-broken line drawing func yet :/
void pixel(GLint x, GLint y); // Blatantly copied from antonijn
void line(int x0, int y0, int x1, int y1); // Draws a line.
bool rect(char *type, int x, int y, int w, int h); // Draws a rect. Returns false if an error has been encountered.
bool circle(char *type, int x, int y, float radius); // Draws a circle with the middle at the x, y. Returns false if an error has been encountered.
bool ellipse(char *type, int x, int y, int w, int h); // Draws an ellipse with the middle at the x, y. Returns false if an error has been encountered.
void drawPartCircle(int x, int y, int r, float a, int c); // Draws the part of the circumferance starting at a and ending hen a == c; Does not work as such


// QLimage:
// img loadImage(char *location, int type); // Where location is something like "res/img.bmp" and type is either BMP or PNG.
// void drawImage(img image, int x, int y); // draws the image returned from loadImage at position x, y
#endif