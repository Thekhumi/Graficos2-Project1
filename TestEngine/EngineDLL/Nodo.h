#pragma once
#include <vector>
#include "Component.h"

using namespace std;
class Nodo
{
private:
	vector<Component> * _components;
	vector<Nodo> * _nodes;
public:
	Nodo();
	~Nodo();
};

