#include "QL.h"

// This is the QuackLang Math module.

float degreesToRadians(float deg) // Should go in QLmath
{
	return deg * M_PI / 180;
}

float radiansToDegrees(float rad) // Should go in QLmath
{
	return rad * 180 / M_PI;
}

float giveAngle(int x0, int y0, int x1, int y1) // Where z0 is the center and z1 are the coordinates you want the angle for.
{
	int xA = x1 - x0;
	int yA = y1 - y0;
	return atan2(yA, xA); // Returns it in Rad
}

int randomNum(int min, int max) // Should go in QLmath
{	
	return min + (rand() % ((max + 1) - min)); // inclusive :D
}

float randomNumF(float min, float max) // Should go in QLmath
{
	return ( rand() / (float)RAND_MAX * max ) + min; // Thanks to evilBetty from #ludumdare (This is inclusive)
}

int sign(int num)
{
	int res = (num < 0) ? -1 : ((num > 0) ? 1 : 0); // I bally love C
	return res;
}

float signf(float num)
{
	int res = (num < 0.0) ? -1 : ((num > 0.0) ? 1 : 0); // I bally love C
	return res;
}

bool noiseGen(double *noise, double width, double height) // QLmath
{
	int x, y;
	for (x = 0; x < width; x++)
	{
		for (y = 0; y < height; y++)
		{
			noise[x][y] = (rand() % 32768) / 32768.0;
		}
	}
	return true;
}

// double smoothNoise(double *noise, double x, double y, double width, double height) // QLrand
// {  
// 	double fractX = x - int(x);
// 	double fractY = y - int(y);
   
// 	int x1 = x + width) % width;
// 	int y1 = y + height) % height;
	
// 	int x2 = (x1 + width - 1) % width;
// 	int y2 = (y1 + height - 1) % height;

// 	//smooth the noise!!! :D
// 	double value = 0.0;
// 	value += fractX * fractY * noise[x1][y1];
// 	value += fractX * (1 - fractY) * noise[x1][y2];
// 	value += (1 - fractX) * fractY * noise[x2][y1];
// 	value += (1 - fractX) * (1 - fractY) * noise[x2][y2];

//    return value;
// }

// double turbulentNoise(double x, double y, double scale) // QLrand
// {
//     double value = 0.0, initialScale = scale;
    
//     while(scale >= 1)
//     {
//         value += smoothNoise(x / scale, y / scale) * scale;
//         scale /= 2.0;
//     }
    
//     return(128.0 * value / initialScale);
// }

// bool noiseDraw(char *type, double noise[][], double width, double height, double scale) // QLrand
// {
// 	int r, g, b;
// 	int x, y;
// 	if(strcmp(type, "normal") || strcmp(type, "Normal"))
// 	{
// 		if (scale == 0)
// 		{ 
// 			for(x = 0; x < width; x++)
// 			{
//     			for(y = 0; y < height; y++)
//     			{
//     				r = g = b = int(256 * noise[x][y]);
//     				setColour(r, g, b, 255);
//         			pixel(x, y);
//     			}
// 			}
//     	}
//     	else 
//     	{
//     		for(x = 0; x < width; x++)
// 			{
//     			for(y = 0; y < height; y++)
//     			{
//     				r = g = b = int(256 * noise[x / scale][y / scale]);
//     				setColour(r, g, b, 255);
//         			pixel(x, y);
//     			}
// 			}
//     	}     
        
//     }
//     else if (strcmp(type, "smooth") || strcmp(type, "Smooth"))
//     {
//     	if (scale == 0)
// 		{ 
// 			for(x = 0; x < width; x++)
// 			{
//     			for(y = 0; y < height; y++)
//     			{
//     				r = g = b = int(256 * smoothNoise(noise[][], x, y, width, height));
//     				setColour(r, g, b, 255);
//         			pixel(x, y);
//     			}
// 			}
//     	}
//     	else 
//     	{
//     		for(x = 0; x < width; x++)
// 			{
//     			for(y = 0; y < height; y++)
//     			{
//     				r = g = b = int(256 * smoothNoise(noise[][], x / scale, y / scale, width, height));
//     				setColour(r, g, b, 255);
//         			pixel(x, y);
//     			}
// 			}
//     	}  
//     }
//     else if (strcmp(type, "turbulence") || strcmp(type, "Turbulence"))
//     {
//     	if (scale == 0)
//     	{
//     		printf("QuackLang - ERROR:");
//     		printf("Invalid argument given! For turbulent noise, scale must be > 0");
//     		return false;
//     	}
//     	else
//     	{
//     		r = g = b = int(256 * turbulentNoise(x, y, scale));
//     		setColour(r, g, b, 255);
//         	pixel(x, y);
//     	}
//     }
//     return true;
// }