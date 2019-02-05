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
CPPUNIT_TEST(test_clearBitChangeExpected);
CPPUNIT_TEST(test_clearBitNoChangeExpected);
CPPUNIT_TEST(test_clearBitBigNumber);
CPPUNIT_TEST(test_raiseBitChange);
CPPUNIT_TEST(test_raiseBitNoChange);
CPPUNIT_TEST(test_raiseBitBigNumber);
CPPUNIT_TEST(test_setBitBigNumber);
CPPUNIT_TEST(test_setBitZero);
CPPUNIT_TEST(test_setBitOne);
CPPUNIT_TEST(test_getBitOne);
CPPUNIT_TEST(test_getBitZero);
CPPUNIT_TEST(test_toBinaryStringFifteen);
CPPUNIT_TEST(test_toBinaryStringMinusOne);
CPPUNIT_TEST(test_toBinaryStringOneSeventy);
CPPUNIT_TEST(test_toBinaryStringZero);
CPPUNIT_TEST(test_binaryStringToNumber_1101);
CPPUNIT_TEST(test_binaryStringToNumber_11111111);
CPPUNIT_TEST(test_binaryStringToNumber_0);
CPPUNIT_TEST(test_binaryStringToNumber_lvalue);

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

    void test_clearBitChangeExpected()
    {
        int res = pstructs::bit_ops::clearBit(15, 0);
        CPPUNIT_ASSERT(res == 14);
    }

    void test_clearBitNoChangeExpected()
    {
        int res = pstructs::bit_ops::clearBit(14, 0);
        CPPUNIT_ASSERT(res == 14);
    }

    void test_clearBitBigNumber()
    {
        int res = pstructs::bit_ops::clearBit(268402688, 15);
        CPPUNIT_ASSERT(res == 268369920);
    }

    void test_raiseBitChange()
    {
        int res = pstructs::bit_ops::raiseBit(14, 0);
        CPPUNIT_ASSERT(res == 15);
    }

    void test_raiseBitNoChange()
    {
        int res = pstructs::bit_ops::raiseBit(15, 1);
        CPPUNIT_ASSERT(res == 15);
    }

    void test_raiseBitBigNumber()
    {
        int res = pstructs::bit_ops::raiseBit(268369920, 15);
        CPPUNIT_ASSERT(res == 268402688);
    }

    void test_setBitBigNumber()
    {
        int res = pstructs::bit_ops::setBit(268369920, 15, 1);
        CPPUNIT_ASSERT(res == 268402688);
    }

    void test_setBitZero()
    {
        int res = pstructs::bit_ops::setBit(15, 1, 0);
        CPPUNIT_ASSERT(res == 13);
    }

    void test_setBitOne()
    {
        int res = pstructs::bit_ops::setBit(13, 1, 1);
        CPPUNIT_ASSERT(res == 15);
    }

    void test_getBitOne()
    {
        int res = pstructs::bit_ops::getBit(13, 2);
        CPPUNIT_ASSERT(res == 1);
    }

    void test_getBitZero()
    {
        int res = pstructs::bit_ops::getBit(13, 1);
        CPPUNIT_ASSERT(res == 0);
    }

    void test_toBinaryStringFifteen()
    {
        string res = pstructs::bit_ops::toBinaryString(15);
        CPPUNIT_ASSERT(res == "1111");
    }

    void test_toBinaryStringMinusOne()
    {
        string res = pstructs::bit_ops::toBinaryString((uint32_t)-1);
        CPPUNIT_ASSERT(res == string(32, '1'));
    }
    void test_toBinaryStringOneSeventy()
    {
        string res = pstructs::bit_ops::toBinaryString(170);
        CPPUNIT_ASSERT(res == "10101010");
    }

    void test_toBinaryStringZero()
    {
        string res = pstructs::bit_ops::toBinaryString(0);
        CPPUNIT_ASSERT(res == "0");
    }

    void test_binaryStringToNumber_1101()
    {
        uint32_t res = pstructs::bit_ops::binaryStringToNumber("1101");
        CPPUNIT_ASSERT(res == 13);
    }

    void test_binaryStringToNumber_11111111()
    {
        uint32_t res = pstructs::bit_ops::binaryStringToNumber("11111111");
        CPPUNIT_ASSERT(res == 255);
    }

    void test_binaryStringToNumber_0()
    {
        uint32_t res = pstructs::bit_ops::binaryStringToNumber("0");
        CPPUNIT_ASSERT(res == 0);
    }

    void test_binaryStringToNumber_lvalue()
    {
        string input = "1111";
        uint32_t res = pstructs::bit_ops::binaryStringToNumber(input);
        CPPUNIT_ASSERT(res == 15);
    }
};

int main(int argc, const char* argv[])
{
    CppUnit::TextUi::TestRunner runner;

    runner.addTest(BitOpsTest::suite());
    runner.run();

    return runner.result().testFailures();
}
