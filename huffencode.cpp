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

    if (argc <= 2 || argc >= 4)
    {
        cout << "Not enough arguments were entered" << endl;
        return 0;
    }
    string inputfile, outputfile;
    std::unordered_map<char,int> freq;

    inputfile = (string)argv[1];
    outputfile = (string)argv[2];

    ifstream inputstream(inputfile);
    char charac;
    while (inputstream.get(charac))
    {
        
             freq[charac] = freq[charac]+1;
        

        
      
    }
    
    

    TLDEDA001::HuffmanTree huff;
     
    huff.BuildHuffmanTree(freq);
    huff.Compress(inputfile,outputfile);
    huff.Decompress(outputfile+".bin","Decompressed");

    return 0;
}