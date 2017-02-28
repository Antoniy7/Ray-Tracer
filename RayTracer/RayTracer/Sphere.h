#ifndef _Sphere_H
#define _Sphere_H

#include"Vect.h"
#include"Object.h"
#include"Color.h"
#include<cmath>

class Sphere : public Object {
	Vect center;
	double radius;
	Color color;

public:
	Sphere();
	Sphere(Vect,double, Color);
	Vect getSphereCenter() { return center	; }
	virtual Color getColor() { return color; }
	double getSphereRadius(){ return radius; }

	//normal always points away from center of spheres
	virtual Vect getNormalAt(Vect point){
		Vect normal_Vect = point.vectAdd(center.negative()).normalize();
		return normal_Vect;
	}

    //origin of the ray to the intersection
	virtual double findIntersection(Ray ray){
		Vect ray_origin = ray.getRayOrigin();
		double ray_origin_x = ray_origin.getVectX();
		double ray_origin_y = ray_origin.getVectY();
		double ray_origin_z = ray_origin.getVectZ();

		Vect ray_direction = ray.getRayDirection();
		double ray_direction_x = ray_direction.getVectX();
		double ray_direction_y = ray_direction.getVectY();
		double ray_direction_z = ray_direction.getVectZ();

		Vect sphere_center = center;
		double sphere_center_x = sphere_center.getVectX();
		double sphere_center_y = sphere_center.getVectY();
		double sphere_center_z = sphere_center.getVectZ();

		double a = 1; //normalized;
		double b = (2 * (ray_origin_x - sphere_center_x) * ray_direction_x) + (2 * (ray_origin_y - sphere_center_y) * ray_direction_y) + (2 * (ray_origin_z - sphere_center_z) * ray_direction_z);

		double c = pow(ray_origin_x - sphere_center_x, 2) + pow(ray_origin_y - sphere_center_y, 2) + pow(ray_origin_z - sphere_center_z, 2) - (radius*radius);

		double discriminant = (b*b) - (4 * c);

		if (discriminant > 0){
			//ray intersects the sphere  // on two sides

			//first root // first intersection
			double root_1 = ((-1 * b - sqrt(discriminant)) / 2) - 0.00001;
			
			//smallest positive 
			if (root_1 > 0){
				return root_1;
			}
			// or this is the smallest positive
			else {
				double root_2 = ((sqrt(discriminant) - b) / 2) - 0.00001;
				return root_2;
			}
		}
		// d!>0
		else{
			//the ray missed the sphere
			return -1;
		}
	}
};

Sphere::Sphere()
{
	center = Vect(0, 0, 0);
	radius = 1;
	color = Color(0.5, 0.5, 0.5, 0);
}

Sphere::Sphere(Vect cent,double rad, Color col)
{
	center = cent;
	radius = rad;
	color = col;
}

#endif
