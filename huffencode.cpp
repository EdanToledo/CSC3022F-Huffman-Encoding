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

using namespace std;

int main(int argc, char *argv[])
{

    if (argc <= 3 || argc >= 5)
    {
        cout << "Not enough arguments were entered" << endl;
        return 0;
    }
   
    string inputfile, outputfile;
    inputfile = (string)argv[2];
    outputfile = (string)argv[3];
    TLDEDA001::HuffmanTree huff;
   
    if ((std::string)argv[1]=="-c")
    {
      
    huff.BuildHuffmanTree(inputfile);
   
    huff.Compress(inputfile, outputfile);

    }else if((std::string)argv[1]=="-d"){
        
        huff.Decompress(inputfile+".bin",outputfile,inputfile+".hdr");

    }
    



    return 0;
}