#include <bits/stdc++.h>
using namespace std;

class bf_interpreter {
public:
  string bf_code;
  vector<int> memory;
  int ptr;
  int pc;
  stack<int> loop_stack;

  bf_interpreter(string bf_code) : bf_code(bf_code) {
    memory = vector<int>(1000, 0);
    ptr = 500;
    pc = 0;
  }

  void move_right() { ptr++; }

  void move_left() { ptr--; }

  void increment() { memory[ptr]++; }

  void decrement() { memory[ptr]--; }

  void output() { cout << (char)memory[ptr]; }

  void loop_start() {
    if (memory[ptr] == 0) {
      int cnt = 1;
      while (cnt != 0) {
        pc++;
        if (bf_code[pc] == '[') {
          cnt++;
        } else if (bf_code[pc] == ']') {
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
    while (bf_code[pc] != '\0') {
      switch (bf_code[pc]) {
      case '>':
        move_right();
        break;
      case '<':
        move_left();
        break;
      case '+':
        increment();
        break;
      case '-':
        decrement();
        break;
      case '.':
        output();
        break;
      case '[':
        loop_start();
        break;
      case ']':
        loop_end();
        break;
      default:
        break;
      }
      pc++;
    }
  }
};

int main(int argc, char *argv[]) {
  string file_path = argv[1];

  ifstream ifs(file_path);
  ifs.seekg(0, ios::end);
  int sz = ifs.tellg();
  ifs.seekg(0, ios::beg);

  vector<char> buf(sz);
  ifs.read(&buf[0], sz);

  string bf_code = string(buf.begin(), buf.end());

  bf_interpreter bf(bf_code);
  bf.evaluate();
}