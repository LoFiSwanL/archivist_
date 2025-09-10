#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>

std::vector<char> binary_read_func(const std::string& filepath);

std::vector<int> build_frequency_table(const std::vector<char>& data);

std::vector<std::pair<char, int>> prepare_frequencies(const std::vector<int>& frequencies);

std::vector<char> pack_bits(const std::vector<bool>& bits, std::uint32_t &bit_count);

void write_compress_words(const std::string &filepath, const std::unordered_map<char, std::vector<bool>> &codes, const std::vector<char> &original_data);
