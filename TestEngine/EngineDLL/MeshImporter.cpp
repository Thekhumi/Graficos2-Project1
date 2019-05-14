#include "MeshImporter.h"



MeshImporter::MeshImporter()
{
}

bool MeshImporter::importModel(const char * path, float*_vertex, int* _index) {
	// Create an instance of the Importer class
	Importer importer;
	// And have it read the given file with some example postprocessing
	// Usually - if speed is not the most important aspect for you - you'll 
	// propably to request more postprocessing than we do in this example.
	const aiScene* scene = importer.ReadFile(path,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);

	// If the import failed, report it
	if (!scene){
		return false;
	}
	return true;
}


MeshImporter::~MeshImporter()
{
}
