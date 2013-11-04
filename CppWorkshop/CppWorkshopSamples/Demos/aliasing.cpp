#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace timecockpit
{
	namespace signaltracker
	{
		namespace data
		{
			template<typename T>
			class vector
			{
			public:
				T x, y, z;
			};
		}
	}
}

namespace Demos
{
	TEST_CLASS(Aliasing)
	{
		TEST_METHOD(TestUsingNamespace)
		{
			timecockpit::signaltracker::data::vector<float> v0;
			namespace tsd = timecockpit::signaltracker::data;
			tsd::vector<float> v1;
			v0.z = 12.0;
			v1.y = 11.0;

			{
				using namespace timecockpit::signaltracker::data;
				vector<float> v;
				v.x = 10.0;
			}

			{
				using namespace std;
				vector<int> asdf;
			}

			{
				using namespace std;
				using namespace tsd; // merge namespace alias with global namespace

				// vector<double> d; arg... vector is ambiguous
				tsd::vector<int> v;
				std::vector<tsd::vector<int>> container;
				container.push_back(v);
			}
		}

		// new syntax, but unspecified template args. can only be used on global or class scope.
		template <typename T> using my_vec = typename timecockpit::signaltracker::data::vector<T>;


		TEST_METHOD(TypeAlias)
		{
			// old syntax
			typedef timecockpit::signaltracker::data::vector<float> old_my_vec_float;

			// new syntax
			using my_vec_float = timecockpit::signaltracker::data::vector<float>;
			my_vec_float v;
			v.x = 10.0;

			// use template <typename T> class-level declaration.
			my_vec<float> v1;
			v1.y = 20.0;
		};
	};

}