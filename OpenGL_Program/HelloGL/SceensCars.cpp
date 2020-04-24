#include "SceensCars.h"
#include"OBJCarBugatti.h"
#include"OBJCarHurican.h"
#include"OBJTankIS7.h"
#include"OBJTankm26.h"
#include"BMPLoader.h"

ScreensCars::ScreensCars(): Screens() {

	mNextLevel = 0;
	InitCamera();
	InitLight();
	InitObjects();

}
//setup light
void ScreensCars::InitLight() {
	mLightPosition = new Vector4();
	mLightPosition->x = 0.0f;
	mLightPosition->y = 5.0f;
	mLightPosition->z = 0.0f;
	mLightPosition->w = 0.0f;

	mLightData = new Lighting();
	mLightData->ambient.x = 1.0f;
	mLightData->ambient.y = 1.0f;
	mLightData->ambient.z = 1.0f;
	mLightData->ambient.w = 1.0f;

	mLightData->diffuse.x = 0.7f;
	mLightData->diffuse.y = 0.7f;
	mLightData->diffuse.z = 0.7f;
	mLightData->diffuse.w = 1.0f;

	mLightData->specular.x = 0.3f;
	mLightData->specular.y = 0.3f;
	mLightData->specular.z = 0.3f;
	mLightData->specular.w = 1.0f;

}

//setup camera
void ScreensCars::InitCamera()
{
	mCamera = new Camera();

	mCamera->eye.x = 0.0f;
	mCamera->eye.y = 0.0f;
	mCamera->eye.z = 1.0f;

	mCamera->center.x = 0.0f;
	mCamera->center.y = 0.0f;
	mCamera->center.z = 0.0f;

	mCamera->up.x = 0.0f;
	mCamera->up.y = 1.0f;
	mCamera->up.z = 0.0f;
}


//setup objects
void ScreensCars::InitObjects() {
	
	mTitleText = "Car:";

	mCarName1Text = "Lamborghini Huracan";
	mCar1InfromationText = "Type:Sports Car \n"
		"Country of origin: Italy\n"
		"Information: The Huracan is manufactured by Italian automotive manufacturer \n"
		"Lamborghini. It has been produced from 2014 and it is still being produced.\n"
		"It's top speed it to be said to be around 341 km/h (212 mph).";


	mCarName2Text= "IS7";
	mCar2InfromationText="Type: Heavy Tank\n"
			"Country of origin: Soviet Union\n"
			"Information: The IS7 started life under the project title of Object 260\n"
			"and originally designed in 1945. It only existed in a prototype\n"
			"form of wich only 6 was built.This final design was armed with a stabilized 130 mm \n" 
			"(5.12 in) cannon fed by an autoloader, a total of 8 machine guns, infrared scopes, \n"
			"and armor up to 300 mm (11.8 in) thick.\n";

	 mCarName3Text= "Bugatti Veyron";
	 mCar3InfromationText="Type: Sports Car\n"
			"Country of origin: France(manufactured) and Germany(designed) \n"
			"Information: The car designed and developed in Germany by the Volkswagen\n"
			"Group and manufactured in Molsheim, France, by French automobile manufacturer\n"
			"Bugatti.The original version at 408.47 km/h (253.81 mph) which was recored\n"
			"during a test of the vehicle. There has be sevral version created between \n"
			"2005 and 2015.They are:Veyron 16.4,Grand Sport, Super Sport and\n"
			"Grand Sport Vitesse.";

	 mCarName4Text= "Tiger 1";
	 mCar4InfromationText="Type: Heavy Tank\n"
			"Country of origin: Germany\n"
			"Information: The Tiger 1 was designed 1938 between 1941.\n"
			"It had about 1,350 built between 1942 and 1944.\n"
			"The Tiger 1 need 5 crew to operate it, A commander,\n"
			"gunner, loader, driver and radio operator.\n"
			"The Tiger 1 operated in WW2 from 1942 until 1945 in Africa and Europe.";


	mCar[0] = new OBJCarHurican((char*)"huracan.obj", 0, -1.0f, -10,0);
	mCar[1]= new OBJCarBugatti((char*)"Bugatti.obj", 0, -1.5f, 10,-90.0f);
	mCar[2] = new OBJTankIS7((char*)"IS7.obj", 12, -2.0f, 0,-90);
	mCar[3] = new OBJTankm26((char*)"Tiger_I.obj", -10, -2.0f, 0,90);
}

void ScreensCars::Update() {
	Screens::Update();

	for (int i = 0; i < 4; i++) {
		mCar[i]->Update();;
	}
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(mLightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(mLightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(mLightData->specular.x));

	glLightfv(GL_LIGHT0, GL_POSITION, &(mLightPosition->x));
	
}

void ScreensCars::Draw() {
	Vector3 textPosition = { -0.0f,4.0f,-10.0f };
	Color textColor = { 0.0f,1.0f,1.0f };
	DrawString(mTitleText, &textPosition, &textColor);

	glRotatef(mCarLookingAt, 0.0f, 1.0f, 0.0f);

	//decided what vehical user is looking at
	if (mCarLookingAt == 90 || mCarLookingAt == -270) {
		mCar[2]->Rotate(mCarRotation, 0.0f, 1.0f, 0.0f);
		mCar[2]->Draw();
		Vector3 textPosition = { 10.0f,3.7f,0.0f };
		DrawString(mCarName2Text, &textPosition, &textColor);
		textPosition.z = -3.0f;
		textPosition.y -= 0.4f;
		DrawString(mCar2InfromationText,
			&textPosition, &textColor);
	}
	else if (mCarLookingAt == 180 || mCarLookingAt == -180) {
		mCar[1]->Rotate(mCarRotation, 0.0f, 1.0f, 0.0f);
		mCar[1]->Draw();
		Vector3 textPosition = { 0.5f,3.7f,10.0f };
		DrawString(mCarName3Text, &textPosition, &textColor);
		textPosition.x = 3.0f;
		textPosition.y -= 0.4f;
		DrawString(mCar3InfromationText,
			&textPosition, &textColor);
	}
	else if (mCarLookingAt == 270 || mCarLookingAt == -90) {
		mCar[3]->Rotate(mCarRotation, 0.0f, 1.0f, 0.0f);
		mCar[3]->Draw();
		Vector3 textPosition = { -10.0f,3.7f,0.1f };
		DrawString(mCarName4Text, &textPosition, &textColor);
		textPosition.z = 3.0f;
		textPosition.y -= 0.4f;
		DrawString(mCar4InfromationText,
			&textPosition, &textColor);
	}
	else {
		mCar[0]->Rotate(mCarRotation, 0.0f, 1.0f, 0.0f);
		mCar[0]->Draw();
		Vector3 textPosition = { -0.8f,3.7f,-10.0f };
		DrawString(mCarName1Text, &textPosition, &textColor);
		textPosition.x = -3.0f;
		textPosition.y -= 0.4f;
		DrawString(mCar1InfromationText,
			&textPosition, &textColor);
		mCarLookingAt = 0;
	}

	mCarRotation = 0.0f;
	
	
}

void ScreensCars::Keyboard(unsigned char key, int x, int y) {
	
	//camracontrols
	if (key == 'w'|| key == 'W') {

		mCameraPosition.z += 0.5;
		
	}
	if (key == 's'|| key == 'S') {

		mCameraPosition.z -= 0.5;

	}
	if (key == 'a'|| key == 'A') {

		mCameraPosition.x += 0.5f;

	}
	if (key == 'd'|| key == 'D') {
		mCameraPosition.x -= 0.5f;
	}
	if (key == 'z'|| key == 'Z') {

		mCameraPosition.y -= 0.5f;

	}
	if (key == 'x'||key == 'X') {
		mCameraPosition.y += 0.5f;
	}
	
	//Moddle controls
	if (key == 'r'|| key == 'R') {
		mCarRotation -= 0.5f;	
	}
	if (key == 't'|| key == 'T') {
		mCarRotation += 0.5f;
	}
	if (key == 'q'|| key == 'Q') {
		mCarLookingAt -= 90.0f;
		mCameraPosition.x = 0;
		mCameraPosition.y = 0;
		mCameraPosition.z = 0;
	}
	if (key == 'e'|| key == 'E') {
		mCarLookingAt += 90.0f;
		mCameraPosition.x = 0;
		mCameraPosition.y = 0;
		mCameraPosition.z = 0;
	}



}

ScreensCars::~ScreensCars() {

	delete[] mCar;
	

}