#include <iostream>
#include "decompressor.h"
#include "compressor.h"
#include "huffman_tree.h"

using namespace std;

int main(int argc, char *argv[]) {

    auto data = binary_read_func("F:/C++/file.txt");
    auto freq = build_frequency_table(data);
    auto freq_pairs = prepare_frequencies(freq);
    Node* root = build_huffman_tree(freq_pairs);
    
    return 0;
}