#pragma once
#include "Shape.h"
#include "TextureImporter.h"
class ENGINEDLL_API Sprite : public Shape
{
private:
	float*_vertex;
	int _vtxCount;
	unsigned int _bufferID = -1;
	Texture * _texture;
public:
	Sprite(Rendering *renderer, const char * imagepath);
	void setVertices(float* vertex, int vtxCount, const char * imagepath);
	void Draw() override;
	~Sprite();
};

