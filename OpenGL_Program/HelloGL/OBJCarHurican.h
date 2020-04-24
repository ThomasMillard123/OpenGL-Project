#ifndef _HURICAN_H
#define _HURICAN_H

#include "ObjSceneObject.h"
#include"BMPLoader.h"
class OBJCarHurican :
	public ObjSceneObject
{
private:

	GLuint mID, mID2;


public:


	OBJCarHurican(char* path, float x, float y, float z, GLfloat rotation);
	~OBJCarHurican();

	void Draw();
	void Update();
};

#endif