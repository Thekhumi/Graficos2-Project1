#include "CompFBox.h"
#include <limits>

using namespace std;
CompFBox::CompFBox(){
}

void CompFBox::clear() {
	_minX = _minY = _minZ = numeric_limits<float>::max();
	_maxX = _maxY = _maxZ = numeric_limits<float>::min();
}
void CompFBox::updateBox(float  minX, float  minY, float  minZ, float  maxX, float  maxY, float  maxZ) {
		if (_minX > minX) {
			_minX = minX;
		}
		if (_minY > minY) {
			_minY = minY;
		}
		if (_minZ > minZ) {
			_minZ = minZ;
		}
		if (_maxX < maxX) {
			_maxX = maxX;
		}
		if (_maxY < maxY) {
			_maxY = maxY;
		}
		if (_maxZ < maxZ) {
			_maxZ = maxZ;
		}
}

void CompFBox::update() {
	clear();
}

void CompFBox::draw() {
	//Wire Cube code
}
CompFBox::~CompFBox()
{
}
