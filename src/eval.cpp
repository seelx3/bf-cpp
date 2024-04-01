#include "eval.hpp"
#include <iostream>
#include <stack>

void eval(std::vector<Instruction> instrs) {
  std::vector<int> memory(1000, 0);
  int ptr = 500;
  int pc = 0;
  std::stack<int> loop_stack;

  while (pc < instrs.size()) {
    switch (instrs[pc].op) {
    case Op::MOVE_RIGHT:
      ptr++;
      break;
    case Op::MOVE_LEFT:
      ptr--;
      break;
    case Op::INCREMENT:
      memory[ptr]++;
      break;
    case Op::DECREMENT:
      memory[ptr]--;
      break;
    case Op::OUTPUT:
      std::cout << (char)memory[ptr];
      break;
    case Op::LOOP_START:
      if (memory[ptr] == 0) {
        int cnt = 1;
        while (cnt != 0) {
          pc++;
          if (instrs[pc].op == Op::LOOP_START) {
            cnt++;
          } else if (instrs[pc].op == Op::LOOP_END) {
            cnt--;
          }
        }
      } else {
        loop_stack.push(pc);
      }
      break;
    case Op::LOOP_END:
      if (memory[ptr] != 0) {
        pc = loop_stack.top();
      } else {
        loop_stack.pop();
      }
      break;
    default:
      break;
    }
    pc++;
  }
}
