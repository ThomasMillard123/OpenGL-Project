
#include"OBJMeshLoader.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include<string>
#include<vector>



using namespace std;

namespace OBJMeshLoader
{

	std::vector<OBJMesh> OBJMeshLoader::LoadOBJ(char* path)
	{

		std::vector<OBJMesh> mesh;


		std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
		std::vector< Vertex > tempVertices;
		std::vector< TexCoord > tempTexcoords;
		std::vector< Vector3> tempNormals;
		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open obj file " << path << endl;

		}

		std::string line;
		std::string lineStr;
		while (!inFile.eof())
		{
			
			inFile >> line;
			
			//get infromation of vertex
			if (line == "v") 
			{
				Vertex tempVertex;
				inFile >> tempVertex.x;
				inFile >> tempVertex.y;
				inFile >> tempVertex.z;
				tempVertices.push_back(tempVertex);


			}

			//get infromation of the face
			if (line == "f") 
			{
				
				int typeSortFromArray = 0;
				int tyepSortFromFile = 0;
				int arrayPos = 0;

				string v, vt, vn;
				int tempVertexIndices[3], tempuvIndices[3], tempnormalIndices[3];
				
				while (true) {
					inFile >> lineStr;

					tyepSortFromFile = 0;
					 v="", vt="", vn="";
					
					//read one vertex index of a face form file(vertex/texcord/normal)
					for (int i = 0; i < lineStr.size(); i++)
					{
						
						if (lineStr[i] == '/') {
							tyepSortFromFile++;
						}
						else {
							if (tyepSortFromFile == 0) {
								v += lineStr[i];
								
							}
							else if (tyepSortFromFile == 1)
							{
								vt += lineStr[i];
								
							}
							else if (tyepSortFromFile == 2) {
								vn += lineStr[i];
								
							}
							else
							{
								cerr << "Error: Too many inputs";
								return mesh;
							}
						}
	
					}
					
					//store face infromation
					if (typeSortFromArray == 0) {
						tempVertexIndices[arrayPos] = std::stoi(v);
						typeSortFromArray++;
					}
					if (typeSortFromArray == 1)
					{
						tempuvIndices[arrayPos] = std::stoi(vt);
						typeSortFromArray++;
					}
					if (typeSortFromArray == 2) {
						tempnormalIndices[arrayPos] = std::stoi(vn);
						typeSortFromArray++;
					}
					if (typeSortFromArray == 3) {
						typeSortFromArray = 0;
						
					}
					arrayPos++;
					
					if (arrayPos == 3) {
						break;
					}
				}

				
				vertexIndices.push_back(tempVertexIndices[0]);
				vertexIndices.push_back(tempVertexIndices[1]);
				vertexIndices.push_back(tempVertexIndices[2]);
				uvIndices.push_back(tempuvIndices[0]);
				uvIndices.push_back(tempuvIndices[1]);
				uvIndices.push_back(tempuvIndices[2]);
				normalIndices.push_back(tempnormalIndices[0]);
				normalIndices.push_back(tempnormalIndices[1]);
				normalIndices.push_back(tempnormalIndices[2]);


			}

			//get infromation of normal
			if (line == "vn") 
			{
				Vector3 temp_normal;
				inFile >> temp_normal.x;
				inFile >> temp_normal.y;
				inFile >> temp_normal.z;
				tempNormals.push_back(temp_normal);


			}
			
			//get infromation of text cord
			if (line == "vt") 
			{
				TexCoord temp_texcoord;
				inFile >> temp_texcoord.u;
				inFile >> temp_texcoord.v;
				tempTexcoords.push_back(temp_texcoord);

			}

		}

		OBJMesh vert;
		//index vertexes,normals and texcords
		for (int i = 0; i < normalIndices.size(); i++)
		{
			int index = vertexIndices[i];
			vert.vertex = tempVertices[index-1];
			vert.normal = tempNormals[normalIndices[i]-1];
			vert.texCoord = tempTexcoords[uvIndices[i]-1];
			
			mesh.push_back(vert);
		}
		
		if (mesh.empty()) {
			cerr << "Error: OBJ Mesh not Loaded" <<endl;
			return mesh;
		}
		else {
			cout << path << " Mesh Loaded"<<endl;
			return mesh;
		}


	}
}