#include "Plane.h"
#include <iostream>

using namespace std;

Plane::Plane()
{
}

Plane::Plane(vec3 &v1, vec3 &v2, vec3 &v3) {
	setPoints(v1, v2, v3);
}

void Plane::setPoints(vec3 &v1, vec3 &v2, vec3 &v3) {


	vec3 aux1, aux2;

	aux1 = v1 - v2;
	aux2 = v3 - v2;

	_normal = cross(aux1, aux2);

	_normal =  normalize(_normal);
	_point.x = v2.x;
	_point.y = v2.y;
	_point.z = v2.z;
	
	vec3 innerProduct;
	innerProduct.x = _normal.x * _point.x;
	innerProduct.y = _normal.y * _point.y;
	innerProduct.z = _normal.z * _point.z;
	_d = (innerProduct.x + innerProduct.y + innerProduct.z);
}

float Plane::distance(vec3 &p) {
	vec3 innerProduct;
	innerProduct.x = _normal.x * p.x;
	innerProduct.y = _normal.y * p.y;
	innerProduct.z = _normal.z * p.z;
	float val = innerProduct.x + innerProduct.y + innerProduct.z + _d;
	return (val);
}

void Plane::print() {
	cout << "Plane: " << _normal.x << ", " << _normal.y << ", " << _normal.z << ". Dir: " << _d << endl;
}

vec3 Plane::cross(vec3 &v1 ,vec3 &v2) {
	vec3 ret;
	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return ret;
}
Plane::~Plane()
{
}
