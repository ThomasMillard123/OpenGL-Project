#include "HelloGl.h"

#include<random>
#include <time.h>

#include"Texture2D.h"

#include"Cube.h"
#include"Pyramid.h"



HelloGl::HelloGl(int argc, char* argv[]){
	srand(time(NULL));

	initGL(argc, argv);
	initCamera();
	initObjects();
	initLight();

	glutMainLoop();

}

void HelloGl::initObjects() {
	sceenRotation = 0.0f;
	
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	//load untexture pryamid mesh (need colour array)
	/*Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");*/

	
	model = OBJMeshLoader::LoadOBJ((char*)"face.obj");
	
	//add texture
	/*Texture2D* texture = new Texture2D();
	texture->Load((char*)"penguins.raw", 512, 512);*/
	
	
	//add sceen objects
	//for (int i = 0; i < 500; i++)
	//{
	//	objects[i] = new Cube(cubeMesh,texture,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(RandomNumber(100))/*-(rand() % 1000) / 10.0f*/);
	//}
	//for (int i = 500; i < 1000; i++)
	//{
	//	objects[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(RandomNumber(100))/*-(rand() % 1000) / 10.0f*/);
	//}
	
	
	
}

void HelloGl::initCamera()
{
	camera = new Camera();

	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = -200.0f;

	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;

	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;
}

void HelloGl::initLight() {
	lightPosition = new Vector4();
	lightPosition->x = 0.0f;
	lightPosition->y = 0.0f;
	lightPosition->z = 1.0f;
	lightPosition->w = 0.0f;

	lightData = new Lighting();
	lightData->Ambient.x = 0.5f;
	lightData->Ambient.y = 0.5f;
	lightData->Ambient.z = 0.5f;
	lightData->Ambient.w = 1.0f;

	lightData->Diffuse.x = 0.8f;
	lightData->Diffuse.y = 0.8f;
	lightData->Diffuse.z = 0.8f;
	lightData->Diffuse.w = 1.0f;

	lightData->Specular.x = 0.8f;
	lightData->Specular.y = 0.8f;
	lightData->Specular.z = 0.8f;
	lightData->Specular.w = 1.0f;

}

void HelloGl::initGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGl Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::timer, REFRESHRATE);



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


void HelloGl::update() {
	glLoadIdentity();
	gluLookAt(
		camera->eye.x,
		camera->eye.y,
		camera->eye.z,
		camera->center.x,
		camera->center.y,
		camera->center.z,
		camera->up.x,
		camera->up.y,
		camera->up.z);
	

	/*for (int i = 0; i < 100; i++)
	{
		objects[i]->update();
	}*/

	//add light
	/*glLightfv(GL_LIGHT0, GL_AMBIENT, &(lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(lightData->Specular.x));

	glLightfv(GL_LIGHT0, GL_POSITION, &(lightPosition->x));*/


	glutPostRedisplay();
	
}

void HelloGl::display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	//load from .obj file draw
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnable(GL_NORMAL_ARRAY);

	glNormalPointer(GL_FLOAT, sizeof(OBJMesh), &model[0].normal);
	glVertexPointer(3, GL_FLOAT, sizeof(OBJMesh), &model[0].pos);
	glTexCoordPointer(2, GL_FLOAT, sizeof(OBJMesh), &model[0].texcoord);
	
	glRotatef(sceenRotation, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	glTranslatef(0, -5, 2);
	glDrawArrays(GL_TRIANGLES, 0, model.size());
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	

	//glRotatef(sceenRotation, 0.0f, 1.0f, 0.0f);
	//for (int i = 0; i < 100; i++)
	//{
	//	objects[i]->draw();
	//}

	glFlush();
	glutSwapBuffers();
}



void HelloGl::Keyboard(unsigned char key, int x, int y) {
	
	if (key == 'w') {
		camera->eye.z += 10.1f;
		
	}
	if (key == 's') {
		camera->eye.z -= 10.0f;

		
	}
	if (key == 'a') {
		
		camera->center.x += 1.0f;

	}
	if (key == 'd') {
		camera->center.x -= 1.0f;
		

	}
	if (key == 'q') {
		sceenRotation -= 0.5f;
		

	}
	if (key == 'e') {

		sceenRotation += 0.5f;

	}

	
}


int HelloGl::RandomNumber(int maxNumber) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution <int> dist(0, maxNumber);


	int randint = dist(mt);
	return randint;

}

HelloGl::~HelloGl(){
	delete camera;
	camera = NULL;

}
