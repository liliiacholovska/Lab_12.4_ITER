#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.4(1)/lab12.4(1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestInsertAndIncrease)
        {
            Elem* L = NULL;
            insert(L, 10);
            insert(L, 20);

            Assert::AreEqual(10, L->info, L"First element should be 20 right after insertion.");

            increaseListValues(L, 5);

            Assert::AreEqual(15, L->info, L"First element should be 25 after increment.");
            Assert::AreEqual(25, L->link->info, L"Second element should be 15 after increment.");
        }

        TEST_METHOD(TestPrintAndIncrease)
        {
            Elem* L = NULL;
            insert(L, 1);
            insert(L, 2);

            increaseListValues(L, 5); 

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            printList(L);
            std::string output = buffer.str();
            std::cout.rdbuf(old);

            Assert::AreEqual(std::string("6 7 \n"), output, L"Output should match the list contents after increase.");
        }
	};
}