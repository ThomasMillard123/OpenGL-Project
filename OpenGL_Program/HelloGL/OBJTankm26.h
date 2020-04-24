#ifndef _TANKTIGER1_H
#define _TANKTIGER1_H

#include "ObjSceneObject.h"
class OBJTankm26 :
	public ObjSceneObject
{
private:

	GLuint mID, mID2;
	

	

public:


	OBJTankm26(char* path, float x, float y, float z, GLfloat rotation);
	~OBJTankm26();

	void Draw();
	void Update();
};

#endif