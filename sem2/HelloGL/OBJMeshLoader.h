#pragma once

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"



#include "Sructures.h"

namespace OBJMeshLoader
{
	std::vector<OBJMesh>LoadOBJ(char* path);
};

