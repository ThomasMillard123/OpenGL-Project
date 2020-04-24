#ifndef _SCREENSMENU_H
#define _SCREENSMENU_H


#include "Screens.h"
#include<string>
class ScreensMenu :
	public Screens
{
public:
	ScreensMenu();
	~ScreensMenu();

	void InitObjects();
	void InitCamera();
	void Update();
	void Draw();
private:
	const char* mSceen1ControllsText;
	const char* mSceen2ControllsText;
	const char* mGeneralControllsText;
 
};

#endif