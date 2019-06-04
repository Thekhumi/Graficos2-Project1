#include "MeshImporter.h"

using namespace std;

MeshImporter::MeshImporter()
{
}

bool MeshImporter::importModel(const char * path, float *_vertex, unsigned int * _index) {
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
		cout << "ERROR: NO SE PUDO IMPORTAR ESCENA" << endl;
		return false;
	}
	if (scene->HasMeshes()) {
		unsigned int cantIndex = scene->mMeshes[0]->mNumFaces * 3;
		unsigned int cantVertex = scene->mMeshes[0]->mNumVertices;
		float * vertexData = new float[cantVertex];
		float * pvertex = vertexData;
		for (int i = 0; i < cantVertex; i++) {
			*pvertex = scene->mMeshes[0]->mVertices[i].x;
			 pvertex++;
			 *pvertex = scene->mMeshes[0]->mVertices[i].y;
			 pvertex++;
			 *pvertex = scene->mMeshes[0]->mVertices[i].z;
			 pvertex++;

		}
		//cout << scene->mMeshes[0]->mTextureCoords[0][0].x << endl;
		//cout << scene->mMeshes[0]->mTextureCoords[0][0].y << endl;


		_index = scene->mMeshes[0]->mFaces->mIndices;
	}
	return true;
}


MeshImporter::~MeshImporter()
{
}
