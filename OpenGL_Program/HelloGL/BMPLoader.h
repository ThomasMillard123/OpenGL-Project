#ifndef _BMPLOADER_H
#define _BMPLOADER_H

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"


class BMPLoader
{
public:
	BMPLoader();
	~BMPLoader();
	int LoadBMP(const char* location, GLuint& texture);
};

#endif