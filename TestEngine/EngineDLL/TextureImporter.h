#pragma once
#include "Exports.h"
#include "Texture.h"
class ENGINEDLL_API TextureImporter
{
public:
	TextureImporter();
	static Texture* loadBMP(const char * imagepath);
	~TextureImporter();
};

