#pragma once
#include "GameBase.h"
#include "Triangle.h"
#include "Square.h"
#include "Sprite.h"
#include "Defs.h"
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
	Square * square;
	Mesh * mesh;
	Camera * camera;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate(double _deltaTime) override;
	void onDraw() override;
public:
	Game();
	~Game();
};

