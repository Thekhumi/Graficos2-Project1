#pragma once
#include "Shape.h"
#include "Exports.h"
class ENGINEDLL_API Mesh :
	public Shape
{
public:
	Mesh(Rendering* renderer);
	~Mesh();
};

