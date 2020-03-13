#include "catch.hpp"
#include "HuffmanTree.h"
#include "HuffmanNode.h"

using namespace Catch;


//HUFFMAN TREE TESTS
//******************************************************************************************

//TEST TO SEE IF HUFFMAN TREE IS BUILT CORRECLTY
TEST_CASE("BUILD HUFFMAN TREE")
{
    // REQUIRE()
}

//TEST TO SEE IF FREQUENCY TABLE IS BUILT CORRECTLY
TEST_CASE("BUILD FREQUENCY TABLE")
{
    /*
    std::unordered_map<char, int> toCheck;
    toCheck['t'] = 2;
    toCheck['e'] = 2;
    toCheck['s'] = 2;
    toCheck['c'] = 1;
    toCheck['a'] = 1;

    REQUIRE(huff.BuildFrequencyTable("TESTINPUT") == toCheck);
    */
}

//TEST TO SEE IF CODE TABLE IS BUILT CORRECTLY
TEST_CASE("BUILD CODE TABLE") {}

//TEST TO SEE IF HEADER FILE IS CREATED CORRECTLY
TEST_CASE("OUTPUT HEADER") {}

//TEST TO SEE IF ASCII TEXT FILE IS OUTPUTTED INTO IT'S CORRECT
//BITS FORM
TEST_CASE("OUTPUT BITSTRING FILE") {}

//TEST TO SEE IF THE BITS FORM OF THE ASCII TEXT FILE
//IS CORRECTLY PACKED INTO A BINARY FILE
TEST_CASE("BITPACK THE BITSTRING FILE") {}

//TEST TO SEE IF BITPACKED FILE IS CORRECTLY UNPACKED INTO
//A FILE OF APPROPRIATE ASCII BIT VALUES ACCORDING TO THEIR
//CHAR BIT PREFIX CODES
TEST_CASE("UNPACK THE BITPACKED FILE") {}

//TEST TO SEE IF ASCII BIT VALUES ARE CORRECLTY CONVERTED
//BACK INTO THEIR APPROPRIATE CHAR VALUES
TEST_CASE("DECODE METHOD") {}

//TEST TO SEE IF CODE TABLE FROM HEADER FILE IS BUILT CORRECTLY
TEST_CASE("BUILD HEADER TABLE") {}
//******************************************************************************************