#pragma once

enum ComponentType { CCamera, CMesh };
class Component
{
public:
	Component();

	virtual void update();
	virtual void draw();

	~Component();
};

