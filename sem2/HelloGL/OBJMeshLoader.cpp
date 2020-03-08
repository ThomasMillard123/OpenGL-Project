
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
		std::vector< Vector3 > temp_vertices;
		std::vector< TexCoord > temp_texcoords;
		std::vector< Vector3> temp_normals;
		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;

		}

		std::string line;
		std::string lineStr;
		while (!inFile.eof())
		{
			
			inFile >> line;
			//found = line.find("v "); //enum to check the line type i,e Face ,vertex
			if (line == "v") //! check to see if the first char is v
			{
				Vector3 temp_vertex;
				inFile >> temp_vertex.x;
				inFile >> temp_vertex.y;
				inFile >> temp_vertex.z;
				temp_vertices.push_back(temp_vertex);


			}

			//  found = line.find("f ");
			if (line == "f") //! checkl to see if the first char is f
			{
				//what infromation belongs to v,vt,vn
				int n = 0;
				int t = 0;
				
				int arrayPos = 0;
				string v, vt, vn;

				//get data, v/vt/vn * 3 per line
				int tempVertexIndices[3], tempuvIndices[3], tempnormalIndices[3];
				
				while (true) {
					inFile >> lineStr;


					t = 0;
					 v="", vt="", vn="";
					for (int i = 0; i < lineStr.size(); i++)
					{
						
						if (lineStr[i] == '/') {
							t++;
						}
						else {
							if (t== 0) {
								v += lineStr[i];
								
							}
							else if (t== 1)
							{
								vt += lineStr[i];
								
							}
							else if (t == 2) {
								vn += lineStr[i];
								
							}
						}

						
					}
					

					if (n == 0) {
						tempVertexIndices[arrayPos] = std::stoi(v);
						n++;
					}
					if (n == 1)
					{
						tempuvIndices[arrayPos] = std::stoi(vt);
						n++;
					}
					if (n == 2) {
						tempnormalIndices[arrayPos] = std::stoi(vn);
						n++;
					}
					
					//one vertex end
					if (n == 3) {
						n = 0;
						
					}
					arrayPos++;
					//line end
					if (arrayPos== 3)
						break;
				}

				//store in index lists
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

			//  found = line.find("vn ");
			if (line == "vn") //! checkl to see if the first char is vn 
			{
				Vector3 temp_normal;
				inFile >> temp_normal.x;
				inFile >> temp_normal.y;
				inFile >> temp_normal.z;
				temp_normals.push_back(temp_normal);


			}
			//  found = line.find("vt ")
			if (line == "vt") //! checkl to see if the first char is vt
			{
				TexCoord temp_texcoord;
				inFile >> temp_texcoord.u;
				inFile >> temp_texcoord.v;
				temp_texcoords.push_back(temp_texcoord);

			}

		}

		
		OBJMesh vert;
		// indexed vertex info add

		for (int i = 0; i < normalIndices.size(); i++)
		{
			int index = vertexIndices[i];
			vert.pos = temp_vertices[index-1];
			vert.normal = temp_normals[normalIndices[i]-1];
			vert.texcoord = temp_texcoords[uvIndices[i]-1];
			
			mesh.push_back(vert);
		}
		
		
		return mesh;


	}
}