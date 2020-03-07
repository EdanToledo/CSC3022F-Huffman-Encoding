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

using namespace std;

int main(int argc, char *argv[])
{

    if (argc < 3 || argc > 3)
    {
        cout << "Not enough arguments were entered" << endl;
        return 0;
    }
    string inputfile, outputfile;
    std::unordered_map<char,int> freq;

    inputfile = (string)argv[1];
    outputfile = (string)argv[2];

    ifstream inputstream(inputfile);
    string line;
    while (getline(inputstream,line))
    {
       for (int i = 0; i < line.length(); i++)
       {

           if (freq.find(line.at(i))==freq.end())
           {
              std::pair<char,int> mypair(line.at(i),1);
               freq.insert(mypair);
           }else{
                freq.at(line.at(i)) += 1;
           }
        
       }
        
    }
    



    return 0;
}