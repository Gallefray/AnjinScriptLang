#include "QL.h"

int lineWidth;

void setColour(int r, int g, int b, int a)
{
	glColor4f(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

void setLineWidth(int width)
{
	lineWidth = width;
}

void pixel(GLint x, GLint y) // Blatantly copied from antonijn
{
	glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void line(int ox, int oy, int tx, int ty) // origin x, y; target x, y;
{
	glBegin(GL_LINES);
	glVertex2i(ox, oy);
	glVertex2i(tx, ty);
	glEnd();
}


bool rect(char *type, int x, int y, int w, int h)
{
	if (strcmp(type, "fill") == 0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glVertex2i(x, y);
		glVertex2i(x, y+h);
		glVertex2i(x+w, y+h);
		glVertex2i(x, y);
		glVertex2i(x+w, y);
		glVertex2i(x+w, y+h);
		glEnd();
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
			px = (cosf(angle)*(w/2) + x);
			py = (sinf(angle)*(h/2) + y);
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