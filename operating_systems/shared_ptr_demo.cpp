#include <atomic>
#include <exception>

template <typename T>
class SmartPtr {
 private:
  T* ptr;
  atomic<int>* use_count;

 public:
  SmartPtr(T* p) : ptr(p) {
    if (!ptr) throw exception();
    use_count = new atomic<int>(1);
  }
  ~SmartPtr() {
    (*use_count)--;
    if ((*use_count) == 0) {
      if (ptr) {
        delete ptr;
        ptr = NULL;
      }
      if (use_count) {
        delete use_count;
        use_count = NULL;
      }
    }
  }
  SmartPtr(const SmartPtr& sp) {
    ptr = sp.ptr;
    use_count = sp.use_count;
    (*use_count)++;
  }
  SmartPtr& operator=(const SmartPtr& sp) {
    if (this == &sp) return *this;
    (*use_count)--;
    if ((*use_count) == 0) {
      if (ptr) {
        delete ptr;
        ptr = NULL;
      }
      if (use_count) {
        delete use_count;
        use_count = NULL;
      }
    }
    ptr = sp.ptr;
    use_count = sp.use_count;
    (*use_count)++;
    return *this;
  }
  T& operator*() { return *ptr; }
  T* operator->() { return ptr; }
  int get_use_count() { return *use_count; };
};