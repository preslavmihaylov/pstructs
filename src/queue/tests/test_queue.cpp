#include <cppunit/TestResultCollector.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <pstructs/queue.h>
#include <iostream>

class QueueTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(QueueTest);

CPPUNIT_TEST(test_enqueueOneElement);
CPPUNIT_TEST(test_enqueueOneDequeueOne);
CPPUNIT_TEST(test_growingQueue);
CPPUNIT_TEST(test_enqueueDequeueMultiple);
CPPUNIT_TEST(test_copyConstructor);
CPPUNIT_TEST(test_assignmentOperator);
CPPUNIT_TEST_EXCEPTION(test_peekWhenQueueEmpty, std::invalid_argument);
CPPUNIT_TEST_EXCEPTION(test_dequeueEmptyQueue, std::invalid_argument);

CPPUNIT_TEST_SUITE_END();

pstructs::queue<int> *myQueue;

public:
    void setUp()
    {
        myQueue = new pstructs::queue<int>();
    }

    void tearDown()
    {
        delete myQueue;
    }

    void test_enqueueOneElement()
    {
        myQueue->enqueue(5);
        CPPUNIT_ASSERT(myQueue->getSize() == 1);
        CPPUNIT_ASSERT(myQueue->peek() == 5);
    }

    void test_enqueueOneDequeueOne()
    {
        myQueue->enqueue(5);
        CPPUNIT_ASSERT(myQueue->getSize() == 1);
        CPPUNIT_ASSERT(myQueue->peek() == 5);

        int element = myQueue->dequeue();
        CPPUNIT_ASSERT(myQueue->getSize() == 0);
        CPPUNIT_ASSERT(element == 5);
    }

    void test_growingQueue()
    {
        for (int i = 1; i <= 10; i++)
        {
            myQueue->enqueue(i);
            CPPUNIT_ASSERT(myQueue->getSize() == i);
        }

        for (int i = 1; i <= 10; i++)
        {
            int element = myQueue->dequeue();
            CPPUNIT_ASSERT(element == i);
            CPPUNIT_ASSERT(myQueue->getSize() == 10 - i);
        }
    }

    void test_peekWhenQueueEmpty()
    {
        int element = myQueue->peek();
        (void)element;
    }

    void test_dequeueEmptyQueue()
    {
        int element = myQueue->dequeue(); 
        (void)element;
    }
    
    void test_copyConstructor()
    {
        myQueue->enqueue(1); 
        myQueue->enqueue(2); 
        myQueue->enqueue(3); 
        myQueue->enqueue(4); 
        myQueue->enqueue(5); 

        pstructs::queue<int> otherQueue(*myQueue);

        for (int i = 1; i <= 5; i++)
        {
            int element = otherQueue.dequeue();
            CPPUNIT_ASSERT(element == i);
        }

        CPPUNIT_ASSERT(myQueue->getSize() == 5);
    }

    void test_assignmentOperator()
    {
        myQueue->enqueue(1); 
        myQueue->enqueue(2); 
        myQueue->enqueue(3); 
        myQueue->enqueue(4); 
        myQueue->enqueue(5); 

        pstructs::queue<int> otherQueue;
        otherQueue = *myQueue;

        for (int i = 1; i <= 5; i++)
        {
            int element = otherQueue.dequeue();
            CPPUNIT_ASSERT(element == i);
        }

        CPPUNIT_ASSERT(myQueue->getSize() == 5);
    }

    void test_enqueueDequeueMultiple()
    {
        myQueue->enqueue(5);
        CPPUNIT_ASSERT(myQueue->getSize() == 1);
        CPPUNIT_ASSERT(myQueue->peek() == 5);

        myQueue->enqueue(6);
        CPPUNIT_ASSERT(myQueue->getSize() == 2);

        myQueue->enqueue(7);
        CPPUNIT_ASSERT(myQueue->getSize() == 3);
        
        myQueue->enqueue(8);
        CPPUNIT_ASSERT(myQueue->getSize() == 4);
        CPPUNIT_ASSERT(myQueue->peek() == 5);

        int element = myQueue->dequeue();
        CPPUNIT_ASSERT(myQueue->getSize() == 3);
        CPPUNIT_ASSERT(element == 5);
        CPPUNIT_ASSERT(myQueue->peek() == 6);

        myQueue->enqueue(9);
        CPPUNIT_ASSERT(myQueue->getSize() == 4);
        CPPUNIT_ASSERT(myQueue->peek() == 6);

        element = myQueue->dequeue();
        CPPUNIT_ASSERT(myQueue->getSize() == 3);
        CPPUNIT_ASSERT(element == 6);
        CPPUNIT_ASSERT(myQueue->peek() == 7);

        myQueue->enqueue(10);
        CPPUNIT_ASSERT(myQueue->getSize() == 4);
        CPPUNIT_ASSERT(myQueue->peek() == 7);

        element = myQueue->dequeue();
        CPPUNIT_ASSERT(myQueue->getSize() == 3);
        CPPUNIT_ASSERT(element == 7);
        CPPUNIT_ASSERT(myQueue->peek() == 8);

        element = myQueue->dequeue();
        CPPUNIT_ASSERT(myQueue->getSize() == 2);
        CPPUNIT_ASSERT(element == 8);
        CPPUNIT_ASSERT(myQueue->peek() == 9);

        element = myQueue->dequeue();
        CPPUNIT_ASSERT(myQueue->getSize() == 1);
        CPPUNIT_ASSERT(element == 9);
        CPPUNIT_ASSERT(myQueue->peek() == 10);

        element = myQueue->dequeue();
        CPPUNIT_ASSERT(myQueue->getSize() == 0);
        CPPUNIT_ASSERT(element == 10);
    }
};

int main(int argc, const char* argv[])
{
    CppUnit::TextUi::TestRunner runner;

    runner.addTest(QueueTest::suite());
    runner.run();

    return runner.result().testFailures();
}
