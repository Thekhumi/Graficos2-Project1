#include "Nodo.h"


using namespace std;


Nodo::Nodo(){

}

void Nodo::update() {
	for (int i = 0; i < _nodes->size(); i++) {
		_nodes->at(i).update();
	}
	for (int i = 0; i < _components->size(); i++) {
		_components->at(i).update();
	}
}


Nodo::~Nodo()
{
}
