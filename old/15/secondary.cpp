#include "secondary.h"

ostream& operator<<(ostream& os, TreeNode* tree){
    if (tree == nullptr) {
        return os;
    }
    os << tree->value;
    if (tree->left_child) os << " " << tree->left_child;
    if (tree->right_child) os << " " << tree->right_child;
    return os;
}

bool is_in_tree(TreeNode* tree, int value){
    if(tree->value == value){
        return true;
    }
    if(tree->left_child && is_in_tree(tree->left_child, value)){
            return true;
    }
    if(tree->right_child && is_in_tree(tree->right_child, value)){
        return true;
    }
    return false;
}
int max_depth(TreeNode* tree){
    int max_depth_right = 0;
    int max_depth_left = 0;
    if(tree->left_child == nullptr && tree->right_child == nullptr){
        return 0;
    }
    if(tree->right_child){
        max_depth_right = max_depth(tree->right_child) + 1;
    }
    if(tree->left_child){
        max_depth_left = max_depth(tree->left_child) + 1;
    }
    return std::max(max_depth_left, max_depth_right);
}
int count_leafs(TreeNode* tree){
    int leaves = 0;
    if(tree->left_child == nullptr && tree->right_child == nullptr){
        return 1;
    }
    if(tree->left_child != nullptr){
        leaves += count_leafs(tree->left_child);
    }
    if(tree->right_child != nullptr){
        leaves += count_leafs(tree->right_child);
    }
    return leaves;
}
void delete_tree(TreeNode* tree){
    if(tree == nullptr){
        return;
    }
    delete_tree(tree->left_child);
    delete_tree(tree->right_child);
    delete tree;
}

