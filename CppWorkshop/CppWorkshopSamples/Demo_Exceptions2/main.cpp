#include <iostream>
#include <memory>

struct my_exception : public std::exception 
{
public:
	my_exception() : std::exception("my exception") {};
};

struct my_other_exception : public std::exception 
{
	my_other_exception() : std::exception("my other exception") {};
};

int main(int argc, char **argv)
{
	std::tr1::shared_ptr<int> b;
	try
	{
		std::tr1::shared_ptr<int> pointerToInt = std::tr1::shared_ptr<int>(new int(100));
		b = pointerToInt;
		std::cout << "this line will never be reached" << std::endl;
	}
	catch(my_exception &ex)
	{
		std::cout << "caught " << ex.what() << std::endl;
	}
	catch(my_other_exception &ex)
	{
		std::cout << "caught " << ex.what() << std::endl;
	//	delete pointerToInt;
	}
	catch(std::exception &ex)
	{
		std::cout << "caught std::exception : " << ex.what() << std::endl;
	}

	std::cin.get();
	return 0;
}