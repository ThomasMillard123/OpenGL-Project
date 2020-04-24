#include "ScreensMenu.h"
ScreensMenu::ScreensMenu() : Screens() {
	
	mNextLevel = 1;
	InitCamera();
	InitObjects();

}

//setup camera
void ScreensMenu::InitCamera()
{
	mCamera = new Camera();

	mCamera->eye.x = 0.0f;
	mCamera->eye.y = 0.0f;
	mCamera->eye.z = 10.0f;

	mCamera->center.x = 0.0f;
	mCamera->center.y = 0.0f;
	mCamera->center.z = 0.0f;

	mCamera->up.x = 0.0f;
	mCamera->up.y = 1.0f;
	mCamera->up.z = 0.0f;
}
//setup objects
void ScreensMenu::InitObjects() {
	mTitleText = "Pointless and Interesting Scenes";
	mGeneralControllsText = "Press c to get to the next Scene";
	mSceen1ControllsText = "Scene 1 Controls:\n"
		"W-Move camera forward on z axis\n"
		"S-Move camera backward on z axis\n"
		"A-Move camera left on x axis\n"
		"D-Move camera right on x axis\n"
		"Q-Rotate camera left\n"
		"E-Rotate camera right\n"
		"Z-Move camera up on y axis\n"
		"X-Move camera down on y axis\n";
	mSceen2ControllsText = "Scene 2 Controls:\n"
		"W-Move camera forward on z axis\n"
		"S-Move camera backward on z axis\n"
		"A-Move camera left on x axis\n"
		"D-Move camera right on x axis\n"
		"Q-Next car to left\n"
		"E-Next car to right\n"
		"Z-Move camera up on y axis\n"
		"X-Move camera down on y axis\n"
		"R-Rotate model left\n"
		"T-Rotate model right\n";
}

void ScreensMenu::Update() {
	Screens::Update();

}

void ScreensMenu::Draw() {
	
	Vector3 textPosition = { -13.0f,30.0f,-100.0f };
	Color textColor = { 1.0f,1.0f,1.0f };

	DrawString(mTitleText, &textPosition, &textColor);
	textPosition.y -= 5;
	DrawString(mGeneralControllsText, &textPosition, &textColor);
	textPosition.x = -30;
	textPosition.y -= 5;
	DrawString(mSceen1ControllsText,&textPosition, &textColor);

	textPosition.x = 10;
	textPosition.y = 20;
	DrawString(mSceen2ControllsText,&textPosition, &textColor);
}

ScreensMenu::~ScreensMenu() {
}