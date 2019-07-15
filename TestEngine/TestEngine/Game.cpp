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
	//nodos
	escena = new Nodo("Escena",_renderer);
	Nodo * camNodo = new Nodo("Camara", _renderer);
	Nodo * meshNodo = new Nodo("Mesh", _renderer);
	//parenting test
	Nodo * meshNodo2 = new Nodo("Mesh2", _renderer);
	meshNodo2->setPosY(meshNodo2->getPosY() - 1.2f);
	meshNodo2->setPosX(meshNodo2->getPosX() - 1.5f);

	camNodo->addComponent(CCamera);
	meshNodo->addComponent(CMesh);
	
	meshNodo2->addComponent(CMesh);

	escena->AddChild(camNodo);
	escena->AddChild(meshNodo);

	meshNodo->AddChild(meshNodo2);
	
	Material * mat = Material::loadMaterial(TEXTURE_VERTEX_SHADER_PATH, TEXTURE_FRAGMENT_SHADER_PATH);
	MeshImporter::importModel(&meshImport,"Cube.obj",_renderer);
	escena->AddChild(meshImport);
	CompMesh * meshImp = (CompMesh*)meshImport->getComponent(CMesh);
	//mesh = new Mesh(_renderer);
	//mesh->setMaterial(mat);
	//mesh->setScale(1, 1, 1);
	//mesh->loadModel("Cube.obj");
	//mesh->loadTexture("CubeTex.bmp",false);
	
	//Punteros a Component
	camera = (CompCamera*)camNodo->getComponent(CCamera);
	camera->setRenderer(_renderer);
	meshC = (CompMesh*)meshNodo->getComponent(CMesh);
	meshImp->init(_renderer);
	meshImp->setMaterial(mat);
	meshImp->loadTexture("CubeTex.bmp", false);
	meshC->init(_renderer);
	meshC->setMaterial(mat);
	meshC->loadModel("Cube.obj");
	meshC->loadTexture("CubeTex.bmp", false);

	meshC2 = (CompMesh*)meshNodo2->getComponent(CMesh);
	meshC2->init(_renderer);
	meshC2->setMaterial(mat);
	meshC2->loadModel("Cube.obj");
	meshC2->loadTexture("CubeTex.bmp", false);
	
	//(CompCamera*)camara->getComponent(CCamera)->setRenderer(_renderer);

	_renderer->setProjectiveMatrixPerspective(45.0f, 640.0f/640.0f, 0.1f, 100.0f);
	_renderer->setProjectionMatrixOrtho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	_renderer->setProjectionMode(Rendering::MODE::PERSPECTIVE);
	return true;
}

bool Game::onUpdate(double deltaTime) {
	camera->cameraInput(input(265), input(264), input(263), input(262), input(87), input(83), input(81), input(69), input(340), input(344), deltaTime);
	Nodo * meshNodo = escena->getNodo("Mesh");
	meshNodo->setPosX(meshNodo->getPosX() + 0.5f * deltaTime);
	meshImport->setPosY(meshImport->getPosY() + 0.5f * deltaTime);
	return true;
}

void Game::onDraw() {
	//mesh->Draw();
	escena->draw();
}

bool Game::onStop() {
	cout << "-OnStop-" << endl;
	return true;
}
