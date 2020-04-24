#ifndef _TANKIS7_H
#define _TANKIS7_H

#include "ObjSceneObject.h"

class OBJTankIS7 :
	public ObjSceneObject
{

private:


	GLuint mID, mID2;
	

public:


	OBJTankIS7(char* path, float x, float y, float z, GLfloat rotation);
	~OBJTankIS7();

	void Draw();
	void Update();
};

#endif