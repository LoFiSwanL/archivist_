#include "secondary.h"

Tree::Iterator_deep::Iterator_deep(Node* node){
    if(node != nullptr){
        st.push(node);
    }
}
int Tree::Iterator_deep::operator*(){
    return st.top() -> value;
}
Tree::Iterator_deep Tree::Iterator_deep::operator++(){
    Node* tmp = st.top();
    st.pop();
    if(tmp->right){
        st.push(tmp->right);
    }
    if(tmp->left){
        st.push(tmp->left);
    }
    return *this;
}
bool Tree::Iterator_deep::operator==(const Iterator_deep& other) const{
    if(st.empty() && other.st.empty()){
        return true;
    }
    else if(!st.empty() && !other.st.empty() && st.top() == other.st.top()){
        return true;
    }
    return false;
}
Tree::Iterator_deep Tree::begin(){
    return Iterator_deep(root);
}
Tree::Iterator_deep Tree::end(){
    return Iterator_deep(nullptr);
}