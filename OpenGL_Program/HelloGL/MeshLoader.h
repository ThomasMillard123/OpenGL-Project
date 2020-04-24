#ifndef _MESHLOADER_H
#define _MESHLOADER_H

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include "Sructures.h"

namespace MeshLoader
{
	Mesh* Load(char* path);
};

#endif