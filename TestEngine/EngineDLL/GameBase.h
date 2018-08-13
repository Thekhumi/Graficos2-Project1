#pragma once
#include "Exports.h"
#include "Rendering.h"
class ENGINEDLL_API GameBase
{
private:
	Rendering * _renderer;
	bool _start;
	bool _stop;
	bool _update;
protected:
	virtual bool onStart() = 0;
	virtual bool onStop() = 0;
	virtual bool onUpdate() = 0;
public:
	GameBase();
	bool start();
	bool stop();
	void loop();
	~GameBase();
};

