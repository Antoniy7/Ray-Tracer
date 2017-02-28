#ifndef _CAMERA_H
#define _CAMERA_H

#include<cmath>
#include"Vect.h"
//#include ""

class Camera{
	Vect campos; // camera position
	Vect camdir; // camera direction
	
	//define general coordinate system for the scene 
	//to compute perspectives
	Vect camright; //camera right
	Vect camdown; //camera down 

public:
	Camera();
	Camera(Vect, Vect,Vect,Vect);
	Vect getCameraPosition() { return campos; }
	Vect getCameraDirection() { return camdir; }
	Vect getCameraRight() { return camright; }
	Vect getCameraDown() { return camdown; }
};

Camera::Camera()
{
	campos = Vect(0, 0, 0);
	camdir = Vect(0, 0, 1);
	camright = Vect(0, 0, 0);
	camdown = Vect(0, 0, 0);

}

Camera::Camera(Vect pos, Vect dir, Vect right, Vect down)
{
	campos = pos;
	camdir = dir;
	camright = right;
	camdown = down;
}

#endif
