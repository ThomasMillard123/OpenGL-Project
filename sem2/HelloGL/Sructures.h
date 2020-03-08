#pragma once
#include<vector>
struct Vector3
{
	float x;
	float y;
	float z;

};

struct Vector4
{
	float x, y, z, w;

};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Color
{
	GLfloat r,g,b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u;
	GLfloat v;

};

struct Mesh
{
	Vertex* Vertices;
	Vector3* Normals;
	GLushort* Indices;
	TexCoord* texCoords;
	int VertexCount,NormalCount,TexCoordCount,IndexCount;
};

struct OBJMesh
{
	Vector3 pos;
	TexCoord texcoord;
	Vector3 normal;

};

struct Lighting
{
	Vector4 Ambient,Diffuse,Specular;

};

struct Material
{
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};
