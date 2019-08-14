#pragma once
#include "Component.h"
#include "Exports.h"
#include "MeshImporter.h"
#include "TextureImporter.h"
class ENGINEDLL_API CompMesh :
	public Component
{
public:
	struct Fbox {
		float minX;
		float minY;
		float minZ;
		float maxX;
		float maxY;
		float maxZ;
	};
private:
	bool _shouldDispose;
	Material* _material;
	
	Rendering * _renderer;

	glm::mat4 * _modelMat;

	float *_vertexUV;
	float *_vertex;
	int _vtxCount;
	int _vertexUVCount;
	int _indexCount;
	unsigned int * _index;
	unsigned int _bufferID = -1;
	unsigned int _bufferUV = -1;
	unsigned int _bufferIDIndex = -1;
	Texture * _texture;
	Fbox _frustrumBox;
	bool _hasFrustrum;

public:
	CompMesh();
	void draw() override;
	void update() override {};

	//mesh
	void init(Rendering * renderer);
	void setVertices();
	void loadModel(const char * path);
	void loadTexture(const char * imagepath, bool hasAlphaC);
	float * getVertex() { return _vertex; };
	void setVertex(float * vertex) { _vertex = vertex; };
	void setVertexCant(int vtxCount) { _vtxCount = vtxCount; };
	void setVertexUV(float * vertexUV) { _vertexUV = vertexUV; };
	void setvertexUVcant(int vtxUVcount) { _vertexUVCount = vtxUVcount; };
	unsigned int * getIndex() { return _index; };
	void setIndex(unsigned int * index) { _index = index; };
	void setIndexCount(int indexCount) { _indexCount = indexCount; };
	void setModelMat(glm::mat4 * modelMat) { _modelMat = modelMat; };
	void setMaterial(Material * mat) { _material = mat; };
	//Frustrum
	void FboxSetUp();
	bool frustrumBoxCheck();
	Fbox getFbox() { return _frustrumBox; };
	void setFbox(Fbox fBox) { _frustrumBox = fBox; }
	~CompMesh();
};

