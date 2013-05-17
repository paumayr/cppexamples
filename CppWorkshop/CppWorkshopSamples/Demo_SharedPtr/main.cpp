

class SharedPointer
{
	double * pointer;
	int * counter;
public:
	SharedPointer()
		: pointer(nullptr), counter(nullptr)
	{
	}

	SharedPointer(double *pointer)
		: pointer(pointer),
		counter(new int(1))
	{
	}

	~SharedPointer()
	{
		decrementReferenceCount();
	}

	void decrementReferenceCount()
	{
		(*counter)--;
		if (*counter == 0)
		{

			if (pointer != 0)
			{
				delete pointer;
				pointer = 0;
			}

			delete counter;
		}
	}

	SharedPointer(const SharedPointer &other)
	{
		pointer = other.pointer;
		counter = other.counter;
		(*counter)++;
	}

	SharedPointer& operator=(const SharedPointer &other)
	{
		if (counter != nullptr && pointer != nullptr)
		{
			decrementReferenceCount();
		}

		counter = other.counter;
		pointer = other.pointer;

		(*counter)++;

		return *this;
	}

	double * get()
	{
		return pointer;
	}
};

int main(int argc, char **argv)
{
	{
		SharedPointer outside;
		{
			SharedPointer sp(new double(10.0));

			SharedPointer sp2 = sp;
			outside = sp2;
		}

	}

	return 0;
}
