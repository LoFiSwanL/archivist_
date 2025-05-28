#pragma once
#include <iostream>

using std::ostream;

struct TreeNode{
    int value;
    TreeNode* left_child;
    TreeNode* right_child;

};
ostream& operator<<(ostream& os, TreeNode* tree);
bool is_in_tree(TreeNode* tree, int value);
int max_depth(TreeNode* tree);
int count_leafs(TreeNode* tree);
void delete_tree(TreeNode* tree);