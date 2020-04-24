#include "HelloGl.h"

#include<iostream>

#include"ScreensMenu.h"
#include"ScreensLevel1.h"
#include"SceensCars.h"

HelloGl::HelloGl(int argc, char* argv[]){
	
	InitGL(argc, argv);
	InitObjects();
	glutMainLoop();

}
//setup objects
void HelloGl::InitObjects() {
	
	Level = new ScreensMenu();
	
}
//setup window
void HelloGl::InitGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGl Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 1000, 800);
	gluPerspective(45, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	
}


void HelloGl::Update() {
	
	Level->Update();

	glutPostRedisplay();
	
}

//output screen
void HelloGl::Display(){
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	Level->Draw();

	glFlush();
	glutSwapBuffers();
}

//switch to next screen
void HelloGl::SwitchScreens() {
	
	if (Level->GetNextLevel() == 0) {
		Level = nullptr;
		Level = new ScreensMenu();
	}else if (Level->GetNextLevel() == 1) {
		Level = nullptr;
		Level = new ScreensLevel1();
	}else if (Level->GetNextLevel() == 2) {
		Level = nullptr;
		Level = new ScreensCars();
	}
	else {
		std::cout << "Invalied Level" << std::endl;
	}
}

//get keyborad inputs
void HelloGl::Keyboard(unsigned char key, int x, int y) {
	Level->Keyboard(key, x, y);

	if (key == 'c'|| key == 'C') {
		SwitchScreens();
	}
}


HelloGl::~HelloGl(){
	
	delete Level;
	Level = NULL;
}

