#include "decompressor.h"
#include "huffman_tree.h"
#include "cstdio"
#include <cstdint>

using namespace std;

// vector<bool> read_table(ifstream &file)
// {
//     ifstream file(file, ios::binary);
//     if(!file.is_open()){
//         cerr << "can't open file for decompress";
//         return {};
//     }
//     file.seekg(0, ios::end);
//     size_t size = file.tellg();
//     file.seekg(0, ios::beg);

//     vector<char> buffer(size);
//     file.read(buffer.data(), size);

//     vector<bool> bits;
//     for(unsigned char byte: buffer){
//         for(int i = 7; i >= 0; --i){
//             bool bit = (byte >> i) & 1;
//             bits.push_back(bit);
//         }
//     }

//     return bits;
// }

unordered_map<char, vector<bool>> read_table(ifstream &file)
{
    unordered_map<char, vector<bool>> table;
    uint16_t table_size;
    char byte1, byte2;
    file.get(byte1);
    file.get(byte2);
    table_size = (static_cast<uint8_t>(byte2 << 8) | static_cast<uint8_t>(byte1));

    for(uint16_t i = 0; i < table_size; ++i){
        char symbol; 
        file.get(symbol);
        uint8_t code_length;
        file.get(reinterpret_cast<char&> (code_length));
        vector<bool> code_bits;
        int bits_read = 0;

        while(bits_read < code_length){
            char code_bytes;
            file.get(code_bytes);

            for(int g = 7; g >= 0; --i){
                bool bit = (code_bytes >> g) & 1;
                code_bits.push_back(bit);
                ++bits_read;
            }
        }
        table[symbol] = code_bits;
    }
    
    return table;
}

vector<bool> read_compress(ifstream &file)
{
    streampos current_pos = file.tellg();
    file.seekg(0, ios::end);
    size_t size = file.tellg() - current_pos;
    file.seekg(current_pos);
    vector<char> bufffer(size);
    file.read(bufffer.data(), size);

    vector<bool> bits;

    for(unsigned char byte: bufffer){
        for(int i = 7; i >= 0; --i){
            bool bit = (byte >> i) & 1;
            bits.push_back(bit);
        }
    }
    return bits;
}

vector<char> decode_data(const unordered_map<char, vector<bool>> &codes, const vector<bool> &compress_bits)
{
    
}
