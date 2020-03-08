#pragma once

#include"GL\freeglut.h"
#include"Sructures.h"
#include"SceneObject.h"
class Pyramid:public SceneObject
{
private:
	Vector3 position;
public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();

	void draw();
	void update();
};

