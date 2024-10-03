#include <iostream>
#include <vector>

class Backtracer {
 public:
  // Function to push the current function name to the backtrace
  static void push(const std::string& func_name) {
    backtrace_.push_back(func_name);
  }

  // Function to pop the last function name from the backtrace
  static void pop() {
    if (!backtrace_.empty()) {
      backtrace_.pop_back();
    }
  }

  // Function to print the current backtrace
  static void print() {
    std::cout << "Backtrace:" << std::endl;
    for (int i = backtrace_.size() - 1; i >= 0; --i) {
      std::cout << "  " << backtrace_[i] << std::endl;
    }
  }

 private:
  // Static vector to store the function call stack
  static std::vector<std::string> backtrace_;
};

// Initialize the static member outside the class
std::vector<std::string> Backtracer::backtrace_;

// Macro to simplify pushing function names to the backtrace
#define PUSH_BACKTRACE Backtracer::push(__FUNCTION__)

// Macro to simplify popping function names from the backtrace
#define POP_BACKTRACE Backtracer::pop()

int func3() {
  PUSH_BACKTRACE;
  // Simulate some work
  POP_BACKTRACE;
  return 0;
}

int func2() {
  PUSH_BACKTRACE;
  func3();
  POP_BACKTRACE;
  return 0;
}

int func1() {
  PUSH_BACKTRACE;
  func2();
  POP_BACKTRACE;
  return 0;
}

int main() {
  PUSH_BACKTRACE;
  func1();
  Backtracer::print();
  POP_BACKTRACE;
  return 0;
}