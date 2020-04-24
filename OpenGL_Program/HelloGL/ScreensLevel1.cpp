#include "ScreensLevel1.h"

#include"Cube.h"

ScreensLevel1::ScreensLevel1():Screens() {
	
	InitCamera();
	InitLight();
	InitObjects();
	mNextLevel = 2;
}

//setup camera
void ScreensLevel1::InitCamera()
{
	mCamera = new Camera();

	mCamera->eye.x = 0.0f;
	mCamera->eye.y = 0.0f;
	mCamera->eye.z = -126.0f;

	mCamera->center.x = 0.0f;
	mCamera->center.y = 0.0f;
	mCamera->center.z = 0.0f;

	mCamera->up.x = 0.0f;
	mCamera->up.y = 1.0f;
	mCamera->up.z = 0.0f;
}
//setup light
void ScreensLevel1::InitLight() {
	
	mLightPosition = new Vector4();
	mLightPosition->x = 0.0f;
	mLightPosition->y = 0.0f;
	mLightPosition->z = 1.0f;
	mLightPosition->w = 0.0f;

	mLightData = new Lighting();
	mLightData->ambient.x = 0.5f;
	mLightData->ambient.y = 0.5f;
	mLightData->ambient.z = 0.5f;
	mLightData->ambient.w = 1.0f;

	mLightData->diffuse.x = 0.8f;
	mLightData->diffuse.y = 0.8f;
	mLightData->diffuse.z = 0.8f;
	mLightData->diffuse.w = 1.0f;

	mLightData->specular.x = 0.8f;
	mLightData->specular.y = 0.8f;
	mLightData->specular.z = 0.8f;
	mLightData->specular.w = 1.0f;

}

//setpu objects
void ScreensLevel1::InitObjects() {
	mTitleText = "Cube field";
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");

	//add texture
	mTexture = new Texture2D();
	mTexture->Load((char*)"penguins.raw", 512, 512);

	/*add sceen objects*/
	for (int i = 0; i < 1000; i++)
	{
		mObjects[i] = new Cube(cubeMesh, mTexture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(RandomNumber(100)));
	}
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(mLightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(mLightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(mLightData->specular.x));

	glLightfv(GL_LIGHT0, GL_POSITION, &(mLightPosition->x));
}

void ScreensLevel1::Update() {
	Screens::Update();

	
	for (int i = 0; i < 1000; i++)
	{
		mObjects[i]->Update();
	}

	
}

void ScreensLevel1::Draw() {
	Vector3 textPosition = { 0.0f,10.0f,-100.0f };
	Color textColor = { 1.0f,1.0f,1.0f };
	
	DrawString(mTitleText, &textPosition, &textColor);
	

	for (int i = 0; i < 1000; i++)
	{
		mObjects[i]->Draw();
	}
	
}

void ScreensLevel1::Keyboard(unsigned char key, int x, int y) {

	//X,Y,Z camra movement
	if (key == 'w'|| key == 'W') {

		mCameraPosition.z += 0.5f;

	}
	if (key == 's'|| key == 'S') {

		mCameraPosition.z -= 0.5f;

	}
	if (key == 'a'|| key == 'A') {

		mCameraPosition.x += 0.5f;

	}
	if (key == 'd'|| key == 'D') {
		mCameraPosition.x-= 0.5f;
	}
	if (key == 'z'|| key == 'Z') {

		mCameraPosition.y -= 0.5f;

	}
	if (key == 'x'|| key == 'X') {
		mCameraPosition.y += 0.5f;
	}

	//camra rotation
	if (key == 'q'|| key == 'Q') {
		mSceenRotation -= 0.5f;
	}
	if (key == 'e'|| key == 'E') {
		mSceenRotation += 0.5f;
	}



}


ScreensLevel1::~ScreensLevel1() {
	delete[] &mObjects;
	
	delete mTexture;
	mTexture = NULL;
	
	
}