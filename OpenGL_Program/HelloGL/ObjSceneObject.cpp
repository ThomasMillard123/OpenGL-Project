#include "ObjSceneObject.h"
#include"OBJMeshLoader.h";


ObjSceneObject::ObjSceneObject(char* path, float x, float y, float z, GLfloat rotation)
{	
	mRotationSpeed = rotation;
	mRotationPoint.x = 0.0f;
	mRotationPoint.y = 1.0f;
	mRotationPoint.z = 0.0f;
	//load mesh
	mModel = OBJMeshLoader::LoadOBJ(path);
	
}

void ObjSceneObject::Update() {

}
void ObjSceneObject::Draw() {
	
}
void ObjSceneObject::Rotate(GLfloat rotation,float x, float y, float z) {
	
	mRotationPoint.x = x;
	mRotationPoint.y = y;
	mRotationPoint.z = z;
	mRotationSpeed += rotation;
}

ObjSceneObject::~ObjSceneObject()
{
	mModel.clear();

	delete mTexture;
	mTexture = NULL;
	delete mMaterial;
	mMaterial = NULL;
}
