#include "MeshFactoryD3D11.hpp"
#include "MeshD3D11.hpp"

std::tr1::shared_ptr<Mesh> MeshFactoryD3D11::CreateMesh()
{
	return std::tr1::shared_ptr<Mesh>(new MeshD3D11());
}