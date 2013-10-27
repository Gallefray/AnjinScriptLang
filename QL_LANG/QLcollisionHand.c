#include "QL.h"

bool rectRectCollision(int Ax, int Ay, int Ah, int Aw, int Bx, int By, int Bh, int Bw)
{ 
	return (Ax + Aw >= Bx && Ax <= Bx+Bw && Ay + Ah >= By && Ay <= By+Bh);
}

bool circleCircleCollision(int Ax, int Ay, int Ar, int Bx, int By, int Br)
{
	int xDelta = (Ax - Bx);
	int yDelta = (Ay - By);
	int rSquare = (Ar + Br); // thanks to Infernal (from #ludumdare) for spotting the stupid little bug :S
	return (xDelta*xDelta + yDelta*yDelta <= rSquare * rSquare);
}

bool pointCircleCollision(int pX, int pY, int cX, int cY, int cR)
{
	int xDelta = (pX - cX);
	int yDelta = (pY - cY);
	return (xDelta*xDelta + yDelta*yDelta <= cR*cR);
}