#include "MeshFactoryOGL.hpp"
#include "MeshOGL.hpp"

std::tr1::shared_ptr<Mesh> MeshFactoryOGL::CreateMesh()
{
	return std::tr1::shared_ptr<Mesh>(new MeshOGL());
}