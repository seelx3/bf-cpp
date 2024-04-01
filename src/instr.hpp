#pragma once

enum class Op {
  MOVE_RIGHT,
  MOVE_LEFT,
  INCREMENT,
  DECREMENT,
  OUTPUT,
  LOOP_START,
  LOOP_END,
};

struct Instruction {
  Op op;
  int count;

  Instruction() : count(1) {}
};

Instruction new_instruction(char bf_instr_raw);