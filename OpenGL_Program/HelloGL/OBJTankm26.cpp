#include "OBJTankm26.h"
#include"OBJMeshLoader.h"


OBJTankm26::OBJTankm26(char* path, float x, float y, float z, GLfloat rotation) :ObjSceneObject(path, x, y, z, rotation) {
	mTexture = new BMPLoader();
	mTexture->LoadBMP("PzVl_Tiger_I.bmp", mID);
	mTexture->LoadBMP("Track.bmp", mID2);

	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;

	mMaterial = new Material();
	mMaterial->ambient.x = 0.8f;
	mMaterial->ambient.y = 0.8f;
	mMaterial->ambient.z = 0.8f;
	mMaterial->ambient.w = 1.0f;

	mMaterial->diffuse.x = 1.0f;
	mMaterial->diffuse.y = 1.0f;
	mMaterial->diffuse.z = 1.0f;
	mMaterial->diffuse.w = 1.0f;

	mMaterial->specular.x = 0.8f;
	mMaterial->specular.y = 0.0f;
	mMaterial->specular.z = 0.6f;
	mMaterial->specular.w = 1.0f;

	mMaterial->shininess = 1000.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, &(mMaterial->ambient.x));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(mMaterial->diffuse.x));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(mMaterial->specular.x));
	glMaterialf(GL_FRONT, GL_SHININESS, mMaterial->shininess);
}

void OBJTankm26::Update() {

}
void OBJTankm26::Draw() {
	//load from .obj file draw
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
	glBindTexture(GL_TEXTURE_2D, mID);
	glDrawArrays(GL_TRIANGLES, 0, 24100);
	glBindTexture(GL_TEXTURE_2D, mID2);
	glDrawArrays(GL_TRIANGLES, 24000, (mModel.size()-1)- 24000);
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_CULL_FACE);
	
}
OBJTankm26::~OBJTankm26() {
	glDeleteTextures(1, &mID);
	glDeleteTextures(1, &mID2);
	

}