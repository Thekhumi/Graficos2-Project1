#pragma once
#include "Exports.h"

enum ComponentType { CCamera, CMesh };
class  ENGINEDLL_API Component
{
private:
	ComponentType _type;
public:
	Component();

	virtual void update() {};
	virtual void draw() {};

	//component
	ComponentType  getType() { return _type; };
	void setType(ComponentType type) { _type = type; };
	~Component();
};

