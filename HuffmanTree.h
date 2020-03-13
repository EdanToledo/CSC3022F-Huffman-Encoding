//
// Created by edan on 2020/03/07.
//

#ifndef ASSIGNMENT3_HUFFMANTREE_H
#define ASSIGNMENT3_HUFFMANTREE_H

#include "HuffmanNode.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
namespace TLDEDA001
{
class HuffmanTree
{

    std::shared_ptr<HuffmanNode> root;
    std::unordered_map<char, std::string> codeTable;

    //traverse tree and assign codes to nodes
    void traverse(std::shared_ptr<TLDEDA001::HuffmanNode> currentnode, std::string code);

public:
    //Constructor
    HuffmanTree();

    //Destructor
    ~HuffmanTree();

    //Copy Constructor
    HuffmanTree(const HuffmanTree &rhs);

    //Move Constructor
    HuffmanTree(HuffmanTree &&rhs);

    //Assignment Operator
    HuffmanTree &operator=(const HuffmanTree &rhs);

    //Move Assignment Operator
    HuffmanTree &operator=(HuffmanTree &&rhs);

    //returns a hashmap of char and the frequency of occurence of that char in a file
    std::unordered_map<char, int> BuildFrequencyTable(std::string inputfile);

    //returns a hashmap of bit prefix and the char from the header file
    std::unordered_map<std::string, char> BuildHeaderTable(std::string inputfile);

    //Build Tree method
    void BuildHuffmanTree(std::string inputfile);

    //Build Code Table into hashmap
    void BuildCodeTable();

    //Getter method for root
    std::shared_ptr<HuffmanNode> getRoot();

    //Print out code table
    void printCode();

    //output code table to header
    void outputHeader(std::string outputfile);

    //output bitstring  file
    void OutputBitStringFile(std::string inputfile, std::string outputfile);

    //Bitpack bitstring file
    void BitpackFile(std::string bitstringfile, std::string outputfilename);

    //Unpack bitpacked file
    void UnpackFile(std::string bitpackedfile, std::string outputfilename);

    //compress file
    void Compress(std::string InputFileName, std::string OutputFileName);

    //decompress file
    void Decompress(std::string InputFileName, std::string OutputFileName, std::string HeaderFile);

    //Decode bitstringfile into original file
    void Decode(std::string bitstringfile, std::string outputfile,std::unordered_map<std::string,char> reverse);
};

} // namespace TLDEDA001
#endif //ASSIGNMENT3_HUFFMANTREE_H
