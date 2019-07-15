#include "Nodo.h"
#include <iostream>

using namespace std;


Nodo::Nodo(const char * name, Rendering * renderer): _name(name),_renderer(renderer){
	_position[0] = _position[1] = _position[2] = 0.0f;
	_rotation[0] = _rotation[1] = _rotation[2] = 0.0f;
	_scale[0] = _scale[1] = _scale[2] = 1.0f;

	_modelMat = glm::mat4(1.0f);
	_translateMat = glm::mat4(1.0f);
	_rotateXMat = glm::mat4(1.0f);
	_rotateYMat = glm::mat4(1.0f);
	_rotateZMat = glm::mat4(1.0f);
	_scaleMat = glm::mat4(1.0f);
}

void Nodo::update() {
	for (int i = 0; i < _components.size(); i++) {
		_components[i]->update();
	}
	for (int i = 0; i < _nodes.size(); i++) {
		_nodes[i]->update();
	}
}

void Nodo::draw(){
	glm::mat4 currentModelMatrix = _renderer->getModel();
	_renderer->multiplyMatrix(_modelMat);
	for (int i = 0; i < _components.size(); i++) {
		_components[i]->draw();
	}
	for (int i = 0; i < _nodes.size(); i++) {
		_nodes[i]->draw();
	}
	_renderer->setMatrix(currentModelMatrix);
}
void Nodo::AddChild(Nodo* newChild) {
	if (newChild == this) {
		cout << "ERROR: El nodo es si mismo" << endl;
		return;
	}
	vector<Nodo*>::iterator itA;
	for (itA = _nodes.begin(); itA != _nodes.end(); itA++) {
		if (*itA == newChild) {
			cout << "ERROR: Ya es hijo." << endl;
			return;
		}
	}
	_nodes.push_back(newChild);
	cout << "Hijo Agregado correctamente" << endl;
}

void Nodo::RemoveChild(const char * name) {
	if (_nodes.size() == 0) {
		cout << "ERROR: Nodo no tiene hijos." << endl;
		return;
	}
	bool finished = false;
	int counter = 0;
	while (finished) {
		finished = true;
		for (int i = 0; i < _nodes.size(); i++) {
			if (_nodes[i]->getName() != name) {
				_nodes.erase(_nodes.begin() + i);
				finished = false;
				counter++;
				break;
			}
		}
	}
	if (counter > 0) {
		cout << "SUCCESS: Se removieron " << counter << " elementos." << endl;
		return;
	}
	cout << "ERROR: Hijo no encontrado" << endl;
}

Nodo * Nodo::getNodo(const char * name) {
	if (_nodes.size() == 0) {
		cout << "ERROR: Nodo no tiene hijos" << endl;
	}
	for (int i = 0; i < _nodes.size(); i++){
		if (_nodes[i]->getName() == name) {
			return _nodes[i];
		}
	}
	cout << "ERROR: Nodo no encontrado." << endl;
	return NULL;
}
bool Nodo::addComponent(ComponentType type) {
	if (getComponent(type) != NULL) {
		cout << "COMPONENTE YA EXISTE" << endl;
		return false;
	}
	switch (type) {
	case CCamera:
	{
		CompCamera * camera = new CompCamera();
		camera->setType(CCamera);
		_components.push_back(camera);
		break;
	}
	case CMesh:
	{
		CompMesh * mesh = new CompMesh();
		mesh->setType(CMesh);
		mesh->setModelMat(&_modelMat);
		_components.push_back(mesh);
		break;
	}
	default:
	{
		cout << "ERROR: Componente no programado" << endl;
		return false;
	}
	}
	cout << "Componente Agregado correctamente" << endl;
	return true;
}

bool Nodo::attachComponent(ComponentType type, Component * component) {
	if (getComponent(type) != NULL) {
		cout << "COMPONENTE YA EXISTE" << endl;
		return false;
	}
	switch (type) {
	case CCamera:
	{
		CompCamera * camera = (CompCamera*)component;
		camera->setType(CCamera);
		_components.push_back(camera);
		break;
	}
	case CMesh:
	{
		CompMesh * mesh = (CompMesh*)component;
		mesh->setType(CMesh);
		mesh->setModelMat(&_modelMat);
		_components.push_back(mesh);
		break;
	}
	default:
	{
		cout << "ERROR: Componente no programado" << endl;
		return false;
	}
	}
	cout << "Componente Agregado correctamente" << endl;
	return true;
}
bool Nodo::removeComponent(ComponentType type) {
	if (_components.size() == 0) {
		cout << "ERROR: Nodo no tiene componentes" << endl;
	}
	for (int i = 0; i < _components.size(); i++){
		if (_components[i]->getType() == type) {
			_components.erase(_components.begin() + i);
			cout << "Componente eliminado correctamente" << endl;
			return true;
		}
	}
	cout << "ERROR: Componente no encontrado" << endl;
	return false;
}

Component * Nodo::getComponent(ComponentType type) {
	for (int i = 0; i < _components.size(); i++){
		if (_components[i]->getType() == type) {
			return _components[i];
		}
	}
	return NULL;
}
Nodo::~Nodo(){
	for (int i = 0; i < _nodes.size(); i++) {
		delete _nodes[i];
	}
	for (int i = 0; i < _components.size(); i++){
		delete _components[i];
	}
	cout << "nodo eliminado" << endl;
}
