#include "../InvoiceLib/InvoiceClass.h"
#include "../InvoiceLib/InvoiceClass.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InvoiceUnitTest
{
	TEST_CLASS(InvoiceUnitTest)
	{
	public:
		
		TEST_METHOD(ConstructorNoItemsParameters)
		{
			std::string name = "Anna";
			std::string adress = "Warsaw";
			Invoice inv(name, adress);
			Assert::AreEqual(name, inv.getName());
			Assert::AreEqual(adress, inv.getAdress());
		}
	};
}
