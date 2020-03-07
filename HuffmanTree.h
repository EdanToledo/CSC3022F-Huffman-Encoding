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

public:
    //Constructor
    HuffmanTree() {}

    //Destructor
    ~HuffmanTree()
    {
    }

    //Copy Constructor
    HuffmanTree(HuffmanTree &rhs)
    {

        this->root = rhs.root;
    }

    //Move Constructor
    HuffmanTree(HuffmanTree &&rhs)
    {

        this->root = std::move(rhs.root);
    }

    //Assignment Operator
    HuffmanTree &operator=(const HuffmanTree &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        this->root = rhs.root;
    }

    //Move Assignment Operator
    HuffmanTree &operator=(HuffmanTree &&rhs)
    {
        if (this != &rhs)
        {
            this->root = std::move(rhs.root);
        }
        return *this;
    }

    //Build Tree method
    void BuildHuffmanTree(std::unordered_map<char,int> datafreq);

   
};

} // namespace TLDEDA001
#endif //ASSIGNMENT3_HUFFMANTREE_H
