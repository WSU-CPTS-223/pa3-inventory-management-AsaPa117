#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "data.hpp"

using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::string;
using std::hash; 
using std::stoi; 
using std::vector; 

template<typename value>
class HashTable
{
    private:
    int tableSize; 
    value* table;  
    double loadFactor; 
    int numElement = 0; 

    void updateTableSize();
    int hashFunction(string key);
    void updateLoad(int elements);

    /*void deleteItem(string key) 
    {
    int index = hashFunction(key);
    // Find and remove the key from the table[index] vector
    auto it = find(table[index].begin(), table[index].end(), key);
    if (it != table[index].end()) 
    {
        table[index].erase(it); // Erase the key if found
    }
    } */  

    public: 
    HashTable()
    {
        this->tableSize = 53; 
        this->loadFactor = 0; 
        table = new value[tableSize]; 

    }; 
    ~HashTable()
    {
        delete[] table; 
    }

    value* find(string target);
    void insertItem(string id, value info);
}; 


    template<typename value>
    void HashTable<value>::updateTableSize()
    {
        int newSize = 2 * tableSize, i = 0; 
        hash<string> convert; 
        value* newTable = new value[newSize]; 
        int e = 0; 

        while(i < tableSize)
        {
            if (!table[i].isEmpty()) 
            {
                string id = table[i].getUniq_Id();
                int index = convert(id) % newSize;
                int j = 0;

                while (!newTable[index].isEmpty()) //quadratic probing again for new table
                {
                    j++;
                    index = (convert(id) + j * j) % newSize;
                }

                newTable[index] = table[i];
                e++; 
            }
            i++;
        }

        delete[] table; 
        //table.swap(newTable); //update the table size and itself
        table = newTable;
        tableSize = newSize; 
        numElement = e; 
    }

    template<typename value>
    void HashTable<value>::insertItem(string id, value info)
    {
        int index = hashFunction(id);  
        int i = 0; 
        while(!table[index].isEmpty())
        {   //quadratic probing
            i++; 
            index = (hashFunction(id) + i*i) % tableSize; 
           
        }
        table[index].setUniq_Id(id);
        table[index].setData(info); 
        numElement++; 
        updateLoad(numElement); 
    }; 
    //void deleteItem(string id); 

    template<typename value>
    int HashTable<value>::hashFunction(string key)
    {
        hash<string> convert;
        return (convert(key) % tableSize); 
    }

    template<typename value>
    void HashTable<value>::updateLoad(int elements)
    {
        loadFactor = elements / double(tableSize); 
        if(loadFactor > 0.5)
        {
            updateTableSize(); 
        }
    }

    template<typename value>
    value* HashTable<value>::find(string target) //chaange datatype from data to void
    {                                           //print found and its corresponding data
        int index = hashFunction(target); 
        int i = 0; 
         while(i < tableSize)
        {
            if(table[index].isEmpty())
            {
                cout << "Not found"; 
                return nullptr; 
            }
            else if(table[index].getUniq_Id() == target)
            {
                cout << "Found"; 
                return &table[index]; 
            }
            else
            {
                i++; 
                index = (hashFunction(target) + i*i) % tableSize; 
            }
        }
        
        cout << "Not found\n"; 
        return nullptr; 
    }