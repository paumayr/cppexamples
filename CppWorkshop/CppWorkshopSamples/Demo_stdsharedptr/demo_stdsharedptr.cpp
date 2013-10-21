#include <memory>
#include <vector>


class vector3
{
public:
	float x, y;
};

std::shared_ptr<vector3> createVector()
{
	std::shared_ptr<vector3> v(new vector3());
	v->x = 0.0f;
	v->y = 0.0f;
	return v;
}

int main(int argc, char **argv)
{
	std::shared_ptr<vector3> v;

	std::shared_ptr<vector3> ptrVec3(new vector3());
	std::shared_ptr<vector3> ptrVec4 = ptrVec3;

	std::shared_ptr<vector3> x = createVector();
}