#include<iostream>
#include<fstream>
#include "Cube.h"
#include"Texture2D.h"


Cube::Cube(Mesh* mesh, Texture2D* texture,float x, float y, float z): SceneObject(mesh,texture)
{	
	
	
	mRotation = 0.0f;
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;

	mMaterial = new Material();
	mMaterial->ambient.x = 0.8f;
	mMaterial->ambient.y = 0.0f;
	mMaterial->ambient.z = 0.0f;
	mMaterial->ambient.w = 1.0f;

	mMaterial->diffuse.x = 1.0f;
	mMaterial->diffuse.y = 0.1f;
	mMaterial->diffuse.z = 0.1f;
	mMaterial->diffuse.w = 1.0f;

	mMaterial->specular.x = 0.0f;
	mMaterial->specular.y = 0.0f;
	mMaterial->specular.z = 0.0f;
	mMaterial->specular.w = 1.0f;

	mMaterial->shininess= 100.0f;
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(mMaterial->ambient.x));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(mMaterial->diffuse.x));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(mMaterial->specular.x));
	glMaterialf(GL_FRONT, GL_SHININESS, mMaterial->shininess);


}



void Cube::Update() {
	
	mRotation += 0.1f;

}



void Cube::Draw() {
	
	glBindTexture(GL_TEXTURE_2D, mTexture->GetID());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnable(GL_NORMAL_ARRAY);

	glNormalPointer(GL_FLOAT, 0, mMesh->normals);
	glVertexPointer(3, GL_FLOAT, 0, mMesh->vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, mMesh->texCoords);
	
	
	
	glPushMatrix();
		glTranslatef(mPosition.x, mPosition.y, mPosition.z);
		glRotatef(mRotation, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, mMesh->indexCount, GL_UNSIGNED_SHORT, mMesh->indices);
	glPopMatrix();

	
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}




Cube::~Cube()
{
	GLuint ID = mTexture->GetID();
	glDeleteTextures(GL_TEXTURE_2D,&ID);

	delete mMaterial;
	mMaterial = NULL;
}
