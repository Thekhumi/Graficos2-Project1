#pragma once
#include "TextureImporter.h"
class ENGINEDLL_API Frames
{
private:
	float * _vertexUV;
public:
	Frames();
	void setVertexUV(float u1, float u2, float v1, float v2);
	float * getVertexUV() { return _vertexUV; };
	~Frames();
};

