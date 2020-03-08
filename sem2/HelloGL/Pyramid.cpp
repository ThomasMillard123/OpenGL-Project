#include "Pyramid.h"



Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) :SceneObject(mesh, nullptr)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void Pyramid::update() {

	/*rotation += 0.1f;*/

}



void Pyramid::draw() {

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
	/*glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);*/
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	
	glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

}

Pyramid::~Pyramid()
{
}
