#include "secondary.h"
#include <cmath>

using std::cout;
const double eps = 1e-6;

LinkedList::LinkedList(){
    size_ = 0;
    head = nullptr;

}
bool LinkedList::add_at(int pos, double a){
    if(pos > size_){return false;}
    if(head == nullptr){
        head = new Node{a};
        size_++;
        return true;
    }
    if(pos == 0){
        Node* newnode = new Node {a, head};
        head->prev = newnode;
        head = newnode;
        size_++;
    }

    Node* node = head;
    for(int i = 0; i < pos - 1; ++i){
        node = node->next;
    }

    Node* newnode = new Node{a, node->next, node};
    node->next = newnode;
    if(newnode->next != nullptr){
        newnode->next->prev = newnode;
    }
    size_++;
    return true;
}
string LinkedList::to_string(){
    string str = "";
    if(size_ == 0){
        return "empty";
    }
    for(Node* i = head; i != nullptr; i = i->next){
        str += std::to_string(i->a) + " ";
    }
    return str;
}
bool LinkedList::remove_value(double a){
    Node* node = head;
    while(std::abs(node->a - a) > eps){
        node = node->next;
        if(node == nullptr){
            return false;
        }
    }
    if(node == head){
        head = node->next;
        head->prev == nullptr;
        delete node;
        return true;
    }

    node->prev->next = node->next;
    
    if(node->next != nullptr){
        node->next->prev = node->prev;
    }
    delete node;
    return true;
}
void LinkedList::clear(){
    auto current = head;

    while(head != nullptr){
        auto temp = head;
        head = head->next;
        delete temp;
    }
    size_ = 0;
    
}
LinkedList::~LinkedList(){
    clear();
}
LinkedList& LinkedList::operator=(LinkedList& other){
    if(this == &other){
        return *this;
    }
    if(!other.head){
        return *this;
    }

    auto other_current = other.head;
    auto this_current = this->head = new Node{other_current->a};
    other_current = other_current->next;
    while(other_current != nullptr){
        this_current->next = new Node{other_current->a};
        this_current->next->prev = this_current;
        other_current = other_current->next;
        this_current = this_current->next;
    }
    size_ = other.size_;
    return *this;
}
LinkedList::LinkedList(LinkedList& other){
    *this = other;
}