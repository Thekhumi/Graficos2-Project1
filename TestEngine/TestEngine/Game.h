#pragma once
#include "GameBase.h"
#include "Nodo.h"
#include "Triangle.h"
#include "Square.h"
#include "Sprite.h"
#include "Refs.h"
#include "TextureImporter.h"
#include "Animation.h"
#include "Avatar.h"
#include "CollisionManager.h"
#include "ColorSquare.h"
#include "Circle.h"
#include "Tilemap.h"
#include "Tile.h"
#include "Camera.h"
#include "Mesh.h"
#include <vector>
class Game : public GameBase
{
private:
	CollisionManager * Cmanager;
	CompCamera * camera;
	CompMesh * meshC;
	CompMesh * meshC2;

	Nodo * escena;

	//tank
	CompMesh * Body;
	Nodo * NodoBody;
	CompMesh * Cabin;
	Nodo * NodoCabin;
	CompMesh * Cannon;
	Nodo * NodoCannon;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate(double _deltaTime) override;
	void onDraw() override;
public:
	Game();
	~Game();
};

