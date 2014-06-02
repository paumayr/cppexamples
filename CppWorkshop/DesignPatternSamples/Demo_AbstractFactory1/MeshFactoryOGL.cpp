#include "MeshFactoryOGL.hpp"
#include "MeshOGL.hpp"

std::shared_ptr<Mesh> MeshFactoryOGL::CreateMesh()
{
	return std::shared_ptr<Mesh>(new MeshOGL());
}