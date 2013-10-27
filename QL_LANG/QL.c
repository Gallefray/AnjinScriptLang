#include "QL.h" // QL.c's header file

GLFWmonitor *monitor;
GLFWwindow *window;

// Screen 
int scrWidth, scrHeight;
int scrTransX, scrTransY;
int scrScaleX, scrScaleY;

// Framerate
int FPS, drawTime, timeDelta;
double timeOne, timeTwo;

void error_callback(int error, const char* description)
{
	printf(description);
}

// void quit_callback(GLFWwindow *window)
// {
// 	glfwSetWindowCloseCallback();
// }

void quitQL()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool initWindow(int width, int height, bool fullscreen, char *name)
{
	srand(time(NULL));
	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) // Init the glfw libs, if there's an error then catch and report it. Yeah, I'm initing all of them, eh.
	{ 
		printf("QuackLang - ERROR");
	    exit(EXIT_FAILURE);
	}

	// atexit();// Clean up everything when the program exits! :D

	monitor = glfwGetPrimaryMonitor();

	if (fullscreen == true)
	{
		window = glfwCreateWindow(width, height, name, monitor, NULL);
		if (window == NULL) 
		{
			printf("QuackLang - ERROR");
		    exit(EXIT_FAILURE);
		}
	}
	else
	{
		window = glfwCreateWindow(width, height, name, NULL, NULL);
		if (window == NULL) 
		{
			printf("QuackLang - ERROR:");
		    exit(EXIT_FAILURE);
		}
	}

	glfwMakeContextCurrent(window);
	
	glfwGetFramebufferSize(window, &scrWidth, &scrHeight);
	glViewport(scrTransX, scrTransY, scrWidth, scrHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, scrWidth, scrHeight, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glfwSetWindowCloseCallback(window, quitQL);
	glfwSetKeyCallback(window, grabKeyInput);
	return true;
}

void clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void setScrColour(int r, int g, int b, int a)
{
	glClearColor(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

void setTitle(char *name)
{
	glfwSetWindowTitle(window, name);
}

void update() // Desired FPS
{
	timeOne = glfwGetTime();
	glViewport(scrTransX, scrTransY, scrWidth, scrHeight);
	glfwSwapBuffers(window); // Draw the shapes/images/whatever
	glfwPollEvents(); 	     // Poll our key event for any keystrokes.
}

void capFrameRate(int desFPS)
{
	drawTime = 1000/desFPS;
	timeTwo = glfwGetTime();

	timeDelta = (timeTwo - timeOne);
	if (timeDelta < drawTime)
	{
	#ifdef _WIN32
		Sleep(drawTime - timeDelta);
	#else
		usleep(drawTime - timeDelta);
	#endif
	}
}