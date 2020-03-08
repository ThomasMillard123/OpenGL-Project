#pragma once
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

	GLuint GetID() const { return _ID; }
	int Getwidth() const { return _Width; }
	int GetHeight() const { return _Height; }

private:

	GLuint _ID;
	int _Width, _Height;
};

