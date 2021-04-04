#include "../InvoiceLib/InvoiceClass.h"
#include "../InvoiceLib/InvoiceClass.cpp"
#include "../InvoiceLib/ItemClass.h"
#include "../InvoiceLib/ItemClass.cpp"
#include "CppUnitTest.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void vectorcompare(std::vector <Item> items1, ::vector <Item> items2);

namespace InvoiceUnitTest
{
	TEST_CLASS(InvoiceUnitTest)
	{
	public:
		
		TEST_METHOD(ConstructorNoItems)
		{
			std::string name = "Anna";
			std::string adress = "Warsaw";
			std::vector <Item> vec = {};
			Invoice inv(name, adress);
			Assert::AreEqual(name, inv.getName());
			Assert::AreEqual(adress, inv.getAdress());
			vectorcompare({},inv.getItems());
		}

		TEST_METHOD(ConstructorWithItems)
		{
			std::string name = "Anna";
			std::string adress = "Warsaw";
			Item Apple = Item("Apple");
			std::vector <Item> items = { Apple };
			Invoice inv(name, adress, items);
			Assert::AreEqual(name, inv.getName());
			Assert::AreEqual(adress, inv.getAdress());
			vectorcompare(items, inv.getItems());
		}

		TEST_METHOD(SetName)
		{
			Item Apple = Item("Apple");
			Invoice inv("Anna", "Warsaw", { Apple });
			std::string name = "Michal";
			inv.setName(name);
			Assert::AreEqual(name, inv.getName());
		}

		TEST_METHOD(SetAdress)
		{
			Item Apple = Item("Apple");
			Invoice inv("Anna", "Warsaw", { Apple });
			std::string adress = "Lublin";
			inv.setAdress(adress);
			Assert::AreEqual(adress, inv.getAdress());
		}

		TEST_METHOD(SetItems)
		{
			Item Apple = Item("Apple");
			Item Banana= Item("Banana");
			Invoice inv("Anna", "Warsaw", { Apple });
			std::vector<Item> items = { Banana };
			inv.setItems(items);
			vectorcompare(items, inv.getItems());
		}

		TEST_METHOD(AddItemOneItem)
		{
			Item Apple = Item("Apple");
			Invoice inv("Anna", "Warsaw");
			inv.addItem(Apple);
			vectorcompare({ Apple }, inv.getItems());
		}

		TEST_METHOD(AddItemMoreItems)
		{
			Item Apple = Item("Apple");
			Item Banana = Item("Banana");
			Invoice inv("Anna", "Warsaw");
			inv.addItem(Apple);
			inv.addItem(Banana);
			vectorcompare({ Apple, Banana}, inv.getItems());
		}

		TEST_METHOD(AddItemWithBaseItems)
		{
			Item Apple = Item("Apple");
			Item Banana = Item("Banana");
			Invoice inv("Anna", "Warsaw", { Apple });
			inv.addItem(Banana);
			vectorcompare({ Apple, Banana }, inv.getItems());
		}

		TEST_METHOD(RemoveItemNoItemRemoved)
		{
			Item Apple = Item("Apple");
			Item Banana = Item("Banana");
			Invoice inv("Anna", "Warsaw", { Apple });
			inv.removeItem(Banana);
			vectorcompare({Apple}, inv.getItems());
		}

		TEST_METHOD(RemoveItemOneItem)
		{
			Item Apple = Item("Apple");
			Invoice inv("Anna", "Warsaw", { Apple });
			inv.removeItem(Apple);
			vectorcompare({}, inv.getItems());
		}

		TEST_METHOD(RemoveItemMoreWithSameName1)
		{
			Item d = Item("d");
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			Invoice inv("Anna", "Warsaw", { a,b,c,d,a,c,a});
			inv.removeItem(a);
			vectorcompare({ b,c,d,c}, inv.getItems());
		}

		TEST_METHOD(RemoveItemMoreWithSameName2)
		{
			Item d = Item("d");
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			Invoice inv("Anna", "Warsaw", { a,b,c,d,a,c,a });
			inv.removeItem(c);
			vectorcompare({ a,b,d,a,a }, inv.getItems());
		}

		TEST_METHOD(PlusOpWithInvSimple)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, {a,b});
			Invoice inv2(name, adress, { a,c });
			Invoice sum = inv + inv2;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({a,b,a,c}, sum.getItems());
		}

		TEST_METHOD(PlusOpWithInvOtherName)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { a,b });
			Invoice inv2("Michal", adress, { a,c });
			Invoice sum = inv + inv2;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({a,b}, sum.getItems());
		}

		TEST_METHOD(PlusOpWithInvOtherAdress)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { a,b });
			Invoice inv2(name, "Lublin", { a,c });
			Invoice sum = inv + inv2;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({ a,b }, sum.getItems());
		}

		TEST_METHOD(MinusOpWithInvSimple)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { a,b });
			Invoice inv2(name, adress, { a,c });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ b }, sub.getItems());
		}

		TEST_METHOD(MinusOpWithInvMoreItems)
		{
			Item d = Item("d");
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { a,b,c,d,a,c,a });
			Invoice inv2(name, adress, { a,c });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ b,d }, sub.getItems());
		}

		TEST_METHOD(MinusOpWithInvNoCommonItems)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { a,b });
			Invoice inv2(name, adress, { c });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ a,b }, sub.getItems());
		}

		TEST_METHOD(MinusOpWithInvWrongAdress)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { a,b });
			Invoice inv2(name, "Lublin", { a,c });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ a,b }, sub.getItems());
		}

		TEST_METHOD(MinusOpWithInvWrongName)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { a,b });
			Invoice inv2("Michal", adress, { a,c });
			Invoice sub = inv - inv2;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ a,b }, sub.getItems());
		}

		TEST_METHOD(PlusOpWithItemSimple)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice inv(name, adress, { a,b });
			Invoice sum = inv + c;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({ a,b,c}, sum.getItems());
		}

		TEST_METHOD(MinusOpWithItemOneItemTest)
		{
			Item Apple = Item("Apple");
			Invoice inv("Anna", "Warsaw", { Apple });
			Invoice sub = inv - Apple;
			vectorcompare({}, sub.getItems());
		}

		TEST_METHOD(MinusOpWithItemSameNameTest1)
		{
			Item d = Item("d");
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			Invoice inv("Anna", "Warsaw", { a,b,c,d,a,c,a });
			Invoice sub = inv - a;
			vectorcompare({ b,c,d,c }, sub.getItems());
		}

		TEST_METHOD(MinusOpWithItemSameNameTest2)
		{
			Item d = Item("d");
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			Invoice inv("Anna", "Warsaw", { a,b,c,d,a,c,a });
			Invoice sub = inv - c;
			vectorcompare({ a,b,d,a,a }, sub.getItems());
		}

		TEST_METHOD(PlusEqOperatorWithItemSimple)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sum(name, adress, { a,b });
			sum += c;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({ a,b,c }, sum.getItems());
		}

		TEST_METHOD(MinusEqOperatorWithItemOneItem)
		{
			Item Apple = Item("Apple");
			Invoice sub("Anna", "Warsaw", { Apple });
			sub -= Apple;
			vectorcompare({}, sub.getItems());
		}

		TEST_METHOD(MinusEqOperatorWithItemSameName1)
		{
			Item d = Item("d");
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			Invoice sub("Anna", "Warsaw", { a,b,c,d,a,c,a });
			sub -= a;
			vectorcompare({ b,c,d,c }, sub.getItems());
		}

		TEST_METHOD(MinusEqOperatorWithItemSameName2)
		{
			Item d = Item("d");
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			Invoice sub("Anna", "Warsaw", { a,b,c,d,a,c,a });
			sub -= c;
			vectorcompare({ a,b,d,a,a }, sub.getItems());
		}

		TEST_METHOD(PlusEqOperatorWithInvSimple)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sum(name, adress, { a,b });
			Invoice inv(name, adress, { a,c });
			sum += inv;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({ a,b,a,c }, sum.getItems());
		}

		TEST_METHOD(PlusEqOperatorWithInvOtherName)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sum(name, adress, { a,b });
			Invoice inv("Michal", adress, { a,c });
			sum += inv;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({ a,b }, sum.getItems());
		}

		TEST_METHOD(PlusEqOperatorWithInvOtherAdress)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sum(name, adress, { a,b });
			Invoice inv(name, "Lublin", { a,c });
			sum += inv;
			Assert::AreEqual(name, sum.getName());
			Assert::AreEqual(adress, sum.getAdress());
			vectorcompare({ a,b }, sum.getItems());
		}

		TEST_METHOD(MinusEqOperatorWithInvSimple)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sub(name, adress, { a,b });
			Invoice inv(name, adress, { a,c });
			sub -= inv;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ b }, sub.getItems());
		}

		TEST_METHOD(MinusEqOperatorWithInvMoreItems)
		{
			Item d = Item("d");
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sub(name, adress, { a,b,c,d,a,c,a });
			Invoice inv(name, adress, { a,c });
			sub -= inv;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ b,d }, sub.getItems());
		}

		TEST_METHOD(MinusEqOperatorWithInvNoCommonItems)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sub(name, adress, { a,b });
			Invoice inv(name, adress, { c });
			sub -= inv;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ a,b }, sub.getItems());
		}

		TEST_METHOD(MinusEqOperatorWithInvWrongAdress)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sub(name, adress, { a,b });
			Invoice inv(name, "Lublin", { a,c });
			sub -= inv;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ a,b }, sub.getItems());
		}

		TEST_METHOD(MinusEqOperatorWithInvWrongName)
		{
			Item c = Item("c");
			Item b = Item("b");
			Item a = Item("a");
			std::string const name = "Anna";
			std::string const adress = "Warsaw";
			Invoice sub(name, adress, { a,b });
			Invoice inv("Michal", adress, { a,c });
			sub -= inv;
			Assert::AreEqual(name, sub.getName());
			Assert::AreEqual(adress, sub.getAdress());
			vectorcompare({ a,b }, sub.getItems());
		}
	};
}

void vectorcompare(std::vector <Item> items1, ::vector <Item> items2)
{
	Assert::AreEqual(items1.size(), items2.size());
	if (items1.size() == items2.size())
	{
		for (int i = 0; i < items1.size(); i++)
		{
			Assert::AreEqual(items1[i].getName(), items2[i].getName());
		}
	}
}