#pragma once
#include "Exports.h"
#include "BoxCollider.h"
#include "Entity.h"
#include <vector>
#include <list>
using namespace std;
class ENGINEDLL_API CollisionManager
{
private:
	std::vector<list<Entity*>*> CollisionGroups;
	int _layersCant;
public:
	CollisionManager(int layers);
	void AddEntity(Entity* entity, int layer);
	void CheckLayers();
	void CheckCollisions(list<Entity*> *layerA, list<Entity*> *layerB);
	void Collision(Entity* A, Entity* B);
	float CalMass(float m1, float m2);
	~CollisionManager();
};

