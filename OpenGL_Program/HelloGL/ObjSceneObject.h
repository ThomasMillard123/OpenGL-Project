#ifndef _OBJOBJECTS_H
#define _OBJOBJECTS_H

#include"GL\freeglut.h"
#include<vector>
#include"BMPLoader.h"
#include"Sructures.h"

class ObjSceneObject
{
protected:
	GLfloat mRotationSpeed;
	std::vector< OBJMesh > mModel;

	Vector3 mRotationPoint;

	Vector3 mPosition;
	Material* mMaterial;
	BMPLoader* mTexture;

public:
	ObjSceneObject(char* path, float x, float y, float z, GLfloat rotation);
	~ObjSceneObject();

	virtual void Update();
	virtual void Draw();
	void Rotate(GLfloat rotation,float x,float y,float z);


};

#endif