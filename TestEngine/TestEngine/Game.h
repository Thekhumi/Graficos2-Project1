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
class Game : public GameBase
{
private:
	CollisionManager * Cmanager;
	Triangle * triangle;
	Square * square;
	Sprite * sprite;
	Sprite * wallSprite;
	Animation * spriteAnimation;
	Avatar * Personaje;
	float _vel;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate(double _deltaTime) override;
	void onDraw() override;
public:
	Game();
	~Game();
};

