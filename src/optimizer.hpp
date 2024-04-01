#pragma once
#include "instr.hpp"
#include <vector>

std::vector<Instruction> optimize(std::vector<Instruction> instrs);
std::vector<Instruction> optimize_run_length(std::vector<Instruction> instrs);