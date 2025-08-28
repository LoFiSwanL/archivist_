#include "huffman_tree.h"

bool Compare::operator()(Node *left_, Node *right_)
{
    return left_->frequency > right_->frequency;
}

Node *build_huffman_tree(const std::vector<std::pair<char, int>> &frequencies)
{
    std::priority_queue<Node*, std::vector<Node*>, Compare> min_cluster;

    for (auto& p: frequencies){
        min_cluster.push(new Node(p.first, p.second));
    }

    while(min_cluster.size() > 1){
        Node* left = min_cluster.top();
        min_cluster.pop();
        Node* right = min_cluster.top();
        min_cluster.pop();

        Node* parent = new Node('\0', left->frequency + right->frequency, left, right);

        min_cluster.push(parent);
    }
}

void generate_code(Node *root, std::vector<bool> way, std::unordered_map<char, std::vector<bool>> &container)
{

}

void delete_all(Node *root)
{

}
