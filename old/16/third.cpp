// #include "secondary.h"
// #include <stdexcept>

// bool Tree::Iterator::operator==(const Iterator& other) const{
//     return tree==other.tree && 
//     ((is_end && other.is_end) || (!is_end && !other.is_end && value == other.value));
// }
// int Tree::Iterator::operator*(){
//     return value;
// }
// Tree::Iterator Tree::Iterator::operator++(){
//     try{
//        value = tree->find_next(value);
//     }
//     catch(std::invalid_argument){
//         is_end = true;
//     }
//     return *this;
// }
// Tree::Iterator::Iterator(int value, bool is_end, Tree* tree){
//     this->value = value;
//     this->tree = tree;
//     this->is_end = is_end;
// }
// Tree::Iterator Tree::begin(){
//     Node* node = root;
//     if(node == nullptr){
//         return end();
//     }
//     while(node && node->left){
//         node = node->left;

//     }
//     return Iterator(node->value, false, this);
// }
// Tree::Iterator Tree::end(){
//     return Iterator(0, true, this);
// }