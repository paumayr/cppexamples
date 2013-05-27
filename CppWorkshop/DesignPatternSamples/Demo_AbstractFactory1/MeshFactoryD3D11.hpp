#pragma once

#include <memory>

#include "MeshFactory.hpp"
#include "MeshD3D11.hpp"

class MeshFactoryD3D11 : public MeshFactory
{
public:
	virtual std::tr1::shared_ptr<Mesh> CreateMesh();
};