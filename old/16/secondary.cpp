#include "secondary.h"
#include <string>
#include <stdexcept>

using std::string;

string Tree::to_string(){
    if(root == nullptr){
        return "empty";
    }
    else{
        return to_string(root);
    }
}
string Tree::to_string(Node* node){
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
void Tree::add(int numb){
    if(root == nullptr){
        root = new Node{numb};
    }
    else{
        add(root, numb);
    }
}
void Tree::add(Node* node, int value){
    if(node->value >= value){
        if(node->left != nullptr){
            add(node->left, value);
        }
        else{
            node->left = new Node{value};
            
        }
    }
    else{
    if(node->right != nullptr){
            add(node-> right, value);
        }
        else{
            node->right = new Node{value};
        }
    }
}
int Tree::find_next(int value){
    if(root == nullptr){
        throw std::invalid_argument("No such value");
    }
    else{
        return find_e(root, value);
    }
    
}
int Tree::find_e(Node* node, int value){
    if(node->value > value){
        if(node->left == nullptr){
            return node->value;
        }
        try{
        return find_e(node->left, value);
        }
        catch(std::invalid_argument e){
            return node->value;
        }
    }
    else{
        if(node->right == nullptr){
            throw std::invalid_argument("No such value");
        }
        else{
            return find_e(node->right, value);
        }
    }
}
