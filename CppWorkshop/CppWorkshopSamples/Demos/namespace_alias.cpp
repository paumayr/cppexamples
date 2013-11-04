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
	TEST_CLASS(NamespaceAlias)
	{
		TEST_METHOD(TestUsingNamespace)
		{
			timecockpit::signaltracker::data::vector<float> v0;
			namespace tsd = timecockpit::signaltracker::data;
			tsd::vector<float> v0;

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
				using namespace tsd;
				// vector<double> d; arg... vector is ambiguous
				tsd::vector<int> v;
				std::vector<tsd::vector<int>> container;
				container.push_back(v);
			}
		}
	};
}