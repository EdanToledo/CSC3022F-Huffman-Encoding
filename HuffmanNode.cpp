//
// Created by edan on 2020/03/07.
//

#include "HuffmanNode.h"

//Default Constructor
TLDEDA001::HuffmanNode::HuffmanNode() {}

//Parameter Constructor
TLDEDA001::HuffmanNode::HuffmanNode(char inputdata, int inputfreq)
{
    this->data = inputdata;
    this->freq = inputfreq;
}

//Destructor
TLDEDA001::HuffmanNode::~HuffmanNode() {}

//Copy Constructor
TLDEDA001::HuffmanNode::HuffmanNode(HuffmanNode &rhs)
{
    this->left = rhs.left;
    this->right = rhs.right;
}

//Move Constructor
TLDEDA001::HuffmanNode::HuffmanNode(HuffmanNode &&rhs)
{
    this->left = (std::move(rhs.left));
    this->right = (std::move(rhs.right));
}

//Assignment Operator
    TLDEDA001::HuffmanNode TLDEDA001::HuffmanNode::operator=(const HuffmanNode &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        this->left = rhs.left;
        this->right = rhs.right;
    }

//Move Assignment Operator
     TLDEDA001::HuffmanNode& TLDEDA001::HuffmanNode::operator=(HuffmanNode &&rhs)
    {
        if (this != &rhs)
        {
            this->left = std::move(rhs.left);
            this->right = std::move(rhs.right);
        }
        return *this;
    }

//less than operator 
    bool TLDEDA001::HuffmanNode::operator<( HuffmanNode & rhs){
        if (this->freq<rhs.freq)
        {
            return true;
        }else{
            return false;
        }
        
    }

//comparison method
bool TLDEDA001::HuffmanNode::compare(HuffmanNode &a, HuffmanNode &b)
{

    return (a<b);
}

//Getter of Frequency
const int TLDEDA001::HuffmanNode::getFreq()
{
    return this->freq;
}
//Getter of Data
const char TLDEDA001::HuffmanNode::getData()
{
    return this->data;
}