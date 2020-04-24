#pragma once
//struct to define a x,y,z coradiant
struct Vector3
{
	float x;
	float y;
	float z;

};
//struct to define a x,y,z,w coradiant
struct Vector4
{
	float x, y, z, w;

};

//struct to define a camera
struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};
//struct to set up a Color
struct Color
{
	GLfloat r,g,b;
};
//struct to define a single vertex position
struct Vertex
{
	GLfloat x, y, z;
};
//struct to define a text coordiant
struct TexCoord
{
	GLfloat u;
	GLfloat v;

};


//struct for sorteing the mesh of objects
struct Mesh
{
	Vertex* vertices;
	Vector3* normals;
	GLushort* indices;
	TexCoord* texCoords;
	int vertexCount,normalCount,texCoordCount,indexCount;
};

struct OBJMesh
{
	Vertex vertex;
	TexCoord texCoord;
	Vector3 normal;

};

//struct for light in scene
struct Lighting
{
	Vector4 ambient,diffuse,specular;

};
//struct for marerial a object
struct Material
{
	Vector4 ambient, diffuse, specular;
	GLfloat shininess;
};
