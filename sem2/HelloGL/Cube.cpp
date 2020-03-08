#include<iostream>
#include<fstream>
#include "Cube.h"
#include"Texture2D.h"





Cube::Cube(Mesh* mesh, Texture2D* texture,float x, float y, float z): SceneObject(mesh,texture)
{	
	
	
	rotation = 0.0f;
	position.x = x;
	position.y = y;
	position.z = z;

	material = new Material();
	material->Ambient.x = 0.8f;
	material->Ambient.y = 0.8f;
	material->Ambient.z = 0.8f;
	material->Ambient.w = 1.0f;

	material->Diffuse.x = 1.0f;
	material->Diffuse.y = 1.0f;
	material->Diffuse.z = 1.0f;
	material->Diffuse.w = 1.0f;

	material->Specular.x = 0.8f;
	material->Specular.y = 0.0f;
	material->Specular.z = 0.6f;
	material->Specular.w = 1.0f;

	material->Shininess= 1000.0f;
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(material->Ambient.x));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(material->Diffuse.x));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(material->Specular.x));
	glMaterialf(GL_FRONT, GL_SHININESS, material->Shininess);


}



void Cube::update() {

	rotation += 0.1f;

}



void Cube::draw() {
	
	
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnable(GL_NORMAL_ARRAY);

	glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, _mesh->texCoords);
	
	
	
	glPushMatrix();
	
		glTranslatef(position.x, position.y, position.z);
		glRotatef(rotation, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
	glPopMatrix();

	
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}




Cube::~Cube()
{
}
