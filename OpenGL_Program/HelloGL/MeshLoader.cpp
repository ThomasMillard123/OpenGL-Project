
#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{	//load data from file
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadTextures(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	//load vertices from file
	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.vertexCount;

		if (mesh.vertexCount > 0)
		{
			mesh.vertices = new Vertex[mesh.vertexCount];

			for (int i = 0; i < mesh.vertexCount; i++)
			{
				
				inFile >> mesh.vertices[i].x;
				inFile >> mesh.vertices[i].y;
				inFile >> mesh.vertices[i].z;
			}
		}
	}
	//load UV's from file
	void LoadTextures(ifstream& inFile, Mesh& mesh) {
		inFile >> mesh.texCoordCount;
		mesh.texCoords = new TexCoord[mesh.texCoordCount];
		for (int i = 0; i < mesh.texCoordCount; i++) {
			inFile >> mesh.texCoords[i].u;
			inFile >> mesh.texCoords[i].v;
		}
	}
	//load normals from file
	void LoadNormals(ifstream& inFile, Mesh& mesh) {
		inFile >> mesh.normalCount;
		mesh.normals = new Vector3[mesh.normalCount];
		for (int i = 0; i < mesh.normalCount; i++) {
			inFile >> mesh.normals[i].x;
			inFile >> mesh.normals[i].y;
			inFile >> mesh.normals[i].z;
		}

	}
	//load indicces from file
	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.indexCount;
			mesh.indices = new GLushort[mesh.indexCount];
			for (int i = 0; i < mesh.indexCount; i++) {
				inFile >> mesh.indices[i];
			}
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();
		
		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open mesh text file " << path << endl;
			return nullptr;
		}

		//LOAD DATA USING METHODS ABOVE
		LoadVertices(inFile, *mesh);
		LoadTextures(inFile, *mesh);
		LoadNormals(inFile, *mesh);
		LoadIndices(inFile,  *mesh);
		//check if data is in file
		if (mesh->indexCount == 0 || mesh->vertexCount == 0 || mesh->texCoordCount == 0 || mesh->normalCount == 0) {
			cerr << "Error: File Empty" << endl;
			return nullptr;
		}
		else
		{
			cout << path << " mesh Loaded" << endl;
			return mesh;
		}
		
	}
}