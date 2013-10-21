
class SimpleResource
{
	int *heapmemory;
public:
	SimpleResource()
		: heapmemory(new int[1024*1024])
	{
	}

	~SimpleResource()
	{
		delete[] heapmemory;
	}
};

int main(int argc, char **argv)
{
	{
		SimpleResource r1;
		{
			SimpleResource r2;
		}
	}
}