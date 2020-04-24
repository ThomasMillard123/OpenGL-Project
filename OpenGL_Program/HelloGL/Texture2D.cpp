#include "Texture2D.h"

#include<iostream>;
#include<fstream>;

Texture2D:: Texture2D() {

}


bool Texture2D::Load(char* path, int width, int height) {

	char* tempTextureData;
	int fileSize;
	std::ifstream inFile;
	mWidth = width;
	mHeight = height;

	inFile.open(path, std::ios::binary);

	if (!inFile.good()) {
		std::cerr << "Can't open texture file" << path << std::endl;
		return false;
	}
	//read in file data
	inFile.seekg(0, std::ios::end);
	fileSize = (int)inFile.tellg();
	tempTextureData = new char [fileSize];
	inFile.seekg(0, std::ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	std::cout << path << " loaded." << std::endl;
	//bind textures to id
	glGenTextures(1, &mID);
	glBindTexture(GL_TEXTURE_2D, mID);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, mWidth, mHeight, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
	//unbind texture
	glBindTexture(GL_TEXTURE_2D, NULL);

	delete [] tempTextureData;
	return true;

}


Texture2D:: ~Texture2D() {
	glDeleteTextures(1,&mID);
}

