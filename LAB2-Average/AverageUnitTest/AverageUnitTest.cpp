#include "CppUnitTest.h"
#include "..\AverageLib\Average.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AverageUnitTest
{
	TEST_CLASS(AverageUnitTest)
	{
	public:
		
		TEST_METHOD(TestArraySimple)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = { { {{1440,2440,31}},{{7389,5555555,17}},{{3578,4920,1203}} } };
			double prog_average = average(array, 3, 3);
			double real_average = 3646.0;
			Assert::AreEqual(prog_average, real_average);
		}

		TEST_METHOD(TestArrayEmpty)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = {};
			double prog_average = average(array, 3, 3);
			Assert::AreEqual(prog_average, 0.0);
		}

		TEST_METHOD(TestArrayIneligibleElements)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = { { {{1440,2450,31}},{{7389,5,17}},{{578,490,1203}} } };
			double prog_average = average(array, 3, 3);
			Assert::AreEqual(prog_average, 0.0);
		}

		TEST_METHOD(TestArrayDifferentSize)
		{
			std::array<std::array<int, maxColumns>, maxRows> array = { { {{1,0,31}},{{89,5,17}},{{5,49,1}},{{5,10,171}} } };
			double prog_average = average(array, 4, 3);
			double real_average = 69.0;
			Assert::AreEqual(prog_average, real_average);
		}

		TEST_METHOD(TestCountInnerSumEven)
		{
			std::string str_element = "107529";
			int prog_innersum = count_inner_sum(str_element);
			int real_innersum = 10;
			Assert::AreEqual(prog_innersum, real_innersum);
		}

		TEST_METHOD(TestCountInnerSumDigit)
		{
			std::string str_element = "9";
			int prog_innersum = count_inner_sum(str_element);
			int real_innersum = 0;
			Assert::AreEqual(prog_innersum, real_innersum);
		}

		TEST_METHOD(TestCountInnerSumOdd)
		{
			std::string str_element = "9103";
			int prog_innersum = count_inner_sum(str_element);
			int real_innersum = 9;
			Assert::AreEqual(prog_innersum, real_innersum);
		}
	};
}
