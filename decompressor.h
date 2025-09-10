#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>

void decompress_file(const std::string &input_filepath, const std::string &output_filepath);

std::vector<bool> unpack_bits(std::ifstream &file, uint32_t bit_count);
