#pragma once
#include "Shape.h"
class ENGINEDLL_API Triangle :
	public Shape
{
private:
	float*_vertex;
	int _vtxCount;
	unsigned int _bufferID = -1;
public:
	Triangle(Rendering *renderer);
	void setVertices(float* vertex, int vtxCount);
	void Draw() override;

	~Triangle();
};

