#include "compressor.h"
#include "huffman_tree.h"
#include <cstdint>

using namespace std;

vector<char> binary_read_func(const string &filepath)
{
    ifstream file(filepath, ios::binary);
    if(!file.is_open()){
        cerr << "could not open file for compress" << endl;
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

vector<char> pack_bits(const vector<bool>& bits, uint32_t &bit_count)
{
    vector<char> buffer;
    uint8_t byte = 0;
    int bitPos = 0;
    bit_count = bits.size();

    for(bool b : bits){
        byte <<= 1;
        if(b) byte |= 1;
        bitPos++;
        if(bitPos == 8){
            buffer.push_back(byte);
            byte = 0;
            bitPos = 0;
        }
    }

    if(bitPos > 0){
        byte <<= (8 - bitPos);
        buffer.push_back(byte);
    }

    return buffer;
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
        uint32_t dummy;
        vector<char> packed_code = pack_bits(code, dummy);

        for(char b: packed_code){
            file.put(b);
        }
    }

    vector<bool> all_bits;
    for(char c: original_data){
        const vector<bool>& code = codes.at(c);
        all_bits.insert(all_bits.end(), code.begin(), code.end());
    }

    uint32_t bit_count = all_bits.size();
    vector<char> compressed_bytes = pack_bits(all_bits, bit_count);

    file.write(reinterpret_cast<const char*>(&bit_count), sizeof(bit_count));
    
    for(char b: compressed_bytes){
        file.put(b);
    }
    
    file.close();
}