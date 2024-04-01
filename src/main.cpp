#include "eval.hpp"
#include "instr.hpp"
#include "parser.hpp"
#include <fstream> // Include the necessary header file
#include <iostream>

std::string read_bf_code(std::string file_path) {
  std::ifstream ifs(file_path);
  ifs.seekg(0, std::ios::end);
  int sz = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  std::vector<char> buf(sz);
  ifs.read(&buf[0], sz);

  return std::string(buf.begin(), buf.end());
}

int main(int argc, char *argv[]) {
  std::string file_path = argv[1];

  std::string bf_code = read_bf_code(file_path);

  std::vector<Instruction> instrs = parse_instructions(bf_code);

  eval(instrs);
}