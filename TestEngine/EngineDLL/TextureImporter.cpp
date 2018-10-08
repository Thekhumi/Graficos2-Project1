#include "TextureImporter.h"
#include "Rendering.h"
#include <fstream>
#include <gl\glew.h>
#include <GLFW\glfw3.h>

TextureImporter::TextureImporter(){
}

unsigned int TextureImporter::loadBMP(const char * imagepath) {
	// Lectura de información del encabezado del archivo
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	unsigned char * data;
	FILE * file = NULL;
	if (fopen_s(&file, imagepath, "rb") != 0) { printf("Image could not be opened\n"); return 0; }

	if (fread_s(header, 54,  1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}

	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}

	dataPos = *(int*)&(header[0x0A]); //10
	width = *(int*)&(header[0x12]); //18
	height = *(int*)&(header[0x16]); //22
	imageSize = *(int*)&(header[0x22]); //34

	// Checkeo de formato BMP
	if (imageSize == 0)    imageSize = width * height * 3; // 3 : RED GREEN BLUE
	if (dataPos == 0)      dataPos = 54; // El encabezado del BMP está hecho de ésta manera

										 // Se crea un buffer
	data = new unsigned char[imageSize];

	// Leemos la información del archivo y la ponemos en el buffer
	fread_s(data, imageSize,  1, imageSize, file);

	//cerrar el archivo
	fclose(file);

	// Se Crea una textura OpenGL
	unsigned int textureID = Rendering::genTexture(width,height,data);
	return textureID;
}


TextureImporter::~TextureImporter(){
}
