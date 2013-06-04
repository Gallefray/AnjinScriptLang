#define true 1
#define false 0
#define bool int

int red, green, blue, alpha;

// Function definitions:
int randomNum(int min, int max);
bool initWindow(int height, int width, bool fullscreen, char *name);
bool rectRectCollision(int Ax, int Ay, int Ah, int Aw, int Bx, int By, int Bh, int Bw);
int setColour(unsigned int r, unsigned int g, unsigned int b, unsigned int a);
// bool keyInput(char key);
int rect(char *type, signed int x, signed int y, signed int w, signed int h);
// int setLineWidth(int width);
int clear();
int update(int FPS);
int grabKeyInput();