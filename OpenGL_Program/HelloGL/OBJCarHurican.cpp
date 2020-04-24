#include "OBJCarHurican.h"

#include"OBJMeshLoader.h"


OBJCarHurican::OBJCarHurican(char* path, float x, float y, float z, GLfloat rotation) :ObjSceneObject(path, x, y, z,rotation) {
	mTexture = new BMPLoader();
	mTexture->LoadBMP("putz.bmp", mID);
	mTexture->LoadBMP("beton.bmp", mID2);

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

	mMaterial->specular.x = 0.0f;
	mMaterial->specular.y = 0.0f;
	mMaterial->specular.z = 0.0f;
	mMaterial->specular.w = 1.0f;

	mMaterial->shininess = 100.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, &(mMaterial->ambient.x));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(mMaterial->diffuse.x));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(mMaterial->specular.x));
	glMaterialf(GL_FRONT, GL_SHININESS, mMaterial->shininess);
}

void OBJCarHurican::Update() {

}
void OBJCarHurican::Draw() {
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
	//use texture 1
	glBindTexture(GL_TEXTURE_2D, mID);
	//draw from start to 18850 vertexs
	glDrawArrays(GL_TRIANGLES, 0, 18850);
	//use no texture
	glBindTexture(GL_TEXTURE_2D, NULL);
	//draw next set of vertexs
	glDrawArrays(GL_TRIANGLES, 18000, 30000-18000);
	//use texture 2
	glBindTexture(GL_TEXTURE_2D, mID2);
	//draw rest of vertexs
	glDrawArrays(GL_TRIANGLES, 30000, mModel.size());
	glPopMatrix();


	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_CULL_FACE);
	
}
OBJCarHurican::~OBJCarHurican() {
	glDeleteTextures(1, &mID);
	glDeleteTextures(1, &mID2);

	
}