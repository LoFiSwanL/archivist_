#pragma once
#include <initializer_list>

//Itsko Andrii K-16
//var 6

class MyStruct{
public:
    using value_type = long long;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = std::size_t;
private:
    struct Node{
        static const size_type BLOCK_SIZE = 16;
        value_type data[BLOCK_SIZE];
        bool is_deleted[BLOCK_SIZE] = {};
        size_type count = 0;

        Node* next = nullptr;
        Node* prev = nullptr;
        Node(){
            for (int i = 0; i < BLOCK_SIZE; ++i) {
                is_deleted[i] = true;
            }
        }
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    size_type size_ = 0;
    size_type capacity_ = 0;

    void compact_node(Node* node);
    
    template<typename NodeType>
    static NodeType* Node_Templ(NodeType* node, size_type& index);
    void moving(MyStruct&& other) noexcept;
    void shift_right(Node* node, size_type from, size_type to);
    void shift_left(Node* node, size_type from, size_type to);

public:
    class iterator{
        friend class MyStruct;
    private:
        Node* node = nullptr;
        size_type index = 0;
    public:
        using value_type = MyStruct::value_type;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using pointer = value_type*;
        
        iterator() = default;
        iterator(Node* node, size_type index);
        reference operator*();
        pointer operator->();
        iterator& operator++();
        iterator operator++(int);
        operator bool() const noexcept{ return node != nullptr;}
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
    };
    class const_iterator{
        friend class MyStruct;
        private:
        const Node* node = nullptr;
        size_type index = 0;
    public:
        using value_type = MyStruct::value_type;
        using difference_type = std::ptrdiff_t;
        using reference = const_reference;
        using pointer = const value_type*;
        
        const_iterator() = default;
        const_iterator(const Node* node, size_type index);
        reference operator*() const;
        pointer operator->() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        operator bool() const noexcept{ return node != nullptr;}
        bool operator==(const const_iterator& other) const;
        bool operator!=(const const_iterator& other) const;
    };
    
    MyStruct();
    MyStruct(std::initializer_list<value_type> constructor);
    MyStruct(const MyStruct& other);
    MyStruct(MyStruct&& other) noexcept;
    MyStruct& operator=(const MyStruct& other);
    MyStruct& operator=(MyStruct&& other) noexcept;
    ~MyStruct();

    size_type size() const;
    size_type capacity() const;
    bool empty() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    const_iterator begin() const;
    const_iterator end() const;
    iterator begin();
    iterator end();
    void insert(iterator pos, const_reference value);
    void push_back(const_reference value);
    void push_front(const_reference value);
    void pop_back();
    void pop_front();
    reference front();
    reference back();
    iterator erase(iterator pos);
    void clear() noexcept;
    void shrink_to_fit();
};