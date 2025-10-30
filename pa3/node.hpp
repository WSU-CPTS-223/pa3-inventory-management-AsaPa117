#pragma once

#include <iostream> // input output operations; cout cin
#include <fstream>
#include <string>
#include <cstdlib>
#include <stack>
#include "data.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;
using std::stack;

template <typename Key, typename Value>
class Node
{
private:
    Key key;
    int height;
    Value value;
    Node* mpLeft,
        * mpRight;

public:

    //default constructor
    Node();
    //full constructor 
    Node(Key nKey, Value& nValue);

    //getters
    Key getkey();
    Value& getvalue();
    Node* getLeftPtr();
    Node* getRightPtr();
    int getHeight();

    //setters
    void setkey(Key nKey);
    void setvalue(Value& nValue);
    void setLeftPtr(Node* newLeftPtr);
    void setRightPtr(Node* newRightPtr);
    void setHeight(int nHeight);
};

template<typename Key, typename Value>
Node<Key, Value>::Node()
{
    key = 0;
    height = 1;
    mpLeft = nullptr;
    mpRight = nullptr;

}

template<typename Key, typename Value>
Node<Key, Value>::Node(Key nKey, Value& nValue)
{
    this->key = nKey;
    this->height = 1;
    value = nValue;
    mpLeft = nullptr;
    mpRight = nullptr;
}

template<typename Key, typename Value>
Key Node<Key,Value>::getkey()
{
    return this->key;
}

template<typename Key, typename Value>
Value& Node<Key,Value>::getvalue()
{
    return value;
}

template<typename Key, typename Value>
void Node<Key,Value>::setkey(Key nKey)
{
    key = nKey;
}

template<typename Key, typename Value>
void Node<Key,Value>::setvalue(Value& nValue)
{
    value = nValue;
}

template<typename Key, typename Value>
void Node<Key,Value>::setLeftPtr(Node* newLeftPtr)
{
    this->mpLeft = newLeftPtr;
}

template<typename Key, typename Value>
void Node<Key,Value>::setRightPtr(Node* newRightPtr)
{
    this->mpRight = newRightPtr;
}

template<typename Key, typename Value>
Node<Key,Value>* Node<Key,Value>::getLeftPtr()
{
    return mpLeft;
}

template<typename Key, typename Value>
Node<Key,Value>* Node<Key,Value>::getRightPtr()
{
    return mpRight;
}

template<typename Key, typename Value>
int Node<Key,Value>::getHeight()
{
    return this->height;
}

template<typename Key, typename Value>
void Node<Key,Value>::setHeight(int nHeight)
{
    this->height = nHeight;
}