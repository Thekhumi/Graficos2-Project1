#pragma once
#include "Rendering.h"
#include "Material.h"
class ENGINEDLL_API Entity
{
protected:
	Rendering * _renderer;
	Material * _material;
	bool _shouldDispose;
public:
	Entity(Rendering * rend);
	virtual void Draw() = 0;
	~Entity();
};

