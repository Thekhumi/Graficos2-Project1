#pragma once
#include "Shape.h"
#include "TextureImporter.h"
class ENGINEDLL_API Sprite : public Shape
{
private:
	float*_vertex;
	float*_vertexUV;
	int _vtxCount;
	int _vtxCountUV;
	int _frameWidth;
	int _frameHeight;
	unsigned int _bufferID = -1;
	unsigned int _bufferUV = -1;
	Texture * _texture;
public:
	Sprite(Rendering *renderer, const char * imagepath);
	void setVertices(float* vertex, int vtxCount, const char * imagepath);
	void Draw() override;
	void setTextureUV(int vtxCountUV, float * vertexUV);
	void setAnimations(int frameWidth, int frameHeight, int textureHeight, int textureWidth);
	~Sprite();
};

