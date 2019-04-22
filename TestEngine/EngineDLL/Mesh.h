#pragma once
#include "Entity.h"
#include "Exports.h"
class ENGINEDLL_API Mesh :
	public Entity
{
public:
	Mesh(Rendering* renderer);
	~Mesh();
};

