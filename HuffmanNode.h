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
     HuffmanNode(const HuffmanNode &rhs);

     //Move Constructor
     HuffmanNode(HuffmanNode &&rhs);

     //Assignment Operator
     HuffmanNode &operator=(const HuffmanNode &rhs);

     //Move Assignment Operator
     HuffmanNode &operator=(HuffmanNode &&rhs);

     //binary operator overloading
     friend bool operator<(const HuffmanNode &lhs, const HuffmanNode &rhs);

     //Setter of Left child
     void setLeft(HuffmanNode &lhs);

     //Setter of Right child
     void setRight(HuffmanNode &rhs);

     //Setter of Frequency
     void setFreq(int val);

     //Setter of Data
     void setData(char dat);

     //getter method of freq
     int getFreq() const;

     //getter method of data
     char getData() const;

     //getter method of left
     std::shared_ptr<HuffmanNode> getLeft();

     //getter method of right
     std::shared_ptr<HuffmanNode> getRight();
};

} // namespace TLDEDA001

#endif //ASSIGNMENT3_HUFFMANNODE_H
