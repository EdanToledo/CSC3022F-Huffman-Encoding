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
    std::unordered_map<char,std::string> codeTable;

    //traverse tree and assign codes to nodes
    void traverse(std::shared_ptr<TLDEDA001::HuffmanNode> currentnode,std::string code);
   

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

    //Build Tree method
    void BuildHuffmanTree(std::unordered_map<char,int> datafreq);

    //Build Code Table into hashmap
    void BuildCodeTable();

    
   //Getter method for root
   std::shared_ptr<HuffmanNode> getRoot();

    //Print out code table
    void printCode();


};

} // namespace TLDEDA001
#endif //ASSIGNMENT3_HUFFMANTREE_H
