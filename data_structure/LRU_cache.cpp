#include <list>
#include <unordered_map>

class LRUCache {
 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (hashTable.find(key) == hashTable.end()) {
      return -1;
    } else {
      // 更新到表头
      auto iter = hashTable[key];                // 找到对应地址
      cache.splice(cache.begin(), cache, iter);  // 移动到表头
      return cache.begin()->second;
    }
  }

  void put(int key, int value) {
    if (hashTable.find(key) == hashTable.end()) {
      if (cache.size() == capacity) {
        // 删除表尾
        hashTable.erase(cache.back().first);
        cache.pop_back();
      }
      // 在表头添加
      cache.push_front(std::make_pair(key, value));
      hashTable[key] = cache.begin();
    } else {
      auto iter = hashTable[key];
      iter->second = value;                      // 更新元素
      cache.splice(cache.begin(), cache, iter);  // 移动到表头
      hashTable[key] = cache.begin();            // 更新地址
    }
  }

 private:
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hashTable;
  std::list<std::pair<int, int>> cache;  // key, value
  int capacity = 0;
};