#pragma once
#include <iostream>
#include <string>

using std::string;

class LinkedList
{
    struct Node
    {
        double a;

        Node* next;
        Node* prev;

    };
    Node* head;
    int size_;
public:
    LinkedList();
    LinkedList(LinkedList& other);
    ~LinkedList();
    LinkedList& operator=(LinkedList& other);
    bool add_at(int pos, double a);
    bool remove_value(double a);
    void clear();
    string to_string();

};