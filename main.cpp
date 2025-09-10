#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "compressor.h"
#include "huffman_tree.h"
#include "decompressor.h"

using namespace std;

long get_file_size(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    if (!file.is_open()) return -1;
    return file.tellg();
}

int main() {
    string input_file = "F:/C_++/file.txt";
    string output_file = "F:/C_++/file.huff";



    long size_before = get_file_size(input_file);
    if (size_before >= 0){
        cout << "Original file size: " << size_before << " bytes\n";
    }


    vector<char> data = binary_read_func(input_file);
    if (data.empty()) {
        cerr << "Input file is empty or cannot be read" << endl;
        return 1;
    }

    vector<int> freq = build_frequency_table(data);
    vector<pair<char,int>> freq_pairs = prepare_frequencies(freq);

    Node* root = build_huffman_tree(freq_pairs);

    unordered_map<char, vector<bool>> codes;
    generate_code(root, {}, codes);

    write_compress_words(output_file, codes, data);
    cout << "Compression finished. Output written to: " << output_file << endl;



    long size_compressed = get_file_size(output_file);
    if (size_compressed >= 0)
        cout << "Compressed file size: " << size_compressed << " bytes\n";



    delete_all(root);

    string input_file_for_decompress = output_file;
    string output_file_for_decompress = "F:/C_++/decompressed.txt";

    decompress_file(input_file_for_decompress, output_file_for_decompress);
    cout << "\nDecompression done. Output written to: " << output_file_for_decompress << endl;


    
    long size_after = get_file_size(output_file_for_decompress);
    if (size_after >= 0)
        cout << "Decompressed file size: " << size_after << " bytes\n";

    return 0;
}
