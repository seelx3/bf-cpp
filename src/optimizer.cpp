#include "optimizer.hpp"
#include "instr.hpp"
#include <vector>

std::vector<Instruction> optimize(std::vector<Instruction> instrs) {
  instrs = optimize_run_length(instrs);

  return instrs;
}

std::vector<Instruction> optimize_run_length(std::vector<Instruction> instrs) {
  std::vector<Instruction> optimized_instrs;

  for (int i = 0; i < instrs.size(); i++) {
    Instruction instr = instrs[i];

    if ((instrs[i].op == Op::MOVE_LEFT || instrs[i].op == Op::MOVE_RIGHT ||
         instrs[i].op == Op::INCREMENT || instrs[i].op == Op::DECREMENT) &&
        optimized_instrs.size() > 0 && instr.op == optimized_instrs.back().op) {
      optimized_instrs.back().count += instr.count;
    } else {
      optimized_instrs.push_back(instr);
    }
  }

  return optimized_instrs;
}