#include "SceneObject.h"
#include"Texture2D.h"


SceneObject::SceneObject(Mesh* mesh, Texture2D* texture){
	_mesh = mesh;
	_texture = texture;
}

void SceneObject::update() {

}
void SceneObject::draw() {

}

SceneObject::~SceneObject(){
}
