#pragma once
#include "Entity.h"
class ENGINEDLL_API Shape :
	public Entity
{
protected:
	float*_vertex;
	int _vtxCount;
	unsigned int _bufferID = -1;
public:
	Shape(Rendering *renderer);
	void setMaterial(Material * mat);
	void dispose();
	~Shape();
};

