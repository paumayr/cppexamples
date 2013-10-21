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
	std::shared_ptr<int> b;
	try
	{
		std::shared_ptr<int> pointerToInt = std::shared_ptr<int>(new int(100));
		b = pointerToInt;
		throw my_exception();
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