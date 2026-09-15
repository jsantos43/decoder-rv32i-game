#ifndef MANAGE_INSTRUCTIONS_H
#define MANAGE_INSTRUCTIONS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <bitset>
#include <cstdint>
#include <random>
#include <algorithm>

bool generate_riscv_dump();
std::string get_info_from_dump_line(std::string);
std::vector<std::string> get_instructions();
std::string pick_instructions(std::vector<std::string>&);
void shuffle_instructions(std::vector<std::string>&);

#endif