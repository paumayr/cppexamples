#include "stdafx.h"
#include <memory>
#include <vector>

using namespace std;

TEST_CLASS(TestSharedFromThis)
{
public:

	// class that is only allowed to be instantiated on the heap
	// via a shared ptr.
	class HeapObject : public enable_shared_from_this<HeapObject>
	{

	public:

		// Note: keep the assignment operator, as assigning from heap object to heap object is ok.

		// public method to create a new instance on the heap.
		static shared_ptr<HeapObject> create()
		{
			return shared_ptr<HeapObject>(new HeapObject());
		}

		// example member method using shared_from_this() to retrieve shared pointer.
		void add_to_collection(vector<shared_ptr<HeapObject>> &v)
		{
			// get a shared pointer to this object using "shared_from_this()"
			auto shared_ptr_to_this = shared_from_this();
			v.push_back(shared_ptr_to_this);
		}

	private:

		// hide the public constructor so that we can only construct through create()
		HeapObject()
		{
		}

		// hide the copy constructor as well!
		HeapObject(const HeapObject& other);
	};

	TEST_METHOD(TestSharedFromThisMain)
	{
		auto instance = HeapObject::create();

		vector<shared_ptr<HeapObject>> asdf;
		instance->add_to_collection(asdf);

		// cannot create a copy on the stack
		// does not compile: auto copy = *instance;

		// can assign objects on the heap
		auto instance2 = HeapObject::create();
		*instance2 = *instance;

		// call example method.
		vector<shared_ptr<HeapObject>> v;
		instance->add_to_collection(v);
	}
};