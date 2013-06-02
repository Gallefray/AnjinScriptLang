#define true 1
#define false 0
#define bool int

// int red, green, blue, alpha;

// Function definitions:
int randomNum(int min, int max);
bool initWindow(int height, int width, bool fullscreen, char *name);
bool rectRectCollision(float Ax, float Ay, float Ah, float Aw, float Bx, float By, float Bh, float Bw);
int setColour(int r, int g, int b, int a);
// bool keyInput(char key);
int rect(char *type, float x, float y, float w, float h);
int setLineWidth(float width);
// int clear();
int update();//int FPS);
int grabKeyInput();