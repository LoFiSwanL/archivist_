#include "mystruct.h"
#include <iostream>
#include <stdexcept>

using std::initializer_list;
using namespace std;

void MyStruct::compact_node(Node* node)
{
    if(!node){
        return;
    }
    size_type index = 0;
    for(size_type curr_index = 0; curr_index < MyStruct::Node::BLOCK_SIZE; ++curr_index){
        if(!node->is_deleted[curr_index]){
            if(index != curr_index){
                node->data[index] = node->data[curr_index];
                node->is_deleted[index] = false;
                node->is_deleted[curr_index] = true;
            }
            ++index;
        }
    }
    node->count = index;
    for(size_type i = index; i < MyStruct::Node::BLOCK_SIZE; ++i){
        node->is_deleted[i] = true;
        node->data[i] = value_type{};
    }
}
template<typename NodeType>
NodeType* MyStruct::Node_Templ(NodeType* node, size_type& index) {
    ++index;
    while (node) {
        while (index < Node::BLOCK_SIZE) {
            if (!node->is_deleted[index]) {
                return node;
            }
            ++index;
        }
        node = node->next;
        index = 0;
    }
    index = 0;
    return nullptr;
}
void MyStruct::moving(MyStruct&& other) noexcept{
    head = other.head;
    tail = other.tail;
    size_ = other.size_;
    capacity_ = other.capacity_;

    other.head = nullptr;
    other.tail = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}
void MyStruct::shift_right(Node* node, size_type from, size_type to) {
    for (size_type i = from; i > to; --i) {
        node->data[i] = node->data[i - 1];
        node->is_deleted[i] = node->is_deleted[i - 1];
    }
}
void MyStruct::shift_left(Node* node, size_type from, size_type to) {
    for (size_type i = from; i < to; ++i) {
        node->data[i] = node->data[i + 1];
        node->is_deleted[i] = node->is_deleted[i + 1];
    }
}

MyStruct::iterator::iterator(Node* node, size_type index) : node(node), index(index) {}
MyStruct::reference MyStruct::iterator::operator*()
{
    if (!node || index >= MyStruct::Node::BLOCK_SIZE || node->is_deleted[index]) {
        throw out_of_range("invalid iterator");
    }
    return node->data[index];
}
MyStruct::iterator::pointer MyStruct::iterator::operator->()
{
    return &(node->data[index]);
}
MyStruct::iterator& MyStruct::iterator::operator++()
{
    node = MyStruct::Node_Templ(node, index);
    return *this;
}
MyStruct::iterator MyStruct::iterator::operator++(int)
{
    iterator temp = *this;
    ++(*this);
    return temp;
}
bool MyStruct::iterator::operator==(const iterator& other) const
{
    return node == other.node && index == other.index;
}
bool MyStruct::iterator::operator!=(const iterator& other) const
{
    return index != other.index || node != other.node;
}

MyStruct::const_iterator::const_iterator(const Node* node, size_type index) : node(node), index(index) {}
MyStruct::const_iterator::reference MyStruct::const_iterator::operator*() const
{
    return node->data[index];
}
MyStruct::const_iterator::pointer MyStruct::const_iterator::operator->() const
{
    return &(node->data[index]);
}
MyStruct::const_iterator& MyStruct::const_iterator::operator++()
{
    node = MyStruct::Node_Templ(node, index);
    return *this;
}
MyStruct::const_iterator MyStruct::const_iterator::operator++(int)
{
    const_iterator temp = *this;
    ++(*this);
    return temp;
}
bool MyStruct::const_iterator::operator==(const const_iterator& other) const
{
    return index == other.index && node == other.node;
}
bool MyStruct::const_iterator::operator!=(const const_iterator& other) const
{
    return index != other.index || node != other.node;
}


MyStruct::MyStruct() : head(nullptr), tail(nullptr) {}
MyStruct::MyStruct(std::initializer_list<value_type> constructor) : head(nullptr), tail(nullptr)
{
    for(const auto& i: constructor){
        push_back(i);
    }
}
MyStruct::MyStruct(const MyStruct& other) : head(nullptr), tail(nullptr)
{
    for(auto it = other.begin(); it != other.end(); ++it){
        push_back(*it);
    }
}
MyStruct::MyStruct(MyStruct&& other) noexcept
{
    moving(std::move(other));
}
MyStruct& MyStruct::operator=(const MyStruct& other)
{
    if(this == &other){
        return *this;
    }
    clear();

    for(const auto& i: other){
        push_back(i);
    }
    return *this;
}
MyStruct& MyStruct::operator=(MyStruct&& other) noexcept
{
    if(this != &other){
        clear();

        moving(std::move(other));
    }
    return *this;
}
MyStruct::~MyStruct()
{
    clear();
}

MyStruct::size_type MyStruct::size() const
{
    return size_;
}
MyStruct::size_type MyStruct::capacity() const
{
    return capacity_;
}
bool MyStruct::empty() const
{
    return size_ == 0;
}
MyStruct::const_iterator MyStruct::cbegin() const
{
    MyStruct::const_iterator it(head, -1);
    ++it;
    return it;
}
MyStruct::const_iterator MyStruct::cend() const
{
    return const_iterator(nullptr, 0);
}
MyStruct::const_iterator MyStruct::begin() const
{
    MyStruct::const_iterator it(head, -1);
    ++it;
    return it;
}
MyStruct::const_iterator MyStruct::end() const
{
    return cend();
}
MyStruct::iterator MyStruct::begin()
{
    MyStruct::iterator it(head, -1);
    ++it;
    return it;
}
MyStruct::iterator MyStruct::end()
{
    return iterator(nullptr, 0);
}
void MyStruct::insert(iterator pos, const_reference value)
{
    Node* node = pos.node;
    size_type index = pos.index;

    if (pos.node == nullptr) {
        push_back(value);
        return;
    }

    if (node->count < MyStruct::Node::BLOCK_SIZE) {
        size_type deleted_index = MyStruct::Node::BLOCK_SIZE;

        for (size_type i = 0; i < MyStruct::Node::BLOCK_SIZE; ++i) {
            if (node->is_deleted[i]) {
                deleted_index = i;
                break;
            }
        }

        if (deleted_index < MyStruct::Node::BLOCK_SIZE) {
            size_++;
            node->count++;

            if(deleted_index > index){
                shift_right(node, deleted_index, index);
                node->data[index] = value;
                node->is_deleted[index] = false;
            }
            else{
                shift_left(node, deleted_index, index);
                node->data[index - 1] = value;
                node->is_deleted[index - 1] = false;
            }
            return;
        }
        shift_right(node, MyStruct::Node::BLOCK_SIZE - 1, index);
        node->data[index] = value;
        node->is_deleted[index] = false;
        node->count++;
        size_++;

        return;
    }
    Node* new_node = new Node;
    size_type middle = MyStruct::Node::BLOCK_SIZE / 2;

    for(size_type i = middle; i < MyStruct::Node::BLOCK_SIZE; ++i){
        size_type new_index = i - middle;
        new_node->data[new_index] = node->data[i];
        new_node->is_deleted[new_index] = node->is_deleted[i];
        if(!node->is_deleted[i]){
            new_node->count++;
            node->count--;
        }
        node->is_deleted[i] = true;
    }
    if(index < middle){
        shift_right(node, middle, index);
        node->data[index] = value;
        node->is_deleted[index] = false;
        node->count++;
    }
    else{
        size_type new_index = index - middle;
        for(size_type i = MyStruct::Node::BLOCK_SIZE - middle - 1; i > new_index; --i){
            new_node->data[i] = new_node->data[i-1];
            new_node->is_deleted[i] = new_node->is_deleted[i-1];
        }
        new_node->data[new_index] = value;
        new_node->is_deleted[new_index] = false;
        new_node->count++;
    }
        
    size_++;

    new_node->next = node->next;
    new_node->prev = node;
    if(node->next != nullptr){
        node->next->prev = new_node;
    }
    else{
        tail = new_node;
    }
    node->next = new_node;
    capacity_ += MyStruct::Node::BLOCK_SIZE;

    shrink_to_fit();
}
void MyStruct::push_back(const_reference value)
{
    if(!tail || tail->count == MyStruct::Node::BLOCK_SIZE){
        Node* new_node = new Node;
        new_node->prev = tail;
        if(tail){
            tail->next = new_node;
        }
        if(!head){
            head = new_node;
        }
        tail = new_node;
        capacity_ += MyStruct::Node::BLOCK_SIZE;
    }
    compact_node(tail);
    for(size_type i = 0; i < MyStruct::Node::BLOCK_SIZE; ++i){
        if(tail->is_deleted[i]){
            tail->data[i] = value;
            tail->is_deleted[i] = false;
            tail->count++;
            size_++;
            return;
        }
    }
    throw std::runtime_error("push_back error");
}
void MyStruct::push_front(const_reference value)
{
    if(!head || head->count == MyStruct::Node::BLOCK_SIZE){
        Node* new_node = new Node;
        new_node->next = head;
        if(head){
            head->prev = new_node;
        }
        head = new_node;
        if(!tail){
            tail = new_node;
        }
        capacity_ += MyStruct::Node::BLOCK_SIZE;
    }
    for(size_type i = 0; i < MyStruct::Node::BLOCK_SIZE; ++i){
        if(head->is_deleted[i]){
            for(size_type g = i; g > 0; --g){
                head->data[g] = head->data[g-1];
                head->is_deleted[g] = head->is_deleted[g-1];
            }
            head->data[0] = value;
            head->is_deleted[0] = false;
            head->count++;
            size_++;
            return;
        }
    }
    size_++;
}
void MyStruct::pop_back()
{
    if(size_ == 0){
        throw out_of_range("Struct is empty");
        }
    for(int i = MyStruct::Node::BLOCK_SIZE - 1; i >= 0; --i){
        if(!tail->is_deleted[i]){
            tail->is_deleted[i] = true;
            tail->count--;
            size_--;

            shrink_to_fit();
            return;
        }
    }
    throw runtime_error("no element to delete");
}
void MyStruct::pop_front()
{
    if(empty()){
        throw out_of_range("Struct is empty");
    }
    for(int i = 0; i < MyStruct::Node::BLOCK_SIZE; ++i){
        if(!head->is_deleted[i]){
            head->is_deleted[i] = true;
            head->count--;
            size_--;

            shrink_to_fit();
            return;
            }
        }
    throw runtime_error("no element to delete");
}
MyStruct::reference MyStruct::front()
{
    Node* node = head;
    while (node) {
        for (size_type i = 0; i < Node::BLOCK_SIZE; ++i) {
            if (!node->is_deleted[i]) {
                return node->data[i];
            }
        }
        node = node->next;
    }
    throw std::out_of_range("Container is empty");
}
MyStruct::reference MyStruct::back()
{
    Node* node = tail;
    while (node) {
        for (int i = Node::BLOCK_SIZE - 1; i >= 0; --i) {
            if (!node->is_deleted[i]) {
                return node->data[i];
            }
        }
        node = node->prev;
    }
    throw std::out_of_range("Container is empty");
}
MyStruct::iterator MyStruct::erase(iterator pos)
{
    Node* node = pos.node;
    size_type index = pos.index;

    if (!node || index >= Node::BLOCK_SIZE || node->is_deleted[index]) {
        throw out_of_range("Error erase position");
    }

    node->is_deleted[index] = true;
    node->count--;
    size_--;
    Node* curr = node;
    size_type new_index = index + 1;

    while (curr) {
        while (new_index < Node::BLOCK_SIZE) {
            if (!curr->is_deleted[new_index]) {
                return iterator(curr, new_index);
            }
            ++new_index;
        }
        curr = curr->next;
        new_index = 0;
    }

    return end();
}
void MyStruct::clear() noexcept
{
    Node* curr = head;
    while(curr){
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
    size_ = 0;
    capacity_ = 0;
}

void MyStruct::shrink_to_fit()
{
    Node* curr = head;
    while(curr){
        Node* next_node = curr->next;
        if(curr->count == 0){
            if(curr->prev){
                curr->prev->next = curr->next;
            }
            else{
                head = curr->next;
            }
            if(curr->next){
                curr->next->prev = curr->prev;
            }
            else{
                tail = curr->prev;
            }
            delete curr;
            if(capacity_ >= MyStruct::Node::BLOCK_SIZE){
                capacity_ -= MyStruct::Node::BLOCK_SIZE;
            }
            else{
                capacity_ = 0;
            }
            curr = next_node;
            continue;
        }
        if(curr->next && curr->count + curr->next->count <= MyStruct::Node::BLOCK_SIZE){
            Node* merge = curr->next;
            compact_node(curr);
            compact_node(merge);

            for(size_type i = 0; i < MyStruct::Node::BLOCK_SIZE; ++i){
                if(!merge->is_deleted[i]){
                    curr->data[curr->count] = merge->data[i];
                    curr->is_deleted[curr->count] = false;
                    ++curr->count;
                }
            }
            curr->next = merge->next;

            if(merge->next){
                merge->next->prev = curr;
            } else {
                tail = curr;
            }
            delete merge;
            capacity_ -= MyStruct::Node::BLOCK_SIZE;
            continue;
        }
        curr = next_node;
    }
}