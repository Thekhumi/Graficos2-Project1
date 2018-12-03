#pragma once
#include "Shape.h"
#include "Exports.h"
class ENGINEDLL_API Circle :
	public Shape{
private:
	float*_vertex;
	int _vtxCount;
	unsigned int _bufferID = -1;
	int _triangleCant;
	float _radius;
	float _angle;
	float _degree;

public:
	Circle(Rendering * renderer, int triangleCant, float radius);
	void setVertices(float* vertex, int vtxCount);
	void Draw() override;
	~Circle();
};

