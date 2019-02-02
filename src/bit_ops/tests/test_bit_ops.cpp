#include <cppunit/TestResultCollector.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <pstructs/bit_ops.h>
#include <iostream>

using namespace std;

class BitOpsTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(BitOpsTest);

CPPUNIT_TEST(test_bitsCntOne);
CPPUNIT_TEST(test_bitsCntFifteen);
CPPUNIT_TEST(test_bitsCntMax);
//CPPUNIT_TEST_EXCEPTION(test_popEmpty, std::invalid_argument);

CPPUNIT_TEST_SUITE_END();

public:
    void test_bitsCntOne()
    {
        int cnt = pstructs::bit_ops::bitsCnt(1);
        CPPUNIT_ASSERT(cnt == 1);
    }

    void test_bitsCntFifteen()
    {
        int cnt = pstructs::bit_ops::bitsCnt(15);
        CPPUNIT_ASSERT(cnt == 4);
    }

    void test_bitsCntMax()
    {
        int cnt = pstructs::bit_ops::bitsCnt((uint32_t)-1);
        CPPUNIT_ASSERT(cnt == 32);
    }
};

int main(int argc, const char* argv[])
{
    CppUnit::TextUi::TestRunner runner;

    runner.addTest(BitOpsTest::suite());
    runner.run();

    return runner.result().testFailures();
}
