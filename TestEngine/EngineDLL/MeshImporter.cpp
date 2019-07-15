#include "MeshImporter.h"

using namespace std;
using namespace Assimp;

MeshImporter::MeshImporter()
{
}

bool MeshImporter::importModelOld(const char * path, float **_vertex, int & _vtxCount, unsigned int** _index, int & _indexCount, float ** _vertexUV, int & _vertexUVCount) {

	Importer importer;

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
		// Numbers of Index/Vertex
		unsigned int cantIndex = scene->mMeshes[0]->mNumFaces * 3;
		unsigned int cantVertex = scene->mMeshes[0]->mNumVertices;
		unsigned int cantUV = cantVertex;
		//Vertex
		float * vertexData = new float[cantVertex * 3];
		int numVtx = 0;
		for (int i = 0; i < cantVertex; i++) {
			vertexData[numVtx++] = scene->mMeshes[0]->mVertices[i].x;
			//cout << vertexData[numVtx - 1] << ", ";
			vertexData[numVtx++] = scene->mMeshes[0]->mVertices[i].y;
			//cout << vertexData[numVtx - 1] << ", ";
			vertexData[numVtx++] = scene->mMeshes[0]->mVertices[i].z;
			//cout << vertexData[numVtx - 1] << ".";
			//cout << endl;
		}
		//Index
		unsigned int * indexData = new unsigned int[cantIndex];
		int numIndex = 0;
		for (int i = 0; i < scene->mMeshes[0]->mNumFaces; i++){
			indexData[numIndex++] = scene->mMeshes[0]->mFaces[i].mIndices[0];
			//cout << indexData[numIndex - 1] << ", ";
			indexData[numIndex++] = scene->mMeshes[0]->mFaces[i].mIndices[1];
			//cout << indexData[numIndex - 1] << ", ";
			indexData[numIndex++] = scene->mMeshes[0]->mFaces[i].mIndices[2];
			//cout << indexData[numIndex - 1] << ".";
			//cout << endl;
		}
		//UV
		float * UVData = new float[cantUV * 2];
		int numUV = 0;
		for (int i = 0; i < cantUV; i++){
			UVData[numUV++] = scene->mMeshes[0]->mTextureCoords[0][i].x;
			cout << UVData[numUV - 1] << ", ";
			UVData[numUV++] = scene->mMeshes[0]->mTextureCoords[0][i].y;
			cout << UVData[numUV - 1] << ".";
			cout << endl;
		}
		//copying values to originals
		//vertex
		*_vertex = vertexData;
		_vtxCount = cantVertex;
		//UV
		*_vertexUV = UVData;
		_vertexUVCount = cantUV;
		//INDEX
		_indexCount = cantIndex;
		*_index = indexData;
	}
	return true;
}

void MeshImporter::importModel(Nodo ** baseNode, const char * path, Rendering * renderer) {
	Importer importer;
	const char * name = "Mesh";

	const aiScene* scene = importer.ReadFile(path,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);

	// If the import failed, report it
	if (!scene) {
		cout << "ERROR: NO SE PUDO IMPORTAR ESCENA" << endl;
		return;
	}
	int numMeshes = scene->mNumMeshes;
	int contMeshes = 0;
	Nodo * nodo = NULL;
	Nodo * firstNodo = NULL;
	if (scene->HasMeshes()) {
		do{
			nodo = new Nodo(name + contMeshes, renderer);
			if (firstNodo == NULL) {
				firstNodo = nodo;
			}
			unsigned int cantIndex = scene->mMeshes[contMeshes]->mNumFaces * 3;
			unsigned int cantVertex = scene->mMeshes[contMeshes]->mNumVertices;
			unsigned int cantUV = cantVertex;
			//Vertex
			float * vertexData = new float[cantVertex * 3];
			int numVtx = 0;
			for (int i = 0; i < cantVertex; i++) {
				vertexData[numVtx++] = scene->mMeshes[contMeshes]->mVertices[i].x;
				vertexData[numVtx++] = scene->mMeshes[contMeshes]->mVertices[i].y;
				vertexData[numVtx++] = scene->mMeshes[contMeshes]->mVertices[i].z;
			}
			unsigned int * indexData = new unsigned int[cantIndex];
			int numIndex = 0;
			for (int i = 0; i < scene->mMeshes[contMeshes]->mNumFaces; i++) {
				indexData[numIndex++] = scene->mMeshes[contMeshes]->mFaces[i].mIndices[0];
				indexData[numIndex++] = scene->mMeshes[contMeshes]->mFaces[i].mIndices[1];
				indexData[numIndex++] = scene->mMeshes[contMeshes]->mFaces[i].mIndices[2];
			}
			float * UVData = new float[cantUV * 2];
			int numUV = 0;
			for (int i = 0; i < cantUV; i++) {
				UVData[numUV++] = scene->mMeshes[0]->mTextureCoords[0][i].x;
				cout << UVData[numUV - 1] << ", ";
				UVData[numUV++] = scene->mMeshes[0]->mTextureCoords[0][i].y;
				cout << UVData[numUV - 1] << ".";
				cout << endl;
			}
			//copying values to originals
			CompMesh * mesh = new CompMesh();


			//VERTEX
			mesh->setVertex(vertexData);
			mesh->setVertexCant(cantVertex);
			//UV
			mesh->setVertexUV(UVData);
			mesh->setvertexUVcant(cantUV);
			//INDEX
			mesh->setIndex(indexData);
			mesh->setIndexCount(cantIndex);

			nodo->attachComponent(CMesh, mesh);
			if (contMeshes != 0) {
				firstNodo->AddChild(nodo);
			}
			contMeshes++;
		} while (contMeshes < numMeshes);
	}
	
	*baseNode = firstNodo;
}

MeshImporter::~MeshImporter()
{
}
