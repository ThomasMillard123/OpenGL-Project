#ifndef _HELLOGL_H
#define _HELLOGL_H

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"

#include"GLUTCallbacks.h"
#include"Sructures.h"
#include"MeshLoader.h"
#include"SceneObject.h"

#include"Screens.h"

#define REFRESHRATE 16



class HelloGl
{
public:
	HelloGl(int arg, char* argv[]);
	~HelloGl();

	void InitObjects();
	void InitGL(int arg, char* argv[]);
	void Display();
	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void SwitchScreens();
	

private:
	Screens* Level;
};

#endif