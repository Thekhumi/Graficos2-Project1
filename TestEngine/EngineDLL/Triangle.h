#pragma once
#include "Entity.h"
class ENGINEDLL_API Triangle :
	public Entity
{
private:
	float*_vertex;
	int _vtxCount;
	unsigned int _bufferID = -1;
public:
	Triangle(Rendering *renderer);
	void setVertices(float* vertex, int vtxCount);
	void setMaterial(Material * mat);
	void dispose();
	void Draw() override;

	~Triangle();
};

