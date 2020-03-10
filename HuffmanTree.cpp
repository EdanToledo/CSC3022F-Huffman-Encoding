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
       // std::cout<<"KEY: "<<element.first<<" FREQUENCY"<<element.second<<std::endl;
        queue.push(*temp);
    }
   



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
       
        queue.push(*internal);
       
       /*
         std::cout<<"left: "<<left.getData()<<" FREQUENCY "<<left.getFreq()<<std::endl;
        std::cout<<"right: "<<right.getData()<<" FREQUENCY "<<right.getFreq()<<std::endl;
          std::cout<<"KEY: "<<"internal"<<" FREQUENCY "<<internal->getFreq()<<std::endl;
       
       */
       
    }

    auto rootNode = queue.top();
    root = std::make_shared<TLDEDA001::HuffmanNode>(rootNode);
    queue.pop();
}

void TLDEDA001::HuffmanTree::BuildCodeTable(){


    traverse(root,"");

}

void TLDEDA001::HuffmanTree::traverse(std::shared_ptr<TLDEDA001::HuffmanNode> currentnode,std::string code){

std::string currCode = code;

if (currentnode.get() == nullptr) {
        return; }
    
    
    /* first recur on left child */
    traverse(currentnode->getLeft(),currCode+"0"); 
   
    /* then print the data of node */
    codeTable[currentnode->getData()] = currCode;
  
  
    /* now recur on right child */
    traverse(currentnode->getRight(),currCode+"1"); 

    
    
    

} 

   //Getter method for root
   std::shared_ptr<TLDEDA001::HuffmanNode> TLDEDA001::HuffmanTree::getRoot(){
       return this->root;
   }


void TLDEDA001::HuffmanTree::printCode(){
    for (std::pair<char, std::string> element : codeTable)
    {
        std::cout<<"KEY: "<<element.first<<" CODE: "<<element.second<<std::endl;
       
    }
}






