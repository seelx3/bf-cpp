#include "eval.hpp"
#include <iostream>
#include <stack>

class BfEvaluator {
public:
  std::vector<Instruction> instrs;
  std::vector<int> memory;
  int ptr;
  int pc;
  std::stack<int> loop_stack;

  BfEvaluator(std::vector<Instruction> instrs)
      : instrs(instrs), memory(1000, 0), ptr(500), pc(0) {
    memory = std::vector<int>(1000, 0);
    loop_stack = std::stack<int>();
  }

  void move_right(int count) { ptr += count; }
  void move_left(int count) { ptr -= count; }

  void increment(int count) { memory[ptr] += count; }
  void decrement(int count) { memory[ptr] -= count; }

  void output() { std::cout << (char)memory[ptr]; }

  void loop_start() {
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
  }

  void loop_end() {
    if (memory[ptr] != 0) {
      pc = loop_stack.top();
    } else {
      loop_stack.pop();
    }
  }

  void evaluate() {
    while (pc < instrs.size()) {
      switch (instrs[pc].op) {
      case Op::MOVE_RIGHT:
        move_right(instrs[pc].count);
        break;
      case Op::MOVE_LEFT:
        move_left(instrs[pc].count);
        break;
      case Op::INCREMENT:
        increment(instrs[pc].count);
        break;
      case Op::DECREMENT:
        decrement(instrs[pc].count);
        break;
      case Op::OUTPUT:
        output();
        break;
      case Op::LOOP_START:
        loop_start();
        break;
      case Op::LOOP_END:
        loop_end();
        break;
      default:
        break;
      }
      pc++;
    }
  }
};

void eval(std::vector<Instruction> instrs) {
  BfEvaluator bf_eval(instrs);
  bf_eval.evaluate();
}