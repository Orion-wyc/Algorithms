#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <unistd.h>

void print(const std::string &s, int i) {
  sleep(4 - i);
  std::cout << s << "-" << i << std::endl;
}

void test_thread_demo() {
  std::vector<std::thread> workers;
  for (int i = 0; i < 4; ++i) {
    workers.emplace_back(std::thread(print, "hello", i));
  }
  for (std::thread &th : workers) {
    th.join();
  }
}

int main() {
  test_thread_demo();
  return 0;
}

