#pragma once
#include <string>
#include <stack>

using std::string, std::stack;

class Tree{
    struct Node{
        int value;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* root = nullptr;
    string to_string(Node* node);
public:
    string to_string();
    void add(int numb);
    int find_next(int value);
    void add(Node* node, int value);
    int find_e(Node* node, int value);

//     class Iterator{
//     int value;
//     bool is_end;
//     Tree* tree;
// public:
//     bool operator==(const Iterator& other) const;
//     int operator*();
//     Iterator operator++();
//     Iterator(int value, bool is_end, Tree* tree);
//     };
//     Iterator begin();
//     Iterator end();
    class Iterator_deep{
        stack<Node*> st;
    public:
        bool operator==(const Iterator_deep& other) const;
        int operator*();
        Iterator_deep operator++();
        Iterator_deep(Node* node);
    };
    Iterator_deep begin();
    Iterator_deep end();
};
