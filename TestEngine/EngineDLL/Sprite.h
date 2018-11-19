#pragma once
#include "Shape.h"
#include "TextureImporter.h"
#include "Frames.h"
class ENGINEDLL_API Sprite : public Shape
{
private:
	float*_vertex;
	float*_vertexUV;
	int _vtxCount;
	int _vtxCountUV;
	int _frameWidth;
	int _frameHeight;
	int _framesCant;
	unsigned int _bufferID = -1;
	unsigned int _bufferUV = -1;
	Texture * _texture;
	Frames * _frames;
	
public:
	Sprite(Rendering *renderer, const char * imagepath);
	void setVertices(float* vertex, int vtxCount, const char * imagepath);
	void Draw() override;
	void setTextureUV(int vtxCountUV, float * vertexUV);
	void setFrames(int frameWidth, int frameHeight, int textureHeight, int textureWidth);
	void setFrame(int frame);
	~Sprite();
};

