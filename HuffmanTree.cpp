//
// Created by edan on 2020/03/07.
//

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <queue>
#include <bits/stdc++.h>

//Default Constructor
TLDEDA001::HuffmanTree::HuffmanTree()
{
}

//Destructor
TLDEDA001::HuffmanTree::~HuffmanTree()
{
}

//Copy Constructor
TLDEDA001::HuffmanTree::HuffmanTree(const HuffmanTree &rhs)
{

    this->root = rhs.root;
}

//Move Constructor
TLDEDA001::HuffmanTree::HuffmanTree(HuffmanTree &&rhs)
{

    this->root = std::move(rhs.root);
}

//Assignment Operator
TLDEDA001::HuffmanTree &TLDEDA001::HuffmanTree::operator=(const HuffmanTree &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    this->root = rhs.root;
}

//Move Assignment Operator
TLDEDA001::HuffmanTree &TLDEDA001::HuffmanTree::operator=(HuffmanTree &&rhs)
{
    if (this != &rhs)
    {
        this->root = std::move(rhs.root);
    }
    return *this;
}

//Build Tree method
void TLDEDA001::HuffmanTree::BuildHuffmanTree(std::string inputfile)
{

    std::priority_queue<TLDEDA001::HuffmanNode> queue;

    for (std::pair<char, int> element : BuildFrequencyTable(inputfile))
    {
        std::shared_ptr<TLDEDA001::HuffmanNode> temp(new TLDEDA001::HuffmanNode(element.first, element.second));
        // std::cout<<"KEY: "<<element.first<<" FREQUENCY"<<element.second<<std::endl;
        queue.push(*temp);
    }

    while (queue.size() > 1)
    {
        std::shared_ptr<TLDEDA001::HuffmanNode> internal(new TLDEDA001::HuffmanNode());

        auto left = queue.top();
        internal->setLeft(left);

        queue.pop();
        auto right = queue.top();

        internal->setRight(right);

        queue.pop();
        internal->setFreq(left.getFreq() + right.getFreq());

        queue.push(*internal);
    }

    auto rootNode = queue.top();

    root = std::make_shared<TLDEDA001::HuffmanNode>(rootNode);

    queue.pop();
}

//build code table starting from root of tree
void TLDEDA001::HuffmanTree::BuildCodeTable()
{

    traverse(root, "");
}

//recursive traverse method to build code table
void TLDEDA001::HuffmanTree::traverse(std::shared_ptr<TLDEDA001::HuffmanNode> currentnode, std::string code)
{

    std::string currCode = code;

    if (currentnode.get() == nullptr)
    {
        return;
    }

    traverse(currentnode->getLeft(), currCode + "0");

    if (currentnode->getLeft() == nullptr && currentnode->getRight() == nullptr)
    {

        codeTable[currentnode->getData()] = currCode;
    }

    traverse(currentnode->getRight(), currCode + "1");
}

//Getter method for root
std::shared_ptr<TLDEDA001::HuffmanNode> TLDEDA001::HuffmanTree::getRoot()
{
    return this->root;
}

//print code table to console
void TLDEDA001::HuffmanTree::printCode()
{
    for (std::pair<char, std::string> element : codeTable)
    {
        std::cout << "KEY: " << element.first << " CODE: " << element.second << std::endl;
    }
}

//outputs header file with relevant bit prefixes
void TLDEDA001::HuffmanTree::outputHeader(std::string outputfile)
{
    std::ofstream out(outputfile + ".hdr");
    out << codeTable.size() << std::endl;
    for (std::pair<char, std::string> element : codeTable)
    {
        out << element.first << " " << element.second << std::endl;
    }
    out.close();
}

//Outputs bit string file from ascii file
void TLDEDA001::HuffmanTree::OutputBitStringFile(std::string inputfile, std::string outputfile)
{

    std::string bitstring;

    std::ifstream inputstream(inputfile);
    char charac;

    while (inputstream.get(charac))
    {
        bitstring += codeTable[charac];
    }

    std::ofstream out(outputfile + "Bitstring", std::ios::out | std::ios::binary);

    out.write(bitstring.c_str(), bitstring.size());
    out.close();
    inputstream.close();
}

//Bit pack file from an input file of bit strings
void TLDEDA001::HuffmanTree::BitpackFile(std::string bitstringfile, std::string outputfilename)
{

    std::ifstream inputstream(bitstringfile + "Bitstring");

    std::string bitstring;
    char bit;

    while (inputstream.get(bit))
    {
        bitstring += bit;
    }

    int bitslength = bitstring.size();
    inputstream.close();
    std::ofstream out(outputfilename + ".bin", std::ios::out | std::ios::binary);
    out << bitslength << std::endl;

    while (bitstring.size() > 8)
    {
        std::bitset<8> bitset(bitstring.substr(0, 8));
        int ulong = bitset.to_ulong();
        char val = (char)ulong;
        out << val;

        bitstring = bitstring.substr(8);
    }

    for (int i = bitstring.size(); i < 8; i++)
    {
        bitstring += '0';
    }

    std::bitset<8> bitset(bitstring);
    int ulong = bitset.to_ulong();
    char val = (char)ulong;
    out << val;
    out.close();
}

//unpack bitpacked file into bitstring file
void TLDEDA001::HuffmanTree::UnpackFile(std::string bitpackedfile, std::string outputfilename)
{

    std::ifstream inputstream(bitpackedfile);

    std::ofstream out(outputfilename + "Unpacked", std::ios::out | std::ios::binary);

    std::string bitstring;
    char byte;
    std::string temp;
    getline(inputstream, temp);
    int length = std::stoi(temp);
    out << length << std::endl;
    while (inputstream.get(byte))
    {
        std::bitset<8> bitset(byte);

        out << bitset.to_string();
    }
    out.close();
    inputstream.close();
}

void TLDEDA001::HuffmanTree::Decode(std::string bitstringfile, std::string outputfile, std::unordered_map<std::string, char> reverse)
{

    std::ifstream inputstream(bitstringfile + "Unpacked");

    std::ofstream out(outputfile);

    std::string bitstring;
    char val;
    std::string cur = "";
    std::string temp;
    std::getline(inputstream, temp);
    int length = std::stoi(temp);
    for (int i = 0; i < length; i++)
    {
        inputstream.get(val);
        cur += val;
        if (reverse.count(cur))
        {
            out << reverse[cur];
            cur = "";
        }
    }

    inputstream.close();
    out.close();
}

//compress file - .bin is the compressed file, the outputfile without the extension is the unpacked file
//makes use of other methods and removes unnecessary temp files
void TLDEDA001::HuffmanTree::Compress(std::string InputFileName, std::string OutputFileName)
{
    BuildCodeTable();
    outputHeader(OutputFileName);
    OutputBitStringFile(InputFileName, OutputFileName);
    BitpackFile(OutputFileName, OutputFileName);
    remove((OutputFileName + "Bitstring").c_str());
}

//decompress file -
void TLDEDA001::HuffmanTree::Decompress(std::string InputFileName, std::string OutputFileName, std::string HeaderFile)
{

    UnpackFile(InputFileName, OutputFileName);
    Decode(OutputFileName, OutputFileName, BuildHeaderTable(HeaderFile));
    remove((OutputFileName + "Unpacked").c_str());
}

//builds the frequency table of chars from an input file
std::unordered_map<char, int> TLDEDA001::HuffmanTree::BuildFrequencyTable(std::string inputfile)
{

    std::unordered_map<char, int> freq;

    std::ifstream inputstream(inputfile);
    char charac;
    while (inputstream.get(charac))
    {

        freq[charac] = freq[charac] + 1;
    }

    return freq;
}

//returns a hashmap of bit prefix and the char from the header file
std::unordered_map<std::string, char> TLDEDA001::HuffmanTree::BuildHeaderTable(std::string inputfile)
{

    std::unordered_map<std::string, char> reverse;

    std::ifstream inputstream(inputfile);

    std::string temp;
    std::getline(inputstream, temp);

    int fieldlength = std::stoi(temp);
    while (std::getline(inputstream, temp))
    {

        if (temp == "")
        {
            std::getline(inputstream, temp);
            reverse[temp.substr(1)] = '\n';
        }
        else
        {

            reverse[temp.substr(2)] = temp[0];
        }
    }

    return reverse;
}

//Return Code Table
std::unordered_map<char, std::string> TLDEDA001::HuffmanTree::getCodeTable() {
    return this->codeTable;
}
