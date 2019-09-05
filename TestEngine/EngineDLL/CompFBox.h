#pragma once
#include "Component.h"
#include "exports.h"
class ENGINEDLL_API CompFBox : public Component
{
private:
	float _minX;
	float _minY;
	float _minZ;
	float _maxX;
	float _maxY;
	float _maxZ;
public:
	CompFBox();
	void updateBox(float * minX, float * minY, float * minZ, float * maxX, float * maxY, float * maxZ, int count);
	~CompFBox();
};

