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

namespace TLDEDA001{
class HuffmanNode {

std::shared_ptr<HuffmanNode> left;
std::shared_ptr<HuffmanNode> right;

public:

//Constructor
HuffmanNode(){

}
//Destructor
~HuffmanNode(){
    
}

//Copy Constructor
HuffmanNode(HuffmanNode & rhs){
    this->left = rhs.left;
    this->right = rhs.right;
}

//Move Constructor
HuffmanNode(HuffmanNode && rhs){
   this->left=(std::move(rhs.left));
   this->right = std::move(rhs.right);
  
}

//Assignment Operator
HuffmanNode operator=(const HuffmanNode & rhs){
    if (this == &rhs)
    {
       return *this;
    }
    this->left = rhs.left;
    this->right = rhs.right;
    
}

//Move Assignment Operator
HuffmanNode & operator =(HuffmanNode && rhs){
    if (this!=&rhs)
    {
       this->left = std::move(rhs.left);
       this->right =std::move(rhs.right);
    }
    return *this;
}


    
};

}

#endif //ASSIGNMENT3_HUFFMANNODE_H
