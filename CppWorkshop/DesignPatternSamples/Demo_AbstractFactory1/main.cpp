
#include "MeshFactory.hpp"
#include "MeshFactoryD3D11.hpp"
#include "MeshFactoryOGL.hpp"

#include <string>

struct unknown_mesh_factory : public std::exception
{
	unknown_mesh_factory(const std::string &name) : std::exception(name.c_str()) {}
};

std::shared_ptr<MeshFactory> createMeshFactory(std::string renderer)
{
	if (renderer == "OGL")
	{
		return std::shared_ptr<MeshFactory>(new MeshFactoryOGL());
	}
	else if (renderer == "D3D11")
	{
		return std::shared_ptr<MeshFactory>(new MeshFactoryD3D11());
	}

	throw unknown_mesh_factory(renderer);
}


int main(int argc, char ** argv)
{
	std::string renderer = "OGL";
	
	std::shared_ptr<MeshFactory> meshFactory = createMeshFactory(renderer);

	std::shared_ptr<Mesh> mesh = std::shared_ptr<Mesh>(meshFactory->CreateMesh());
}

