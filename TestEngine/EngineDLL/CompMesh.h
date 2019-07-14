#pragma once
#include "Component.h"
#include "Exports.h"
class ENGINEDLL_API CompMesh :
	public Component
{
public:
	CompMesh();
	void draw() override {};
	void update() override {};
	~CompMesh();
};

