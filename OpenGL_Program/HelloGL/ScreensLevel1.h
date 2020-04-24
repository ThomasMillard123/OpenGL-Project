#ifndef _SCREENCUBES_H
#define _SCREENCUBES_H

#include "Screens.h"
class ScreensLevel1 :
	public Screens
{
public:
	ScreensLevel1();
	~ScreensLevel1();

	void InitObjects();
	void InitCamera();
	void InitLight();
	void Keyboard(unsigned char key, int x, int y);
	void Update();
	void Draw();

private:
	
	SceneObject* mObjects[1000];
	Texture2D* mTexture;
};

#endif