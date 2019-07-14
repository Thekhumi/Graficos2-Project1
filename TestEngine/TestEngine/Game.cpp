#include "Game.h"
#include <iostream>
using namespace std;


Game::Game(){
	
}


Game::~Game()
{
}

bool Game::onStart() {
	cout << "-OnStart-" << endl;
	escena = new Nodo("Escena");
	Nodo * camara = new Nodo("Camara");
	camara->addComponent(CCamera);
	escena->AddChild(camara);
	
	
	//oldCamera = new Camera();
	Material * mat = Material::loadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRAGMENT_SHADER_PATH);
	mesh = new Mesh(_renderer);
	mesh->setMaterial(mat);
	mesh->setScale(1, 1, 1);
	mesh->loadModel("Cube.obj");
	mesh->loadTexture("CubeTex.bmp",false);
	//oldCamera->setRenderer(_renderer);
	CompCamera * asd = (CompCamera*)camara->getComponent(CCamera);
	asd->setRenderer(_renderer);

	//(CompCamera*)camara->getComponent(CCamera)->setRenderer(_renderer);

	_renderer->setProjectiveMatrixPerspective(45.0f, 640.0f/640.0f, 0.1f, 100.0f);
	_renderer->setProjectionMatrixOrtho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	_renderer->setProjectionMode(Rendering::MODE::PERSPECTIVE);
	return true;
}

bool Game::onUpdate(double deltaTime) {
	//oldCamera->cameraInput(input(265),input(264),input(263), input(262) , input(87), input(83), input(81),input (69),input(340),input(344	),deltaTime);
	CompCamera * asd = (CompCamera*)escena->getNodo("Camara")->getComponent(CCamera);
	asd->cameraInput(input(265), input(264), input(263), input(262), input(87), input(83), input(81), input(69), input(340), input(344), deltaTime);
	return true;
}

void Game::onDraw() {
	mesh->Draw();
}

bool Game::onStop() {
	cout << "-OnStop-" << endl;
	return true;
}
