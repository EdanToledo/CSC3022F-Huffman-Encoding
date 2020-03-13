//
// Created by edan on 2020/03/07.
//

#include "HuffmanNode.h"

//Default Constructor
TLDEDA001::HuffmanNode::HuffmanNode()
{
    this->left = nullptr;
    this->right = nullptr;
}

//Parameter Constructor
TLDEDA001::HuffmanNode::HuffmanNode(char inputdata, int inputfreq)
{
    this->data = inputdata;
    this->freq = inputfreq;
}

//Destructor
TLDEDA001::HuffmanNode::~HuffmanNode()
{
    left = nullptr;
    right = nullptr;
    freq = -1;
}

//Copy Constructor
TLDEDA001::HuffmanNode::HuffmanNode(const HuffmanNode &rhs)
{
    this->left = rhs.left;
    this->right = rhs.right;
    this->data = rhs.data;
    this->freq = rhs.freq;
}

//Move Constructor
TLDEDA001::HuffmanNode::HuffmanNode(HuffmanNode &&rhs)
{
    this->left = (std::move(rhs.left));
    this->right = (std::move(rhs.right));
    this->data = (std::move(rhs.data));
    this->freq = (std::move(rhs.freq));
}

//Assignment Operator
TLDEDA001::HuffmanNode &TLDEDA001::HuffmanNode::operator=(const HuffmanNode &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    this->left = rhs.left;
    this->right = rhs.right;
    this->data = rhs.data;
    this->freq = rhs.freq;
}

//Move Assignment Operator
TLDEDA001::HuffmanNode &TLDEDA001::HuffmanNode::operator=(HuffmanNode &&rhs)
{
    if (this != &rhs)
    {
        this->left = std::move(rhs.left);
        this->right = std::move(rhs.right);
        this->data = (std::move(rhs.data));
        this->freq = (std::move(rhs.freq));
    }
    return *this;
}

//Binary Operator
bool TLDEDA001::operator<(const HuffmanNode &lhs, const HuffmanNode &rhs)
{
    return !(lhs.freq < rhs.freq);
}

//Getter of Frequency
int TLDEDA001::HuffmanNode::getFreq() const
{
    return this->freq;
}
//Setter of Left child
void TLDEDA001::HuffmanNode::setLeft(HuffmanNode &lhs)
{

    left = std::make_shared<HuffmanNode>(lhs);
}

//Setter of Right child
void TLDEDA001::HuffmanNode::setRight(HuffmanNode &rhs)
{
    right = std::make_shared<HuffmanNode>(rhs);
}
//Getter of Data
char TLDEDA001::HuffmanNode::getData() const
{
    return this->data;
}

//Setter of Frequency
void TLDEDA001::HuffmanNode::setFreq(int val)
{
    this->freq = val;
}

//Setter of Data
void TLDEDA001::HuffmanNode::setData(char dat)
{
    this->data = dat;
}

//getter method of left
std::shared_ptr<TLDEDA001::HuffmanNode> TLDEDA001::HuffmanNode::getLeft()
{
    return this->left;
}

//getter method of right
std::shared_ptr<TLDEDA001::HuffmanNode> TLDEDA001::HuffmanNode::getRight()
{
    return this->right;
}
