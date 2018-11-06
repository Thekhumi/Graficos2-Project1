#pragma once
#include "GameBase.h"
#include "Triangle.h"
#include "Square.h"
#include "Sprite.h"
#include "Defs.h"
#include "TextureImporter.h"
class Game : public GameBase
{
private:
	int _pepito;
	Triangle * triangle;
	Square * square;
	Sprite * sprite;
	float _vel;
	float _rot;
	float _pos;
	float _scale;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate(double _deltaTime) override;
	void onDraw() override;
public:
	Game();
	~Game();
};

