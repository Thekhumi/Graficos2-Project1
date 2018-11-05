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
	_vertexUV = new float[8]{
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f
	};
	_vtxCountUV = 8;
	_bufferUV = _renderer->genBuffer(_vertexUV, _vtxCountUV);
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

void Sprite::setTextureUV(int vtxCountUV, float * vertexUV) {
	_vertexUV = vertexUV;
	_vtxCountUV = vtxCountUV;
}
void Sprite::Draw() {
	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
			_material->bindTexture(*_texture);
		}
		_renderer->bind(_bufferID, 3, 0);
		_renderer->bind(_bufferUV, 2, 1);
		_renderer->Draw(_bufferID, _vtxCount, GL_TRIANGLE_STRIP,2,0);
		_renderer->disableVtx(0);
		_renderer->disableVtx(1);
	}
}
Sprite::~Sprite()
{
}
