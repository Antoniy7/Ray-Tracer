#ifndef _RAY_H
#define _RAY_H

#include<cmath>
#include"Vect.h"

class Ray{
	Vect origin;
	Vect directon;
	
public:
	Ray();
	Ray(Vect, Vect);
	Vect getRayOrigin() { return origin; }
	Vect getRayDirection() { return directon; }
};

Ray::Ray()
{
	origin = Vect(0, 0, 0);
	directon = Vect(1, 0, 0);
}

Ray::Ray(Vect orig, Vect dir)
{
	origin = orig;
	directon = dir;
}

#endif
