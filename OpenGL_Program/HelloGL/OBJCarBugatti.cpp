#include "OBJCarBugatti.h"
#include"OBJMeshLoader.h"


OBJCarBugatti::OBJCarBugatti(char* path,float x, float y, float z, GLfloat rotation) :ObjSceneObject(path, x,y,z,rotation) {
	

	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;

	mMaterial = new Material();
	mMaterial->ambient.x = 1.0f;
	mMaterial->ambient.y = 1.0f;
	mMaterial->ambient.z = 1.0f;
	mMaterial->ambient.w = 1.0f;

	mMaterial->diffuse.x = 1.0f;
	mMaterial->diffuse.y = 1.0f;
	mMaterial->diffuse.z = 1.0f;
	mMaterial->diffuse.w = 1.0f;

	mMaterial->specular.x = 0.2f;
	mMaterial->specular.y = 0.2f;
	mMaterial->specular.z = 0.2f;
	mMaterial->specular.w = 1.0f;

	mMaterial->shininess = 5.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, &(mMaterial->ambient.x));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(mMaterial->diffuse.x));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(mMaterial->specular.x));
	glMaterialf(GL_FRONT, GL_SHININESS, mMaterial->shininess);
}

void OBJCarBugatti::Update() {
}


void OBJCarBugatti::Draw() {
	glDisable(GL_CULL_FACE);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnable(GL_NORMAL_ARRAY);

	glNormalPointer(GL_FLOAT, sizeof(OBJMesh), &mModel[0].normal);
	glVertexPointer(3, GL_FLOAT, sizeof(OBJMesh), &mModel[0].vertex);
	glTexCoordPointer(2, GL_FLOAT, sizeof(OBJMesh), &mModel[0].texCoord);

	glPushMatrix();
	glTranslatef(mPosition.x, mPosition.y, mPosition.z);
	glRotatef(mRotationSpeed, mRotationPoint.x, mRotationPoint.y, mRotationPoint.z);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDrawArrays(GL_TRIANGLES, 0, mModel.size());
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_CULL_FACE);
	
}
OBJCarBugatti::~OBJCarBugatti() {
	
}