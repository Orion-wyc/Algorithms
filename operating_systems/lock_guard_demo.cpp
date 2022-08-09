#include <unistd.h>

#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>

std::mutex mtx;

/* 这里lock_guard的简单实现 */
template <typename MUTEX>
class LockGuard {
 public:
  // 在 std::mutex 的定义中，下面两个函数被删除了
  // mutex(const mutex&) = delete;
  // mutex& operator=(const mutex&) = delete;
  // 因此这里必须传递引用
  explicit LockGuard(MUTEX &mtx) : mtx_(mtx) { mtx_.lock(); }
  ~LockGuard() { mtx_.unlock(); }

 private:
  MUTEX &mtx_;
  // 不可赋值，不可拷贝
  LockGuard(const MUTEX &mtx) = delete;
  LockGuard &operator=(const MUTEX &mtx) = delete;
};

void print_even(int x) {
  if (x % 2 == 0)
    std::cout << x << " is even\n";
  else
    throw(std::logic_error("not even"));
}

void print_thread_id(int id) {
  try {
    // using a local lock_guard to lock mtx guarantees unlocking on destruction
    // / exception:
    LockGuard<std::mutex> lck(mtx);
    if (id == 1) sleep(2);
    print_even(id);
  } catch (std::logic_error &) {
    std::cout << "[exception caught]\n";
  }
}

int main() {
  std::thread threads[10];
  // spawn 10 threads:
  for (int i = 0; i < 10; ++i) threads[i] = std::thread(print_thread_id, i +
  1);

  for (auto &th : threads) th.join();

  return 0;
}


// // 两个子线程共享的全局变量
// int kData = 0;

// // std::mutex 提供了一种防止共享数据被多个线程并发访问的简单同步方法
// // 调用线程可以通过 lock 和 try_lock 来获取互斥量，使用 unlock() 释放互斥量
// std::mutex kMutex;

// void increment() {
//   // 1.创建一个互斥量的包装类，用来自动管理互斥量的获取和释放
//   // std::lock_guard<std::mutex> lock(kMutex);

//   // 2.原生加锁
//   // kMutex.lock();

//   // 3.自己实现的 std::mutex 的包装类
// LockGuard<std::mutex> lock(kMutex);

//   for (int i = 0; i < 10; i++) {
//     // 打印当前线程的 id : kData
//     std::cout << std::this_thread::get_id() << ":" << kData++ << std::endl;
//     sleep(1);
//   }

//   // 2. 原生解锁
//   // kMutex.unlock();

//   // 离开局部作用域，局部锁解锁，释放互斥量
// }

// int main() {
//   // 打印当前函数名
//   std::cout << __FUNCTION__ << ":" << kData << std::endl;

//   // 开启两个线程
//   std::thread t1(increment);
//   std::thread t2(increment);

//   // 主线程等待这两个线程完成操作之后再退出
//   t1.join();
//   t2.join();

//   // 防止立刻退出
//   getchar();
//   return 0;
// }
