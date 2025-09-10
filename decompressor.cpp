#include "decompressor.h"
#include <cstdint>

using namespace std;

vector<bool> unpack_bits(ifstream &file, uint32_t bit_count) {
    vector<bool> bits;
    bits.reserve(bit_count);

    uint8_t byte;
    for (uint32_t i = 0; i < (bit_count + 7) / 8; ++i) {
        file.read(reinterpret_cast<char*>(&byte), 1);
        int bits_in_this_byte = min(8u, bit_count - i * 8);
        for (int j = 7; j >= 8 - bits_in_this_byte; --j) {
            bits.push_back((byte >> j) & 1);
        }
    }
    return bits;
}

void decompress_file(const string &input_filepath, const string &output_filepath) {
    ifstream file(input_filepath, ios::binary);
    if (!file.is_open()) {
        cerr << "Cannot open input file: " << input_filepath << endl;
        return;
    }

    uint16_t table_size;
    char byte1, byte2;
    file.get(byte1);
    file.get(byte2);
    table_size = (static_cast<uint8_t>(byte2) << 8) | static_cast<uint8_t>(byte1);

    unordered_map<char, vector<bool>> codes;
    for (uint16_t i = 0; i < table_size; ++i) {
        char symbol;
        file.get(symbol);

        uint8_t length;
        file.get(reinterpret_cast<char&>(length));

        vector<bool> code_bits;
        int bits_read = 0;
        while (bits_read < length) {
            char code_byte;
            file.get(code_byte);
            int bits_to_read = min(8, length - bits_read);
            for (int j = 7; j >= 8 - bits_to_read; --j) {
                code_bits.push_back((code_byte >> j) & 1);
                ++bits_read;
            }
        }
        codes[symbol] = code_bits;
    }

    uint32_t bit_count;
    file.read(reinterpret_cast<char*>(&bit_count), sizeof(bit_count));

    vector<bool> compressed_bits = unpack_bits(file, bit_count);

    vector<char> decoded_data;
    vector<bool> curr_code;
    for (bool bit : compressed_bits) {
        curr_code.push_back(bit);
        for (auto &p : codes) {
            if (p.second == curr_code) {
                decoded_data.push_back(p.first);
                curr_code.clear();
                break;
            }
        }
    }

    ofstream out(output_filepath, ios::binary);
    if (!out.is_open()) {
        cerr << "Cannot open output file: " << output_filepath << endl;
        return;
    }
    out.write(decoded_data.data(), decoded_data.size());
    out.close();
}
