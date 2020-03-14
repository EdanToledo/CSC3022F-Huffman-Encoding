#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "HuffmanTree.h"
#include "HuffmanNode.h"

//TESTINPUT

//HUFFMAN TREE TESTS
//******************************************************************************************

//TEST TO SEE IF HUFFMAN TREE IS BUILT CORRECLTY
TEST_CASE("BUILD HUFFMAN TREE")
{
    TLDEDA001::HuffmanTree huff;
    huff.BuildHuffmanTree("TESTINPUT");

    REQUIRE(huff.getRoot() != nullptr);
}

//TEST TO SEE IF FREQUENCY TABLE IS BUILT CORRECTLY
TEST_CASE("BUILD FREQUENCY TABLE")
{
    TLDEDA001::HuffmanTree huff;
    huff.BuildHuffmanTree("TESTINPUT");

    std::unordered_map<char, int> toCheck;
    toCheck['t'] = 2;
    toCheck['e'] = 2;
    toCheck['s'] = 2;
    toCheck['c'] = 1;
    toCheck['a'] = 1;
    toCheck['\n'] = 1;

    for (std::pair<char, int> element : huff.BuildFrequencyTable("TESTINPUT"))
    {

        REQUIRE(element.second == toCheck[element.first]);
    }
}

//TEST TO SEE IF CODE TABLE IS BUILT CORRECTLY
TEST_CASE("BUILD CODE TABLE")
{
    TLDEDA001::HuffmanTree huff;
    huff.BuildHuffmanTree("TESTINPUT");

    huff.BuildCodeTable();

    std::unordered_map<char, std::string> toCheck;
    toCheck['t'] = "00";
    toCheck['e'] = "10";
    toCheck['s'] = "111";
    toCheck['c'] = "011";
    toCheck['a'] = "110";
    toCheck['\n'] = "010";
    for (std::pair<char, std::string> element : huff.getCodeTable())
    {

        REQUIRE(element.second == toCheck[element.first]);
    }
}

//TEST TO SEE IF ASCII TEXT FILE IS OUTPUTTED INTO IT'S CORRECT
//BITS FORM
TEST_CASE("OUTPUT BITSTRING FILE")
{
    TLDEDA001::HuffmanTree huff;
    huff.BuildHuffmanTree("TESTINPUT");
    huff.BuildCodeTable();
    huff.OutputBitStringFile("TESTINPUT", "TESTBITSTRINGFILE");

    std::ifstream bitstringfile("TESTBITSTRINGFILEBitstring");
    char charac;
    std::string tocheck = "00101110001111011110010";
    int i = 0;
    while (bitstringfile.get(charac))
    {
        REQUIRE(charac == tocheck[i]);
        i++;
    }

    remove("TESTBITSTRINGFILEBitstring");
}

//TEST TO SEE IF THE BITS FORM OF THE ASCII TEXT FILE
//IS CORRECTLY PACKED INTO A BINARY FILE
TEST_CASE("BITPACK THE BITSTRING FILE")
{
    TLDEDA001::HuffmanTree huff;
    huff.BuildHuffmanTree("TESTINPUT");
    huff.BuildCodeTable();
    huff.OutputBitStringFile("TESTINPUT", "TESTBITSTRINGFILE");
    huff.BitpackFile("TESTBITSTRINGFILE", "TESTBITPACKED");

    std::ifstream in("TESTBITPACKED.bin");
    std::ifstream inprev("TESTINPUT");

    const auto begin = in.tellg();
    in.seekg(0, std::ios::end);
    const auto end = in.tellg();
    const auto fsize = (end - begin);

    const auto beginprev = inprev.tellg();
    inprev.seekg(0, std::ios::end);
    const auto endprev = inprev.tellg();
    const auto fsizeprev = (endprev - beginprev);

    REQUIRE(fsize < fsizeprev);

    remove("TESTBITSTRINGFILEBitstring");
    remove("TESTBITPACKED.bin");
}

//TEST TO SEE IF BITPACKED FILE IS CORRECTLY UNPACKED INTO
//A FILE OF APPROPRIATE ASCII BIT VALUES ACCORDING TO THEIR
//CHAR BIT PREFIX CODES
TEST_CASE("UNPACK THE BITPACKED FILE")
{
    TLDEDA001::HuffmanTree huff;
    huff.BuildHuffmanTree("TESTINPUT");
    huff.BuildCodeTable();
    huff.OutputBitStringFile("TESTINPUT", "TESTBITSTRINGFILE");
    huff.BitpackFile("TESTBITSTRINGFILE", "TESTBITPACKED");
    huff.UnpackFile("TESTBITPACKED.bin", "BITSTRING");

    std::ifstream bitstringfile("BITSTRINGUnpacked");
    std::string temp;
    getline(bitstringfile, temp);
    int length = std::stoi(temp);
    char charac;
    std::string tocheck = "00101110001111011110010";
    int i = 0;
    for (int i = 0; i < length; i++)
    {
        bitstringfile.get(charac);
        REQUIRE(charac == tocheck[i]);
    }

    remove("TESTBITSTRINGFILEBitstring");
    remove("TESTBITPACKED.bin");
    remove("BITSTRINGUnpacked");
}
//TEST TO SEE IF CODE TABLE FROM HEADER FILE IS BUILT CORRECTLY
TEST_CASE("BUILD TABLE FROM HEADER") {
    TLDEDA001::HuffmanTree huff;
    huff.outputHeader("TESTINPUT");


    std::unordered_map<std::string, char> toCheck;
    toCheck["00"] = 't';
    toCheck["10"] = 'e';
    toCheck["111"] = 's';
    toCheck["011"] = 'c';
    toCheck["110"] = 'a';
    toCheck["010"] = '\n';
    for (std::pair< std::string,char> element : huff.BuildHeaderTable("TESTINPUT.hdr"))
    {

        REQUIRE(element.second == toCheck[element.first]);
    }
remove("TESTINPUT.hdr");

}

//TEST TO SEE IF ASCII BIT VALUES ARE CORRECLTY CONVERTED
//BACK INTO THEIR APPROPRIATE CHAR VALUES
TEST_CASE("DECODE METHOD")
{
    TLDEDA001::HuffmanTree huff;
    huff.BuildHuffmanTree("TESTINPUT");
    huff.BuildCodeTable();
    huff.outputHeader("TESTINPUT");
    huff.OutputBitStringFile("TESTINPUT", "TESTBITSTRINGFILE");
    huff.BitpackFile("TESTBITSTRINGFILE", "TESTBITPACKED");
    huff.UnpackFile("TESTBITPACKED.bin", "BITSTRING");

    huff.Decode("BITSTRING", "TESTDECODE", huff.BuildHeaderTable("TESTINPUT.hdr"));

    std::ifstream inOrig("TESTINPUT");
    std::ifstream inDecode("TESTDECODE");
    char charac1, charac2;
    while (inOrig.get(charac1))
    {
        inDecode.get(charac2);
        REQUIRE(charac1 == charac2);
    }

    remove("TESTBITSTRINGFILEBitstring");
    remove("TESTBITPACKED.bin");
    remove("BITSTRINGUnpacked");
    remove("TESTDECODE");
    remove("TESTINPUT.hdr");
}


//******************************************************************************************
