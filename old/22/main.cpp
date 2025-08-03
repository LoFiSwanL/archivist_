#include <iostream>

using namespace std;

class Tree{
    struct TrieNode{
        int value;
        TrieNode* left = nullptr;
        TrieNode* right = nullptr;
        bool isEndOfNumber;
    };
    TrieNode* root = nullptr;
    void insert(TrieNode* node, int value){
        if(value == 1){
            if(node->right != nullptr){
                insert(node->right, value);
            }
            else{
                node->right = new TrieNode{value};
            }
        }
        else if(value == 0){
            if(node->left != nullptr){
                insert(node->left, value);
            }
            else{
                node->left = new TrieNode{value};
            }
        }
    }
    string to_string(TrieNode* node){
        string str;
        if(node->left != nullptr){
            str += to_string(node->left) + " ";
        }
        str += std::to_string(node->value);
        if(node->right != nullptr){
            str += " " + to_string(node->right);
        }
        return str;
    }
public:
    string to_string(){
        if(root == nullptr){
            return "empty";
        }
        else{
            return to_string(root);
        }
    }
    void add(int numb){
        if(root == nullptr){
            root = new TrieNode{numb};
        }
        else{
            insert(root, numb);
        }
    }

};

int main(){
    Tree tree;
    tree.add(0);
    tree.add(1);
    tree.add(0);
    tree.add(1);
    
    std::cout << tree.to_string() << std::endl;
    return 0;
}
