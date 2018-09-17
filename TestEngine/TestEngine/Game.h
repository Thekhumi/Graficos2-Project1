#pragma once
#include "GameBase.h"
#include "Triangle.h"
class Game : public GameBase
{
private:
	int _pepito;
	Triangle * triangle;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate() override;
	void onDraw() override;
public:
	Game();
	~Game();
};

