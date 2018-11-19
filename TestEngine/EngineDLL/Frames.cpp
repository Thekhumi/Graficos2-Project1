#include "Frames.h"



Frames::Frames()
{
	_vertexUV = new float[8]{
		0.0f,0.0f,
		0.0f,0.0f,
		0.0f,0.0f,
		0.0f,0.0f
	};
}

void Frames::setVertexUV(float u1, float u2, float v1, float v2) {
	_vertexUV[0] = u1; _vertexUV[1] = v2;
	_vertexUV[2] = u1; _vertexUV[3] = v1;
	_vertexUV[4] = u2; _vertexUV[5] = v2;
	_vertexUV[6] = u2; _vertexUV[7] = v1;
}


Frames::~Frames()
{
}
