#include "../InvoiceLib/InvoiceClass.h"
#include "../InvoiceLib/InvoiceClass.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InvoiceUnitTest
{
	TEST_CLASS(InvoiceUnitTest)
	{
	public:
		
		TEST_METHOD(ConstructorNoItemsParameter)
		{
			std::string name = "Anna";
			std::string adress = "Warsaw";
			Invoice inv(name, adress);
			Assert::AreEqual(name, inv.getName());
			Assert::AreEqual(adress, inv.getAdress());
			//Assert::AreEqual({}, inv.getItems());
		}

		TEST_METHOD(ConstructorWithItemsParameter)
		{
			std::string name = "Anna";
			std::string adress = "Warsaw";
			std::vector <std::string> items = { "Apple" };
			Invoice inv(name, adress);
			Assert::AreEqual(name, inv.getName());
			Assert::AreEqual(adress, inv.getAdress());
			//Assert::AreEqual(items, inv.getItems());
		}
	};
}