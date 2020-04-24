#ifndef _SCREENCARS_H
#define _SCREENCARS_H

#include "Screens.h"
class ScreensCars :
	public Screens
{
public:
	ScreensCars();
	~ScreensCars();

	void InitObjects();
	void InitCamera();
	void InitLight();
	void Keyboard(unsigned char key, int x, int y);
	void Update();
	void Draw();

private:

	ObjSceneObject* mCar[4];
	
	float mCarLookingAt, mCarRotation;

	const char* mCarName1Text;
	const char* mCar1InfromationText;

	const char* mCarName2Text;
	const char* mCar2InfromationText;

	const char* mCarName3Text;
	const char* mCar3InfromationText;

	const char* mCarName4Text;
	const char* mCar4InfromationText;
};

#endif