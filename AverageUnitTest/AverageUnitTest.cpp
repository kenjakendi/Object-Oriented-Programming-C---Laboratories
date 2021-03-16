#include "CppUnitTest.h"
#include "..\AverageLib\Average.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AverageUnitTest
{
	TEST_CLASS(AverageUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::array<std::array<int, maxColumns>, maxRows> array1 = { { {{1440,2440,31}},{{7389,5555555,17}},{{3578,4920,1203}} } };
			double prog_average = average(array1, 3, 3);
			Assert::AreEqual(prog_average, 3646.0);
		}

		TEST_METHOD(TestMethod2)
		{
			std::array<std::array<int, maxColumns>, maxRows> array2 = {};
			double prog_average = average(array2, 3, 3);
			Assert::AreEqual(prog_average, 0.0);
		}

		TEST_METHOD(TestMethod3)
		{
			std::array<std::array<int, maxColumns>, maxRows> array3 = { { {{1440,2450,31}},{{7389,5,17}},{{578,490,1203}} } };
			double prog_average = average(array3, 3, 3);
			Assert::AreEqual(prog_average, 0.0);
		}
	};
}
