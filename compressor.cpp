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
