#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map<char, std::vector<bool>> read_table(std::ifstream &file);

std::vector<bool> read_compress(std::ifstream &file);

std::vector<char> decode_data(const std::unordered_map<char, std::vector<bool>> &codes, const std::vector<bool> &compress_bits);

void decompress_file(const std::string &input_filepath, std::string &output_filepath);