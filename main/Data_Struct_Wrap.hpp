#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string>
#include <iostream>
#include "HashTable.hpp"
#include "AVL_Map.hpp"
#include <cassert>
#include "data.hpp"

using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::string;
using std::stoi; 
using std::hash; 


class dataStruct
{ 
    private:
    HashTable <::data> struct1; 
    AVL_Map <int, ::data> struct2; 
 


    public: 
    dataStruct(); 
    ~dataStruct(); 
    void parseFile(); 
    void find(string target); 
    void listInventory(string target); 

    void test();

}; 
