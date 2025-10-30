#include <iostream>
#include <string>
#include "Data_Struct_Wrap.hpp"
using namespace std;

dataStruct Inventory; 

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") || (line.rfind("find", 0) == 0) || (line.rfind("listInventory") == 0 || (line.rfind("test") == 0));
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        string search; 
        // Look up the appropriate datastructure to find if the inventory exist
        //cout << "YET TO IMPLEMENT!" << endl;
        cout << "\nType Uniq_Id to find:"; 
        cin >> search;
        string target = search; 
        if(!target.empty())
        { Inventory.find(target);}
        else{ cout << "Error\n"; }

    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        //cout << "YET TO IMPLEMENT!" << endl;
        string search; 
        cout << "\nType Category to find:"; 
        getline(cin, search); // read full line
        string target = search; 
        if(!target.empty())
        { Inventory.listInventory(target);}
        else{cout << "Error\n"; }
    }

    //////////////////////////////////////
    //test purposes
    else if (line.rfind("test") == 0)
    {
        Inventory.test(); 
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
    
    Inventory.parseFile(); 
    //use hashtable for find: 0(1)
    //use avl. 

}

int main(int argc, char const *argv[])
{
    //In validCommand and evalCommand, I added one more input call "test" that user can test
    string line;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
