#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H

#include"GL\freeglut.h"
#include"Sructures.h"

class Texture2D;

class SceneObject
{
protected:
	Mesh* mMesh;
	Texture2D* mTexture;

public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
};

#endif