
#include <memory>
#include <iostream>
#include <vector>
#include <array>

int main(int argc, char **argv)
{
  using namespace std;
  weak_ptr<int> wp;

  {
	 shared_ptr<int> sp1 = shared_ptr<int>(new int(10));
	
    cout << "usecount: " << sp1.use_count() << endl;
    {
	  shared_ptr<int> sp2 = sp1;
      wp = sp1;
      {
        // if we need a shared pointer from a weak pointer, call lock
		 shared_ptr<int> sp3 = wp.lock();
        // ... be sure to check before using.
        if (sp3 != nullptr)
        {
          cout << "sp3 valid, value is " << *sp3 << endl;
        }

        cout << "usecount: " << sp3.use_count() << endl;
      }
      cout << "usecount: " << sp2.use_count() << endl;
    }
    cout << "usecount: " << sp1.use_count() << endl;
  }

  shared_ptr<int> sp4 = wp.lock();

  // weak pointer should have expired here.
  if (wp.expired())
  {
  	cout << "expired!" << endl;
  }
  else
  {
  	cout << "still valid!" << endl;
  }

  return 0;
}