#include "instr.hpp"

Instruction new_instruction(char bf_instr_raw) {
  Instruction instr;
  switch (bf_instr_raw) {
  case '>':
    instr.op = Op::MOVE_RIGHT;
    break;
  case '<':
    instr.op = Op::MOVE_LEFT;
    break;
  case '+':
    instr.op = Op::INCREMENT;
    break;
  case '-':
    instr.op = Op::DECREMENT;
    break;
  case '.':
    instr.op = Op::OUTPUT;
    break;
  case '[':
    instr.op = Op::LOOP_START;
    break;
  case ']':
    instr.op = Op::LOOP_END;
    break;
  default:
    break;
  }
  return instr;
}