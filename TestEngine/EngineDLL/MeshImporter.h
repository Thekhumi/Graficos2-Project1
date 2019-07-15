#pragma once
#include "Exports.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"	
#include "assimp/postprocess.h"
#include "Mesh.h"
#include "Nodo.h"
#include <iostream>
class ENGINEDLL_API Nodo;
class ENGINEDLL_API MeshImporter
{
public:
	MeshImporter();
	static bool importModelOld(const char * path, float **_vertex, int & _vtxCount,
		unsigned int** _index, int & _indexCount, float ** _vertexUV, int & _vertexUVCount);
	static void importModel(Nodo ** baseNode, const char * path, Rendering * renderer);
	~MeshImporter();
};

