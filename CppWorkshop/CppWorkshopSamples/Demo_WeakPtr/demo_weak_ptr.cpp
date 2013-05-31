
#include <memory>
#include <iostream>

int main(int argc, char **argv)
{
  using namespace std;
  weak_ptr<int> wp;
  
  {
    auto sp1 = make_shared<int>(10);
    cout << "usecount: " << sp1.use_count() << endl;
    {
      auto sp2 = sp1;
      wp = sp1;
      {
        // if we need a shared pointer from a weak pointer, call lock
        auto sp3 = wp.lock();
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