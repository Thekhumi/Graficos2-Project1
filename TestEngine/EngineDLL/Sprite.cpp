#include "Sprite.h"




Sprite::Sprite(Rendering * renderer, const char * imagepath):Shape(renderer), _vertex(NULL), _bufferID(-1){
	_vertex = new float[12]{
		-0.5f,-0.5f,0.0f,
		-0.5f,0.0f,0.0f,
		0.5f,-0.5f,0.0f,
		0.5f,0.0f,0.0f,

	};
	_shouldDispose = false;
	setVertices(_vertex, 4,imagepath);
}

void Sprite::setVertices(float* vertex, int vtxCount, const char * imagepath) {
	if (_shouldDispose) {
		dispose();
	}
	_vertex = vertex;
	_vtxCount = vtxCount;
	_shouldDispose = true;

	_texture = TextureImporter::loadBMP(imagepath);
	_bufferID = _renderer->genBuffer(_vertex, sizeof(float) * vtxCount * 3);
}

void Sprite::Draw() {
	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
		}
		_renderer->Draw(_bufferID, _vtxCount, GL_TRIANGLE_STRIP,2);
	}
}
Sprite::~Sprite()
{
}
