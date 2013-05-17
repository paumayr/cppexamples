#include <memory>

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
	typedef std::shared_ptr<vector3> vector3ptr;

	vector3* oldptr;
	vector3ptr v;

	vector3ptr ptrVec3(new vector3());
	vector3ptr ptrVec4 = ptrVec3;

	vector3ptr x = createVector();
}