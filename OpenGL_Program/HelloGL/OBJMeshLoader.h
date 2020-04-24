#ifndef _OBJMESHLOADER_H
#define _OBJMESHLOADER_H

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include<vector>


#include "Sructures.h"

namespace OBJMeshLoader
{
	std::vector<OBJMesh>LoadOBJ(char* path);
};

#endif