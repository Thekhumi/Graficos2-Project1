#include "CompFBox.h"
#include <limits>

using namespace std;
CompFBox::CompFBox(){
}

void CompFBox::clear() {
	_minX = _minY = _minZ = numeric_limits<float>::max();
	_maxX = _maxY = _maxZ = numeric_limits<float>::min();
}
void CompFBox::updateBox(float * minX, float * minY, float * minZ, float * maxX, float * maxY, float * maxZ, int count) {
	for (int i = 0; i < count; i++){
		if (_minX > minX[i]) {
			_minX = minX[i];
		}
		if (_minY > minY[i]) {
			_minY = minY[i];
		}
		if (_minZ > minZ[i]) {
			_minZ = minZ[i];
		}
		if (_maxX < maxX[i]) {
			_maxX = maxX[i];
		}
		if (_maxY < maxY[i]) {
			_maxY = maxY[i];
		}
		if (_maxZ < maxZ[i]) {
			_maxZ = maxZ[i];
		}
	}
}

void CompFBox::update() {
	clear();
}

void CompFBox::update() {
	//Wire Cube code
}
CompFBox::~CompFBox()
{
}
