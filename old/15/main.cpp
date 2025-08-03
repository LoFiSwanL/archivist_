#include <iostream>
#include "secondary.h"

using namespace std;

int main(){
    TreeNode* tree = new TreeNode{12};

    tree->left_child = new TreeNode(1);
    tree->right_child = new TreeNode(4);
    tree->left_child->left_child = new TreeNode(7);
    tree->left_child->right_child = new TreeNode(6);
    tree->left_child->left_child->right_child = new TreeNode(98);
    tree->right_child->left_child = new TreeNode(21);
    tree->right_child->right_child = new TreeNode(112);

    cout << tree << endl;

    cout << "\n" << is_in_tree(tree, 6) << endl;
    cout << is_in_tree(tree, 12) << endl;
    cout << is_in_tree(tree, 0) << endl;

    cout << "\n" << max_depth(tree) << endl;

    cout << "\n" << count_leafs(tree) << endl;

    tree->left_child->left_child->left_child = new TreeNode(22);
    cout << count_leafs(tree) << endl;

    cout << "\n" << tree << endl;

    delete_tree(tree->left_child->left_child);
    tree->left_child->left_child = nullptr;

    cout << "\n" << tree << endl;
}