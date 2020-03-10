//
// Created by edan on 2020/03/07.
//

#include "HuffmanTree.h"
#include <queue>
#include "HuffmanNode.h"
#include <vector>

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
void TLDEDA001::HuffmanTree::BuildHuffmanTree(std::unordered_map<char, int> datafreq)
{

    std::priority_queue<TLDEDA001::HuffmanNode> queue;

  

    for (std::pair<char, int> element : datafreq)
    {
        std::shared_ptr<TLDEDA001::HuffmanNode>temp(new TLDEDA001::HuffmanNode(element.first, element.second));
        
        queue.push(*temp);
    }
    //FIX DOES DONT WORK
    while (queue.size() > 1)
    {
        std::shared_ptr<TLDEDA001::HuffmanNode>internal(new TLDEDA001::HuffmanNode());
        
        auto left = queue.top();
        internal->setLeft(left);
      
        queue.pop();
        auto right = queue.top();
        
        internal->setRight(right);
        
        queue.pop();
        internal->setFreq(left.getFreq()+right.getFreq());
        internal->setData('\0');
        queue.push(*internal);
        
       
    }

    auto rootNode = queue.top();
    root = std::make_shared<TLDEDA001::HuffmanNode>(rootNode);

}



