#ifndef _BUGATTI_H
#define _BUGATTI_H

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"

#include "ObjSceneObject.h"
#include"Sructures.h"


class OBJCarBugatti :
	public ObjSceneObject
{
	
public:
	OBJCarBugatti(char* path,float x, float y, float z, GLfloat rotation);
	~OBJCarBugatti();

	void Draw();
	void Update();
	
};

#endif
