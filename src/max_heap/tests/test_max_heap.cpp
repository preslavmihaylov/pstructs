#include <cppunit/TestResultCollector.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <pstructs/heap.h>
#include <iostream>

class MaxHeapTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(MaxHeapTest);

CPPUNIT_TEST(test_pushOneElement);
CPPUNIT_TEST(test_pushFourElements);
CPPUNIT_TEST(test_pushOnePopOne);
CPPUNIT_TEST(test_pushTwoPopOne);
CPPUNIT_TEST(test_pushFourPopFour);
CPPUNIT_TEST_EXCEPTION(test_popEmpty, std::invalid_argument);

CPPUNIT_TEST_SUITE_END();

std::shared_ptr<pstructs::max_heap<int>> heap;

public:
    void setUp()
    {
        heap = std::make_shared<pstructs::max_heap<int> >();
    }

    void test_pushOneElement()
    {
        heap->push(5);
        CPPUNIT_ASSERT(heap->peek() == 5);
        CPPUNIT_ASSERT(heap->getSize() == 1);
    }

    void test_pushFourElements()
    {
        heap->push(5);
        CPPUNIT_ASSERT(heap->peek() == 5);
        CPPUNIT_ASSERT(heap->getSize() == 1);

        heap->push(7);
        CPPUNIT_ASSERT(heap->peek() == 7);
        CPPUNIT_ASSERT(heap->getSize() == 2);

        heap->push(3);
        CPPUNIT_ASSERT(heap->peek() == 7);
        CPPUNIT_ASSERT(heap->getSize() == 3);

        heap->push(9);
        CPPUNIT_ASSERT(heap->peek() == 9);
        CPPUNIT_ASSERT(heap->getSize() == 4);
    }

    void test_pushOnePopOne()
    {
        heap->push(5);
        CPPUNIT_ASSERT(heap->peek() == 5);
        CPPUNIT_ASSERT(heap->getSize() == 1);

        int el = heap->pop();
        CPPUNIT_ASSERT(el == 5);
        CPPUNIT_ASSERT(heap->getSize() == 0);
    }

    void test_pushTwoPopOne()
    {
        heap->push(5);
        CPPUNIT_ASSERT(heap->peek() == 5);
        CPPUNIT_ASSERT(heap->getSize() == 1);

        heap->push(8);
        CPPUNIT_ASSERT(heap->peek() == 8);
        CPPUNIT_ASSERT(heap->getSize() == 2);

        int el = heap->pop();
        CPPUNIT_ASSERT(el == 8);
        CPPUNIT_ASSERT(heap->peek() == 5);
        CPPUNIT_ASSERT(heap->getSize() == 1);
    }

    void test_pushFourPopFour()
    {
        heap->push(5);
        CPPUNIT_ASSERT(heap->peek() == 5);
        CPPUNIT_ASSERT(heap->getSize() == 1);

        heap->push(7);
        CPPUNIT_ASSERT(heap->peek() == 7);
        CPPUNIT_ASSERT(heap->getSize() == 2);

        heap->push(4);
        CPPUNIT_ASSERT(heap->peek() == 7);
        CPPUNIT_ASSERT(heap->getSize() == 3);

        heap->push(11);
        CPPUNIT_ASSERT(heap->peek() == 11);
        CPPUNIT_ASSERT(heap->getSize() == 4);
 
        int el = heap->pop();
        CPPUNIT_ASSERT(el == 11);
        CPPUNIT_ASSERT(heap->peek() == 7);
        CPPUNIT_ASSERT(heap->getSize() == 3);

        el = heap->pop();
        CPPUNIT_ASSERT(el == 7);
        CPPUNIT_ASSERT(heap->peek() == 5);
        CPPUNIT_ASSERT(heap->getSize() == 2);

        el = heap->pop();
        CPPUNIT_ASSERT(el == 5);
        CPPUNIT_ASSERT(heap->peek() == 4);
        CPPUNIT_ASSERT(heap->getSize() == 1);

        el = heap->pop();
        CPPUNIT_ASSERT(el == 4);
        CPPUNIT_ASSERT(heap->getSize() == 0);
    }

    void test_popEmpty()
    {
        CPPUNIT_ASSERT(heap->getSize() == 0);
        heap->pop();
    }
};

int main(int argc, const char* argv[])
{
    CppUnit::TextUi::TestRunner runner;

    runner.addTest(MaxHeapTest::suite());
    runner.run();

    return runner.result().testFailures();
}
