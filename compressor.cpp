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
