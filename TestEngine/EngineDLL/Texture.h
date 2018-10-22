#pragma once
#include "Exports.h"
class ENGINEDLL_API Texture
{
private:
	unsigned int _width;
	unsigned int _height;
	unsigned int _textureID;
public:
	Texture(unsigned int width, unsigned int height, unsigned int textureID);
	void setWidth(unsigned int width) { _width = width; };
	void setHeight(unsigned int height) { _height = height; };
	void setTextureID(unsigned int textureID) { _textureID = textureID; };
	unsigned int getWidth() { return _width; };
	unsigned int getHeight() { return _height; };
	unsigned int getTextureID() { return _textureID; };
	~Texture();
};

