#include "huffman_tree.h"

bool Compare::operator()(Node *left_, Node *right_)
{
    return left_->frequency > right_->frequency;
}

Node *build_huffman_tree(const std::vector<std::pair<char, int>> &frequencies)
{
    
}

void generate_code(Node *root, std::vector<bool> way, std::unordered_map<char, std::vector<bool>> &container)
{

}

void delete_all(Node *root)
{
    
}
