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

    return min_cluster.top();
}

void generate_code(Node *root, std::vector<bool> way, std::unordered_map<char, std::vector<bool>> &container)
{
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        container[root->letter] = way;
        return;
    }
    if(root->left){
        std::vector<bool> left_way = way;
        left_way.push_back(false);
        generate_code(root->left, left_way, container);
    }
    if(root->right){
        std::vector<bool> right_way = way;
        right_way.push_back(true);
        generate_code(root->right, right_way, container);
    }
}

void delete_all(Node *root)
{
    if(!root){
        return;
    }
    delete_all(root->left);
    delete_all(root->right);
    delete root;
}
