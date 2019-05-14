#pragma once
#include "Exports.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"	
#include "assimp/postprocess.h"
using namespace Assimp;
class ENGINEDLL_API MeshImporter
{
public:
	MeshImporter();
	bool static importModel(const char * path, float*_vertex, int* _index);
	~MeshImporter();
};

