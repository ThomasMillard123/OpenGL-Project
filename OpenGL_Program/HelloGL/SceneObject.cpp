#include "SceneObject.h"
#include"Texture2D.h"

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture){
	mMesh = mesh;
	mTexture = texture;
}

void SceneObject::Update() {

}
void SceneObject::Draw() {

}

SceneObject::~SceneObject(){
}
