#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "compressor.h"
#include "huffman_tree.h"

using namespace std;

int main() {
    vector<char> data = binary_read_func("F:/C_++/file.txt");

    vector<int> freq = build_frequency_table(data);

    vector<pair<char,int>> freq_pairs = prepare_frequencies(freq);

    Node* root = build_huffman_tree(freq_pairs);

    unordered_map<char, vector<bool>> codes;
    generate_code(root, {}, codes);

    cout << "Huffman codes:" << endl;
    for (auto &p : codes) {
        cout << p.first << " -> ";
        for (bool b : p.second) cout << b;
        cout << endl;
    }

    write_compress_words("F:/C_++/file.huff", codes, data);

    delete_all(root);

    return 0;
}