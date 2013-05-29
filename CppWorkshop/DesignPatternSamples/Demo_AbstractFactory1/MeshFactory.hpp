#pragma once


#include <memory>
class Mesh;

class MeshFactory
{
public:
	virtual std::tr1::shared_ptr<Mesh> CreateMesh() = 0;
};