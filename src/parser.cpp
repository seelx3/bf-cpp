#include "parser.hpp"

std::vector<Instruction> parse_instructions(std::string bf_code) {
  std::vector<Instruction> instructions;
  for (int i = 0; i < bf_code.size(); i++) {
    if (bf_code[i] != '>' && bf_code[i] != '<' && bf_code[i] != '+' &&
        bf_code[i] != '-' && bf_code[i] != '.' && bf_code[i] != '[' &&
        bf_code[i] != ']') {
      continue;
    }
    Instruction instr = new_instruction(bf_code[i]);
    instructions.push_back(instr);
  }
  return instructions;
}