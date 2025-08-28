#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
    char letter;
    int frequency;
    Node* left;
    Node* right;
    Node(char letter, int frequency) : letter(letter), frequency(frequency), left(nullptr), right(nullptr) {}
    Node(char letter, int frequency, Node* left, Node* right) : letter(letter), frequency(frequency), left(left), right(right) {}
};

struct Compare{
    bool operator()(Node* left_, Node* right_){
        return left_->frequency > right_->frequency;
    }
};