#pragma once
#include "TypeDef.h"
#include "Exports.h"
#include "Rendering.h"
#include "Window.h"
class ENGINEDLL_API GameBase
{
private:
	Window * _window;
	bool _start;
	bool _stop;
	bool _update;
protected:
	Rendering * _renderer;
	virtual bool onStart() = 0;
	virtual bool onStop() = 0;
	virtual bool onUpdate() = 0;
	virtual void onDraw() = 0;
public:
	GameBase();
	bool start();
	bool stop();
	void loop();
	~GameBase();
};

