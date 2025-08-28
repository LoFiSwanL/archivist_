#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>

struct Node{
    char letter;
    int frequency;
    Node* left;
    Node* right;
    Node(char letter, int frequency) : letter(letter), frequency(frequency), left(nullptr), right(nullptr) {}
    Node(char letter, int frequency, Node* left, Node* right) : letter(letter), frequency(frequency), left(left), right(right) {}
};

struct Compare{
    bool operator()(Node* left_, Node* right_);
};

Node* build_huffman_tree(const std::vector<std::pair<char, int>>& frequencies);

void generate_code(Node* root, std::vector<bool> way, std::unordered_map<char, std::vector<bool>>& container);

void delete_all(Node* root);