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
	MeshImporter::importModel(&meshImport,"Tank.obj",_renderer);
	escena->AddChild(meshImport);

	CompMesh * meshImp = (CompMesh*)meshImport->getComponent(CMesh);
	//Punteros a Component
	camera = (CompCamera*)camNodo->getComponent(CCamera);
	camera->setRenderer(_renderer);
	meshC = (CompMesh*)meshNodo->getComponent(CMesh);
	//cabin
	meshImp->init(_renderer);
	meshImp->setMaterial(mat);
	meshImp->loadTexture("car.bmp", false);
	//cabin
	Nodo * nodoMesh2 = meshImport->getNodo("esh");
	nodoMesh2->setPosY(nodoMesh2->getPosY() + 2);
	CompMesh * meshImp2 = (CompMesh*)nodoMesh2->getComponent(CMesh);
	meshImp2->init(_renderer);
	meshImp2->setMaterial(mat);
	meshImp2->loadTexture("cabin.bmp", false);
	//cannon
	Nodo * nodoMesh3 = meshImport->getNodo("sh");
	nodoMesh3->setPosY(nodoMesh3->getPosY() + 2);
	CompMesh * meshImp3 = (CompMesh*)nodoMesh3->getComponent(CMesh);
	meshImp3->init(_renderer);
	meshImp3->setMaterial(mat);
	meshImp3->loadTexture("cannon.bmp", false);
	
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
	meshImport->setPosY(meshImport->getPosY() + 0.0f * deltaTime);
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
