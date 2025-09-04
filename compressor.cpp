#include "compressor.h"
#include "huffman_tree.h"
#include <cstdint>

using namespace std;

vector<char> binary_read_func(const string &filepath)
{
    ifstream file(filepath, ios::binary);
    if(!file.is_open()){
        cerr << "could not open file" << endl;
        return {};
    }
    
    file.seekg(0, ios::end);
    size_t size = file.tellg();
    file.seekg(0, ios::beg);

    vector<char> buffer(size);
    file.read(buffer.data(), size);

    return buffer;
}

vector<int> build_frequency_table(const vector<char> &data)
{
    vector<int> frequencyMap(256, 0);

    for (char byte: data) {
        frequencyMap[static_cast<unsigned char>(byte)]++;
    }

    return frequencyMap;
}

vector<pair<char, int>> prepare_frequencies(const vector<int> &frequencies)
{
    vector<pair<char, int>> freq_pairs;

    for(int i = 0; i < 256; ++i){
        if(frequencies[i] > 0){
            freq_pairs.push_back({static_cast<char>(i), frequencies[i]});
        }
    }

    return freq_pairs;
}

vector<char> pack_bits(const vector<bool> &bits)
{
    vector<char> bit_buffer; 
    char current_bit = 0;
    int count_bit = 0;

    for(vector<bool>::const_iterator it = bits.cbegin(); it != bits.cend(); ++it){
        current_bit <<= 1;
        current_bit |= *it;
        count_bit += 1;
        if(count_bit == 8){
            bit_buffer.push_back(current_bit);
            current_bit = 0;
            count_bit = 0;
        }
    }
    if(count_bit > 0){
            current_bit <<= 8 - count_bit;
            current_bit |= 0;
            bit_buffer.push_back(current_bit);
            current_bit = 0;
            count_bit = 0;
        }

    return bit_buffer;
}

void write_compress_words(const string &filepath, const unordered_map<char, vector<bool>> &codes, const vector<char> &original_data)
{
    ofstream file(filepath, ios::binary);
    if(!file.is_open()){
        cerr << "could not open file" << endl;
        return;
    }

    uint16_t table_size = codes.size();
    file.put(static_cast<char>(table_size & 0xFF));
    file.put(static_cast<char>((table_size >> 8) & 0xFF));

    for(const auto &pair: codes){
        char symbol = pair.first;
        const vector<bool> &code = pair.second;
        file.put(symbol);

        uint8_t length = code.size();
        file.put(length);
        vector<char> packed_code = pack_bits(code);

        for(char b: packed_code){
            file.put(b);
        }
    }
}
