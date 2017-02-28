#ifndef _Plane_H
#define _Plane_H

#include"Vect.h"
#include"Object.h"
#include"Color.h"
#include<cmath>

class Plane : public Object {
	Vect normal; // orients the plane

	//distance from the center of our plane to the 
	//center of our scene
	double distance;

	Color color;

public:
	Plane();
	Plane(Vect, double, Color);
	Vect getPlaneNormal() { return normal; }
	virtual Color getColor() { return color; }
	double getPlaneDistance(){ return distance; }

	virtual Vect getNormalAt(Vect point){
		return normal;
	}

	virtual double findIntersection(Ray ray){
		Vect ray_direction = ray.getRayDirection();

		double a = ray_direction.dotProduct(normal);
		if (a == 0){
			//ray is parallel to the plane
			return -1;
		}
		else{
			double b = normal.dotProduct(ray.getRayOrigin().vectAdd(normal.vectMult(distance).negative()));
			return -1 * b / a;
		}
	}


};

Plane::Plane()
{
	normal = Vect(1, 0, 0);
	distance = 0; //at the origin
	color = Color(0.5, 0.5, 0.5, 0);
}

Plane::Plane(Vect normalValue, double distanceVaue, Color colValue)
{
	normal = normalValue;
	distance = distanceVaue;
	color = colValue;
}

#endif
