#include "Shape.h"



Shape::Shape(Rendering *renderer):Entity(renderer){

}

void Shape::dispose(){
	_renderer->destroyBuffer(_bufferID);
}

void Shape::setMaterial(Material * mat) {
	_material = mat;
}

Shape::~Shape()
{
	dispose();
}
