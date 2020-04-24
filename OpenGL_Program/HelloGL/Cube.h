#ifndef _CUBE_H
#define _CUBE_H

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"

#include"Sructures.h"
#include"SceneObject.h"


class Cube:public SceneObject
{
private:
	
	GLfloat mRotation;
	Vector3 mPosition;
	Material* mMaterial;

public:

	Cube(Mesh* mesh, Texture2D* texture,float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	
};

#endif