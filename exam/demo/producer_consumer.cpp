#include <bits/stdc++.h>
using namespace std;

int i = 0;
mutex mtx;
condition_variable cv;

void producer() {
  int k = 10;
  while (k--) {
    unique_lock<mutex> locker(mtx);
    if (i > 0) {
      cv.wait(locker);
    }
    ++i;
    cout << "P=" << i << endl;
    cv.notify_all();
  }
}

void consumer() {
  int k = 10;
  while (k--) {
    unique_lock<mutex> locker(mtx);
    if (i <= 0) {
      cv.wait(locker);
    }
    --i;
    cout << "C=" << i << endl;
    cv.notify_all();
  }
}

int main() {
  thread c(consumer);
  thread p(producer);

  p.join();
  c.join();
  return 0;
}