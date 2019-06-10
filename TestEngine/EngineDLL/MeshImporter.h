#pragma once
#include "Exports.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"	
#include "assimp/postprocess.h"
#include "Mesh.h"
#include <iostream>
using namespace Assimp;
class ENGINEDLL_API MeshImporter
{
public:
	MeshImporter();
	bool static importModel(const char * path, float **_vertex, int & _vtxCount,unsigned int** _index, int & _indexCount);
	~MeshImporter();
};

