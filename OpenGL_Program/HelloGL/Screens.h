#ifndef _SCREEN_H
#define _SCREEN_H

#include <Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"

#include"GLUTCallbacks.h"
#include"Sructures.h"
#include"MeshLoader.h"
#include"SceneObject.h"
#include"ObjSceneObject.h"
#include"OBJMeshLoader.h"
#include"Texture2D.h"
class Screens
{
public:
	Screens();
	~Screens();

	virtual void Update();
	virtual void Draw();

	virtual void InitCamera();
	virtual void InitObjects();
	virtual void InitLight();

	virtual void Keyboard(unsigned char key, int x, int y);
	int GetNextLevel();

	void DrawString(const char* text, Vector3* position, Color* color);
	int RandomNumber(int maxNumber);

protected:
	float mSceenRotation;
	Vector3 mCameraPosition;

	int mNextLevel;
	Camera* mCamera;
	Vector4* mLightPosition;
	Lighting* mLightData;
	
	const char* mTitleText;
	

};

#endif