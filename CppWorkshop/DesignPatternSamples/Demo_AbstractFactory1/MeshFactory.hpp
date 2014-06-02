#pragma once


#include <memory>
class Mesh;

class MeshFactory
{
public:
	virtual std::shared_ptr<Mesh> CreateMesh() = 0;
};