#pragma once

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"

#include"Sructures.h"
#include"SceneObject.h"


class Cube:public SceneObject
{
private:
	

	GLfloat rotation;
	Vector3 position;
	Material* material;

public:


	Cube(Mesh* mesh, Texture2D* texture,float x, float y, float z);
	~Cube();

	void draw();
	void update();
	



};

