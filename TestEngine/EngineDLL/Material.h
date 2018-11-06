#pragma once
#include "Exports.h"
#include "Texture.h"
#include "glm\glm.hpp"

using namespace std;
class ENGINEDLL_API Material
{
private:
	unsigned int _programID;
	unsigned int _matrixID;
	Material();
	unsigned int loadShader(const char * vertex_file_path, const char * fragment_file_path);
public:
	static Material * loadMaterial(const char * vertex_file_path, const char * fragment_file_path);
	void setMatrixProperty(glm::mat4& mat);

	void bind();
	void bindTexture(unsigned int textureID);
	~Material();
};

