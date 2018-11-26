#include "Sprite.h"
#include <iostream>


using namespace std;

Sprite::Sprite(Rendering * renderer, const char * imagepath,bool hasAlphaC):Shape(renderer), _vertex(NULL), _bufferID(-1),_hasAlphaC(hasAlphaC){
	_vertex = new float[12]{
		-0.5f, -0.5f, 0.f,
		-0.5f, 0.5f, 0.f,
		0.5f, -0.5f, 0.f,
		0.5f, 0.5f, 0.f
	};
	_shouldDispose = false;
	setVertices(_vertex, 4,imagepath);
	_vertexUV = new float[8]{
		0.0f,0.0f,
		0.0f, 1.0f,
		1.0f,0.0f,
		1.0f,1.0f
	};
	_vtxCountUV = 4;
	_bufferUV = _renderer->genBuffer(_vertexUV, sizeof(float)* _vtxCountUV * 2);
}

void Sprite::setVertices(float* vertex, int vtxCount, const char * imagepath) {
	if (_shouldDispose) {
		dispose();
	}
	_vertex = vertex;
	_vtxCount = vtxCount;
	_shouldDispose = true;

	_texture = TextureImporter::loadBMP(imagepath,_hasAlphaC);
	_bufferID = _renderer->genBuffer(_vertex, sizeof(float) * vtxCount * 3);
}

void Sprite::setTextureUV(int vtxCountUV, float * vertexUV) {
	_vertexUV = vertexUV;
	_vtxCountUV = vtxCountUV;
}

void Sprite::setFrames(int frameWidth, int frameHeight, int textureHeight, int textureWidth) {
	int columns = textureHeight / frameHeight; //redondea para abajo por ser INT
	int rows = textureWidth / frameWidth;
	float uvHeight = (float)frameHeight / (float)textureHeight;
	float uvWidth = (float)frameWidth / (float)textureWidth;
	_framesCant = rows * columns;
	int cont = 0;
	_frames = new Frames[_framesCant];
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < columns; i++) {
			_frames[cont].setVertexUV(uvWidth*i, uvWidth*(i + 1), 1.0f - (uvHeight*j), 1.0f - (uvHeight*(j + 1)));
			if (cont != _framesCant) {
				cont++;
			}
		}
	}
}

void Sprite::setFrame(int frame) {
	if (_frames != NULL) {
		if (frame > _framesCant && frame < 0) {
			cout << "Frame excede el máximo, colocandolo en el último";
			frame = _framesCant;
		}
		_vertexUV = _frames[frame].getVertexUV();
		_bufferUV = _renderer->genBuffer(_vertexUV, sizeof(float)* _vtxCountUV * 2);
	}
}
void Sprite::Draw() {
	if (_shouldDispose) {
		_renderer->loadMatrix();
		_renderer->setMatrix(_modelMat);
		if (_material)
		{
			_material->bind();
			_material->setMatrixProperty(_renderer->getMVP());
			_material->bindTexture(_texture->getTextureID());
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
