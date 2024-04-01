#pragma once

#include "instr.hpp"
#include <string>
#include <vector>

std::vector<Instruction> parse_instructions(std::string bf_code);