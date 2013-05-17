
class Squares
{
public:
	Squares(){
		for(int i = 0; i < 1024; i++)
		{
			chunk[i] = i * i; 
		}
	}
	// 1 kb
	int chunk[1024];
};

int sumsquares(const Squares &squares, int first, int last)
{
	// cannot produce error due to sneaky bug, because squares is not const, will not compile
	// ERROR, lvalue const.... squares.chunk[10] = 101; 
	int ret = 0;
	for (int i = first; i <= last; i++) {
		ret += squares.chunk[i];
	}

	return ret;
}


class SomeClass
{
	int member;
	mutable int mutableMember;
public:
	SomeClass() : member(0), mutableMember(0) {};

	int getMember()
	{
		return member;
	}

	int getMember() const
	{
		// ERROR, cannot modify any non-mutable members
		// member++;
		// ok, member is mutable
		mutableMember++;
		return member;
	}
};

int main(int argc, char **argv)
{
	const int constantInteger = 10;
	// ERROR, expression must be a modifiable lvalue.
	// constantInteger = 5;

	int u = 20;
	int v = 30;

	const int *pointerTo = &u;
	// ERROR pointerTo points to a constant integer
	// *pointerTo = 5;
	// ok, change pointer to point to v instead of u
	pointerTo = &v;

	int * const pointerTov = &v;
	// ok, the pointer is const, not the value pointed to
	*pointerTov = 20;
	// ERROR, pointer is constant, cannot be changed to point to u.
	// pointerTov = &u;


	SomeClass c;
	c.getMember();

	const SomeClass& refc = c;
	refc.getMember();
	return 0;
}