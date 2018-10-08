#pragma once
#include "Exports.h"
class ENGINEDLL_API TextureImporter
{
public:
	TextureImporter();
	static unsigned int  loadBMP(const char * imagepath);
	~TextureImporter();
};

