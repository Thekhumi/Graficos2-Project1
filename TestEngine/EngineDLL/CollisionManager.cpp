#include "CollisionManager.h"
#include <math.h>


CollisionManager::CollisionManager(int layers){
	for (int i = 0; i < layers; i++)
	{
		CollisionGroups.push_back(new list<Entity*>());
	}
	_layersCant = layers;
}	

void CollisionManager::AddEntity(Entity* A, int layer) {
	CollisionGroups[layer]->push_back(A);
}

void CollisionManager::CheckLayers() {
	for (int i = 0; i < _layersCant; i++)
	{
		for (int j = i + 1; j < _layersCant; j++)
		{
			CheckCollisions(CollisionGroups[i], CollisionGroups[j]);
		}
	}
}

void CollisionManager::CheckCollisions(list<Entity*> *layerA, list<Entity*> *layerB) {
	for (list<Entity*>::iterator i = layerA->begin(); i != layerA->end(); ++i) {
		for (list<Entity*>::iterator j = layerB->begin(); j != layerB->end(); ++j) {
			Collision(*i, *j);
		}
	}
}

void CollisionManager::Collision(Entity* A, Entity* B){
	glm::vec2 Diff = (A->getBoxCollider()->getPos() - B->getBoxCollider()->getPos());
	glm::vec2 module = abs(Diff);
	if (module.x <= (A->getBoxCollider()->getWidth() + B->getBoxCollider()->getWidth()) / 2.0f && module.y <= 
	   (A->getBoxCollider()->getHeight() + B->getBoxCollider()->getHeight()) / 2.0f) {
		float xP = ((A->getBoxCollider()->getWidth() / 2.0f) + (B->getBoxCollider()->getWidth() / 2.0f)) - module.x;
		float yP = ((A->getBoxCollider()->getHeight() / 2.0f) + (B->getBoxCollider()->getHeight() / 2.0f)) - module.y;
		float totalMass = A->getBoxCollider()->getMass() + B->getBoxCollider()->getMass();
		float mass1 = A->getBoxCollider()->getMass();
		float mass2 = B->getBoxCollider()->getMass();
		if (xP > yP) {
			if (Diff.y > 0) {
				yP = -yP;
			}
			if (A->getBoxCollider()->getStatic()) {
				B->setPos(B->getPosX(), B->getPosY() - (yP), 0.0f);
			}
			else if (B->getBoxCollider()->getStatic())
			{
				A->setPos(A->getPosX(), A->getPosY() - (yP), 0.0f);
			}
			else
			{
				A->setPos(A->getPosX(), A->getPosY() - (yP * CalMass(totalMass, mass2)), 0.0f);
				B->setPos(B->getPosX(), B->getPosY() + (yP * CalMass(totalMass, mass1)), 0.0f);
			}
		}
		else {
			if (Diff.x > 0) {
				xP = -xP;
			}
			if (A->getBoxCollider()->getStatic())
			{
				B->setPos(B->getPosX() - (xP), B->getPosY(), 0.0f);
			}
			else if (B->getBoxCollider()->getStatic())
			{
				A->setPos(A->getPosX() - (xP), A->getPosY(), 0.0f);
			}
			else
			{
				A->setPos(A->getPosX() - (xP*CalMass(totalMass,mass2)), A->getPosY(), 0.0f);
				B->setPos(B->getPosX() + (xP*CalMass(totalMass,mass1)), B->getPosY(), 0.0f);

			}
		}
	}
}

float CollisionManager::CalMass(float totalMass, float mass) {
	float num = mass / totalMass;
	return num;
}
CollisionManager::~CollisionManager(){
}
