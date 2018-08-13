#pragma once
#include "GameBase.h"
class Game : public GameBase
{
private:
	int _pepito;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate() override;
public:
	Game();
	~Game();
};

