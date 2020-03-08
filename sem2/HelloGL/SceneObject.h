#pragma once
#include"GL\freeglut.h"
#include"Sructures.h"

class Texture2D;

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;
public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void update();
	virtual void draw();
};

