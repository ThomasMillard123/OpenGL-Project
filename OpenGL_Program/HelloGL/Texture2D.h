#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return mID; }
	int Getwidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }

private:

	GLuint mID;
	int mWidth, mHeight;
};

#endif