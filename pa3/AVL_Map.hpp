#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "node.hpp"
#include "data.hpp"
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <stdlib.h>

using std::max;
using std::cout;
using std::cin;
using std::string;
using std::hash; 


template<typename Key, typename Value>
class AVL_Map 
{
private:
    using NodeT = Node<Key, Value>;
    NodeT* root;
    int size;

    // Balance and rotation utilities
    int balanceFactor(NodeT* node);
    void updateHeight(NodeT* node);
    NodeT* rightRotation(NodeT* node);
    NodeT* leftRotation(NodeT* node);
    NodeT* findMin(NodeT* node);
    int height(NodeT* node);
    
    void insert(NodeT*& curNode, Key key, Value& value);
    NodeT* deletion(NodeT* node, Key key);

public:
    AVL_Map(); //constructor
    ~AVL_Map(); //destructor

    void insert(Key key, Value& value);
    void deletion(Key key);

    void listInventory(string category); 

    class Iterator {
    private:
        friend class AVL_Map<Key, Value>;
        std::stack<NodeT*> Stack;
        NodeT* current;

        void pushAllLeft(NodeT* node);
        void next_Inorder();

        explicit Iterator(NodeT* root);
        Iterator(Key key, NodeT* root);

    public:
        Iterator();
        Value& operator*() const;
        Iterator& operator++();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        Key key();
    };

    // Iterator member function
    Iterator begin();
    Iterator end();
    Iterator find(Key target);
};

template<typename Key, typename Value>
AVL_Map<Key, Value>::AVL_Map() 
{
    root = nullptr;
    size = 0;
}

template<typename Key, typename Value>
AVL_Map<Key, Value>::~AVL_Map() {}

template<typename Key, typename Value>
int AVL_Map<Key, Value>::balanceFactor(NodeT* node) 
{
    return height(node->getLeftPtr()) - height(node->getRightPtr());
}

template<typename Key, typename Value>
void AVL_Map<Key, Value>::updateHeight(NodeT* node)
{
    int Lheight = height(node->getLeftPtr());
    int Rheight = height(node->getRightPtr());

    node->setHeight(1 + max(Lheight, Rheight));
}

template<typename Key, typename Value>
typename AVL_Map<Key, Value>::NodeT* AVL_Map<Key, Value>::rightRotation(NodeT* node) 
{
    NodeT* x = node->getLeftPtr();
    NodeT* T2 = x ? x->getRightPtr() : nullptr;

    x->setRightPtr(node);
    node->setLeftPtr(T2);

    updateHeight(node);
    updateHeight(x);

    return x;
}

template<typename Key, typename Value>
typename AVL_Map<Key, Value>::NodeT* AVL_Map<Key, Value>::leftRotation(NodeT* node) 
{
    NodeT* x = node->getRightPtr();
    NodeT* T2 = x ? x->getLeftPtr() : nullptr;

    x->setLeftPtr(node);
    node->setRightPtr(T2);
    updateHeight(node);
    updateHeight(x);

    return x;
}

template<typename Key, typename Value>
typename AVL_Map<Key, Value>::NodeT* AVL_Map<Key, Value>::findMin(NodeT* node) 
{
    while (node->getLeftPtr())
    {
        node = node->getLeftPtr();
    }
    return node;
}

template<typename Key, typename Value>
int AVL_Map<Key, Value>::height(NodeT* node) 
{
    return node ? node->getHeight() : 0;
}

template<typename Key, typename Value>
void AVL_Map<Key, Value>::insert(Key key, Value& value) {
    insert(root, key, value);
}

template<typename Key, typename Value>
void AVL_Map<Key, Value>::insert(NodeT*& curNode, Key key, Value& value) {
    if (curNode == nullptr) 
    {
        curNode = new NodeT(key, value);
        return;
    }

    if (key < curNode->getkey()) 
    {
        NodeT* left_temp = curNode->getLeftPtr();
        insert(left_temp, key, value);
        curNode->setLeftPtr(left_temp);
    } else if (key > curNode->getkey())
    {
        NodeT* right_temp = curNode->getRightPtr();
        insert(right_temp, key, value);
        curNode->setRightPtr(right_temp);
    }

    updateHeight(curNode);
    int balance = balanceFactor(curNode);

    // Left heavy
    if (balance > 1) {
        NodeT* l_temp = curNode->getLeftPtr();
        if (key < l_temp->getkey()) {
            curNode = rightRotation(curNode);
        } else {
            curNode->setLeftPtr(leftRotation(l_temp));
            curNode = rightRotation(curNode);
        }
    }

    // Right heavy
    if (balance < -1)
    {
        NodeT* r_temp = curNode->getRightPtr();
        if (key > r_temp->getkey()) 
        {
            curNode = leftRotation(curNode);
        } else 
        {
            curNode->setRightPtr(rightRotation(r_temp));
            curNode = leftRotation(curNode);
        }
    }
}

template<typename Key, typename Value>
void AVL_Map<Key, Value>::deletion(Key key) 
{
    root = deletion(root, key);
}

template<typename Key, typename Value>
typename AVL_Map<Key, Value>::NodeT* AVL_Map<Key, Value>::deletion(NodeT* node, Key key) {
    if (node == nullptr) 
    {
        return nullptr;
    }

    if (key < node->getkey()) 
    {
        node->setLeftPtr(deletion(node->getLeftPtr(), key));
    } 
    else if (key > node->getkey()) 
    {
        node->setRightPtr(deletion(node->getRightPtr(), key));
    } 
    else if (key == node->getkey())
    {
        //Found the node to delete
        // Logic for 1 or no child
        if (node->getLeftPtr() == nullptr || node->getRightPtr() == nullptr)
        {
            NodeT* temp = nullptr;
            if (node->getLeftPtr() != nullptr)
            {
                temp = node->getLeftPtr();
            }
            else if (node->getRightPtr() != nullptr)
            {
                temp = node->getRightPtr();
            }

            if (temp == nullptr)
            {
                delete node;
                return nullptr;
            }
            else
            {
                node->setvalue(temp->getvalue());
                node->setkey(temp->getkey());
                node->setLeftPtr(temp->getLeftPtr());
                node->setRightPtr(temp->getRightPtr());
                delete temp;
            }

        }
        else
        {
            //logic to replace with a inorder successor 
            NodeT* temp = findMin(node->getRightPtr());
            node->setkey(temp->getkey());
            node->setvalue(temp->getvalue());
            node->setRightPtr(deletion(node->getRightPtr(), temp->getkey()));
        }
    }

    if (!node)
    {
        return nullptr;
    }

    //update height of current node
    updateHeight(node);
    int balance = balanceFactor(node);

    //Left heavy
    if (balance > 1 && balanceFactor(node->getLeftPtr()) >= 0)
    {
        return rightRotation(node);
    }
    //Left Right Heavy
    if (balance > 1 && balanceFactor(node->getLeftPtr()) < 0)
    {
        node->setLeftPtr(leftRotation(node->getLeftPtr()));
        return rightRotation(node);
    }
    //Right heavy
    if (balance < -1 && balanceFactor(node->getRightPtr()) <= 0)
    {
        return leftRotation(node);
    }

    //Right Left Heavy
    if (balance < -1 && balanceFactor(node->getRightPtr()) > 0)
    {
        node->setRightPtr(rightRotation(node->getRightPtr()));
        return leftRotation(node);
    }

    return node;
}


template<typename Key, typename Value>
AVL_Map<Key, Value>::Iterator::Iterator()
{
    current = nullptr; 
}

template<typename Key, typename Value>
AVL_Map<Key, Value>::Iterator::Iterator(NodeT* root)
{
    current = nullptr;
    pushAllLeft(root);
    next_Inorder();
}

template<typename Key, typename Value>
AVL_Map<Key, Value>::Iterator::Iterator(Key key, NodeT* root)
{
    NodeT* temp = root;
    current = nullptr;

        while (temp != nullptr)
        {
            Stack.push(temp);
            if (temp->getkey() == key)
            {
                current = temp;
                return;
            }
            
            //update node to the next
            if (temp->getkey() > key)
            {
                temp = temp->getLeftPtr();
            }
            else if (temp->getkey() < key)
            {
                temp = temp->getRightPtr();
            }
        }

        while (!Stack.empty())
        {
            Stack.pop(); //empty list 
        }

        current = nullptr;
}

template<typename Key, typename Value>
void AVL_Map<Key, Value>::Iterator::pushAllLeft(NodeT* node)
{
    while (node) 
    {
        Stack.push(node);
        node = node->getLeftPtr();
    }
}

template<typename Key, typename Value>
void AVL_Map<Key, Value>::Iterator::next_Inorder() 
{
    if (Stack.empty()) 
    {
        current = nullptr;
        return;
    }
    NodeT* node = Stack.top(); 
    Stack.pop();

    current = node;
    if (node->getRightPtr()) 
    {
        pushAllLeft(node->getRightPtr());
    }
}

template<typename Key, typename Value>
Value& AVL_Map<Key, Value>::Iterator::operator*() const 
{
    return current->getvalue();
}

template<typename Key, typename Value>
typename AVL_Map<Key, Value>::Iterator& AVL_Map<Key, Value>::Iterator::operator++() 
{
    next_Inorder();
    return *this;
}

template<typename Key, typename Value>
bool AVL_Map<Key, Value>::Iterator::operator==(const Iterator& other) const 
{
    return current == other.current;
}

template<typename Key, typename Value>
bool AVL_Map<Key, Value>::Iterator::operator!=(const Iterator& other) const 
{
    return current != other.current;
}

template<typename Key, typename Value>
Key AVL_Map<Key, Value>::Iterator::key() 
{
    return current ? current->getkey() : Key();
}

template<typename Key, typename Value>
typename AVL_Map<Key, Value>::Iterator AVL_Map<Key, Value>::begin() 
{
    return Iterator(root);
}

template<typename Key, typename Value>
typename AVL_Map<Key, Value>::Iterator AVL_Map<Key, Value>::end() 
{
    return Iterator(nullptr);
}

template<typename Key, typename Value>
typename AVL_Map<Key, Value>::Iterator AVL_Map<Key, Value>::find(Key target) 
{
    return Iterator(target, root);
}

template<typename Key, typename Value>
void AVL_Map<Key, Value>::listInventory(string category)
{
    Iterator strt = begin(); 
    bool found = false; 

    while(strt != end())
    {
        string cat = (*strt).getCategory(); 
        char line[500]; 
        strcpy(line, cat.c_str()); 

        char* token = strtok(line, "|"); 
        while(token != nullptr)
        {
            string single_cat = token; 
            //need to trim spaces from data (category) ... | .... | .....
            while (!single_cat.empty() && (single_cat.front() == ' ' || single_cat.front() == '\r' || single_cat.front() == '\n')) //front
            {
                single_cat.erase(single_cat.begin());
            }
            while (!single_cat.empty() && (single_cat.back() == ' '|| single_cat.back() == '\r' || single_cat.back() == '\n')) //back
            {
                single_cat.pop_back();
            }


            if(single_cat == category)
            {
                found = true; 
                if(found)
                { cout << "\nCategory Exist\n"; }
                cout << "Uniq_ID:" << (*strt).getUniq_Id() << "\n"; 
                cout << "Product Name:" << (*strt).getProduct_Name() << "\n";
            }

           token = strtok(nullptr, "|"); 
        }

        ++strt;
    }

    if(!found)
    {cout << "\nInvalid Category\n";}
   
}


