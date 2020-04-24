#include "Screens.h"
#include<random>


Screens::Screens() {

}
void Screens::InitCamera()
 {
	
 }
void Screens::InitLight() {
	

}
void Screens::InitObjects() {

}

void Screens::Update() {
	glLoadIdentity();

	//rotat the camera
	glRotatef(mSceenRotation, 0.0f,1.0f, 0.0f);
	//move the camera
	glTranslatef(mCameraPosition.x, mCameraPosition.y, mCameraPosition.z);

	gluLookAt(
		mCamera->eye.x,
		mCamera->eye.y,
		mCamera->eye.z,
		mCamera->center.x,
		mCamera->center.y,
		mCamera->center.z,
		mCamera->up.x,
		mCamera->up.y,
		mCamera->up.z);

	
 }
 void Screens:: Draw() {

 }
 

 int Screens::GetNextLevel() {
	 return mNextLevel;
}



void Screens::Keyboard(unsigned char key, int x, int y) {

	

}

void Screens::DrawString(const char* text, Vector3* position, Color* color) {

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRasterPos3f(0.0f, 0.0f,0.0f);
	glColor3f(color->r, color->g, color->b);
	//draw string
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glPopMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

int Screens::RandomNumber(int maxNumber) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution <int> dist(0, maxNumber);


	int randint = dist(mt);
	return randint;

}

Screens::~Screens() {
	delete mCamera;
	mCamera = NULL;

	delete mLightPosition;
	mLightPosition=NULL;

	delete mLightData;
	mLightData = NULL;
	
}

