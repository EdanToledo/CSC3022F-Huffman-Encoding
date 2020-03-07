//
// Created by edan on 2020/03/07.
//

#ifndef ASSIGNMENT3_HUFFMANNODE_H
#define ASSIGNMENT3_HUFFMANNODE_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace TLDEDA001
{
class HuffmanNode
{

    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;
    char data;
    int freq;

public:
    //Default Constructor
    HuffmanNode();

    //Parameter Constructor
    HuffmanNode(char inputdata, int inputfreq);

    //Destructor
    ~HuffmanNode();

    //Copy Constructor
    HuffmanNode(HuffmanNode &rhs);

    //Move Constructor
    HuffmanNode(HuffmanNode &&rhs);

    //Assignment Operator
    HuffmanNode operator=(const HuffmanNode &rhs);

    //Move Assignment Operator
    HuffmanNode &operator=(HuffmanNode &&rhs);

    //less than operator
    bool operator<(HuffmanNode &rhs);

    //comparison method
    bool compare(HuffmanNode &a, HuffmanNode &b);

//getter method of freq
    const int getFreq();

//getter method of data
    const char getData();
};

} // namespace TLDEDA001

#endif //ASSIGNMENT3_HUFFMANNODE_H
