#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<char> binary_read_func(const std::string& filepath);

std::vector<int> build_frequency_table(const std::vector<char>& data);

std::vector<std::pair<char, int>> prepare_frequencies(const std::vector<int>& frequencies);
