#include "../InvoiceLib/InvoiceClass.h"
#include "../InvoiceLib/InvoiceClass.cpp"
#include "CppUnitTest.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void vectorcompare(std::vector <std::string> items1, ::vector <std::string> items2);

namespace InvoiceUnitTest
{
	TEST_CLASS(InvoiceUnitTest)
	{
	public:
		
		TEST_METHOD(ConstructorNoItemsParameter)
		{
			std::string name = "Anna";
			std::string adress = "Warsaw";
			std::vector <std::string> vec = {};
			Invoice inv(name, adress);
			Assert::AreEqual(name, inv.getName());
			Assert::AreEqual(adress, inv.getAdress());
			vectorcompare({},inv.getItems());
		}

		TEST_METHOD(ConstructorWithItemsParameter)
		{
			std::string name = "Anna";
			std::string adress = "Warsaw";
			std::vector <std::string> items = { "Apple" };
			Invoice inv(name, adress, items);
			Assert::AreEqual(name, inv.getName());
			Assert::AreEqual(adress, inv.getAdress());
			vectorcompare(items, inv.getItems());
		}

		TEST_METHOD(InvoiceSetNameTest)
		{
			Invoice inv("Anna", "Warsaw", { "Apple" });
			std::string name = "Michal";
			inv.setName(name);
			Assert::AreEqual(name, inv.getName());
		}

		TEST_METHOD(InvoiceSetAdressTest)
		{
			Invoice inv("Anna", "Warsaw", { "Apple" });
			std::string adress = "Lublin";
			inv.setAdress(adress);
			Assert::AreEqual(adress, inv.getAdress());
		}

		TEST_METHOD(InvoiceSetItemsTest)
		{
			Invoice inv("Anna", "Warsaw", { "Apple" });
			std::vector<std::string> items = { "Banana" };
			inv.setItems(items);
			vectorcompare(items, inv.getItems());
		}

		TEST_METHOD(AddOneItemTest)
		{
			Invoice inv("Anna", "Warsaw");
			inv.addItem("Apple");
			vectorcompare({ "Apple" }, inv.getItems());
		}

		TEST_METHOD(AddMoreItemsTest)
		{
			Invoice inv("Anna", "Warsaw");
			inv.addItem("Apple");
			inv.addItem("Banana");
			vectorcompare({ "Apple","Banana"}, inv.getItems());
		}

		TEST_METHOD(AddItemWithBaseItemsTest)
		{
			Invoice inv("Anna", "Warsaw", { "Apple" });
			inv.addItem("Banana");
			vectorcompare({ "Apple","Banana" }, inv.getItems());
		}

		TEST_METHOD(RemoveNoItemTest)
		{
			Invoice inv("Anna", "Warsaw", { "Apple" });
			inv.removeItem("Banana");
			vectorcompare({"Apple"}, inv.getItems());
		}

		TEST_METHOD(RemoveOneItemTest)
		{
			Invoice inv("Anna", "Warsaw", { "Apple" });
			inv.removeItem("Apple");
			vectorcompare({}, inv.getItems());
		}

		TEST_METHOD(RemoveItemsWithSameName1Test)
		{
			Invoice inv("Anna", "Warsaw", { "a","b","c","d","a","c","a"});
			inv.removeItem("a");
			vectorcompare({ "b","c","d","c"}, inv.getItems());
		}

		TEST_METHOD(RemoveItemsWithSameName2Test)
		{
			Invoice inv("Anna", "Warsaw", { "a","b","c","d","a","c","a" });
			inv.removeItem("c");
			vectorcompare({ "a","b","d","a","a" }, inv.getItems());
		}

		TEST_METHOD(PlusOperatorWithInvSimple)
		{
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, {"a","b"});
			Invoice inv2(name, adress, { "a","c" });
			Invoice sum = inv + inv2;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({"a","b","a","c"}, sum.getItems());
		}

		TEST_METHOD(PlusOperatorWithInvOtherName)
		{
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { "a","b" });
			Invoice inv2("Michal", adress, { "a","c" });
			Invoice sum = inv + inv2;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({"a","b"}, sum.getItems());
		}

		TEST_METHOD(PlusOperatorWithInvOtherAdress)
		{
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { "a","b" });
			Invoice inv2(name, "Lublin", { "a","c" });
			Invoice sum = inv + inv2;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({ "a","b" }, sum.getItems());
		}

		TEST_METHOD(MinusOperatorWithInvSimple)
		{
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { "a","b" });
			Invoice inv2(name, adress, { "a","c" });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ "b" }, sub.getItems());
		}

		TEST_METHOD(MinusOperatorWithInvMoreItems)
		{
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { "a","b","c","d","a","c","a" });
			Invoice inv2(name, adress, { "a","c" });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ "b","d" }, sub.getItems());
		}

		TEST_METHOD(MinusOperatorWithInvNoCommonItems)
		{
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { "a","b" });
			Invoice inv2(name, adress, { "c" });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ "a","b" }, sub.getItems());
		}

		TEST_METHOD(MinusOperatorWithInvWrongAdress)
		{
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { "a","b" });
			Invoice inv2(name, "Lublin", { "a","c" });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ "a","b" }, sub.getItems());
		}

		TEST_METHOD(MinusOperatorWithInvWrongName)
		{
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { "a","b" });
			Invoice inv2("Michal", adress, { "a","c" });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ "a","b" }, sub.getItems());
		}
	};
}

void vectorcompare(std::vector <std::string> items1, ::vector <std::string> items2)
{
	Assert::AreEqual(items1.size(), items2.size());
	if (items1.size() == items2.size())
	{
		for (int i = 0; i < items1.size(); i++)
		{
			Assert::AreEqual(items1[i], items2[i]);
		}
	}
}