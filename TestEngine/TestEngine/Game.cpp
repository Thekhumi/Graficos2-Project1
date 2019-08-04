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
	//tank
	MeshImporter::importModel(&NodoBody,"Tank.obj",_renderer);
	escena->AddChild(NodoBody);
	NodoBody->setScale(0.15f, 0.15f, 0.15f);

	Body = (CompMesh*)NodoBody->getComponent(CMesh);
	//Punteros a Component
	camera = (CompCamera*)camNodo->getComponent(CCamera);
	meshC = (CompMesh*)meshNodo->getComponent(CMesh);
	//Body
	Body->setMaterial(mat);
	Body->loadTexture("car.bmp", false);
	//cabin
	NodoCabin = NodoBody->getNodo(0);
	NodoCabin->setPosY(NodoCabin->getPosY() + 2.3f);
	Cabin = (CompMesh*)NodoCabin->getComponent(CMesh);
	Cabin->setMaterial(mat);
	Cabin->loadTexture("cabin.bmp", false);
	//cannon
	NodoCannon = NodoCabin->getNodo(0);
	Cannon = (CompMesh*)NodoCannon->getComponent(CMesh);
	Cannon->setMaterial(mat);
	Cannon->loadTexture("cannon.bmp", false);

	//father Cube
	meshC->setMaterial(mat);
	meshC->loadModel("Cube.obj");
	meshC->loadTexture("CubeTex.bmp", false);
	//child Cube
	meshC2 = (CompMesh*)meshNodo2->getComponent(CMesh);
	meshC2->setMaterial(mat);
	meshC2->loadModel("Cube.obj");
	meshC2->loadTexture("CubeTex.bmp", false);
	
	//(CompCamera*)camNodo->getComponent(CCamera)->setRenderer(_renderer);

	camera->setCamInternals(45.0f, 640.0f / 640.0f, 0.1f, 100.0f);
	_renderer->setProjectionMatrixOrtho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	_renderer->setProjectionMode(Rendering::MODE::PERSPECTIVE);
	return true;
}

bool Game::onUpdate(double deltaTime) {
	camera->cameraInput(input(265), input(264), input(263), input(262), input(87), input(83), input(81), input(69), input(340), input(344), deltaTime);
	Nodo * meshNodo = escena->getNodo("Mesh");
	meshNodo->setPosX(meshNodo->getPosX() + 0.5f * deltaTime);
	NodoBody->setRotY(NodoBody->getRotation()[0] + 0.05f * deltaTime);
	//Tank controls
	if(input(74))
	NodoCabin->setRotY(NodoCabin->getRotation()[0] + 0.25f * deltaTime);
	if (input(76))
	NodoCabin->setRotY(NodoCabin->getRotation()[0] + -0.25f * deltaTime);
	if (input(75))
	NodoCannon->setRotX(NodoCannon->getRotation()[0] + 0.50f * deltaTime);
	if (input(73))
	NodoCannon->setRotX(NodoCannon->getRotation()[0] + -0.50f * deltaTime);
	return true;
}

void Game::onDraw() {
	escena->draw();
}

bool Game::onStop() {
	cout << "-OnStop-" << endl;
	return true;
}
