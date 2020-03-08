#pragma once

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"

#include"GLUTCallbacks.h"
#include"Sructures.h"
#include"MeshLoader.h"
#include"SceneObject.h"
#include"OBJMeshLoader.h"


#define REFRESHRATE 16



class HelloGl
{
public:
	HelloGl(int arg, char* argv[]);
	~HelloGl();

	void initObjects();
	void initCamera();
	void initGL(int arg, char* argv[]);
	void initLight();
	void display();
	void update();
	void Keyboard(unsigned char key, int x, int y);
	int RandomNumber(int maxNumber);


	

private:
	float sceenRotation;
	
	
	Camera* camera;
	SceneObject* objects[1000];
	std::vector< OBJMesh > model;
	
	
	Vector4* lightPosition;
	Lighting* lightData;
	
	
	

	
};

