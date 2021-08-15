#ifndef _HASH_HPP_
#define _HASH_HPP_

#include <functional>
#include <string>
#include <cmath>
#include <utility>
#include <vector>
#include "list.hpp"

namespace ll {

namespace algorithm {

template <typename Type>
using hasher = std::function<size_t (Type)>;

template <typename Type>
struct Hash {};

template <>
struct Hash<int> {
  size_t operator() (int data) {
    return data;
  }
};

template <>
struct Hash<char> {
  size_t operator() (char data) {
    return data;
  }
};

template <>
struct Hash<std::string&> {
  size_t operator() (std::string& data) {
    size_t sum = 0;
    for (auto c : data) {
      sum = 5 * sum + static_cast<size_t>(c);
    }
    return sum;
  }
};

template <typename Key_Type, typename Value_Type>
class HashTable {
 public:
  HashTable (hasher<Key_Type> h = Hash<Key_Type>())
    : hash { h },
      cap { 7 },
      load_size { 0 },
      load_rate { 0 } {
    datas = std::vector<DoublyList<std::pair<Key_Type, Value_Type>>>(cap, DoublyList<std::pair<Key_Type, Value_Type>>());
  }

  virtual ~HashTable() { }

  size_t get_cap() const {
    return cap;
  }

  size_t get_size() const {
    return load_size;
  }

  double get_rate() const {
    return load_rate;
  }

  size_t count(const Key_Type& key) {
    size_t hash_value = div_hash(hash(key));
    if (search_by_key(key, datas[hash_value])) {
      return 1;
    }
    return 0;
  }

  Value_Type& operator[] (const Key_Type& key) {
    size_t hash_value = div_hash(hash(key));
    auto n = search_by_key(key, datas[hash_value]);
    if (n == nullptr) { // 找不到插入一个
      std::pair<Key_Type, Value_Type> p(key, Value_Type());
      datas[hash_value].push_front(p);
      ++load_size;
      load_rate = load_size / static_cast<double>(cap);
      if (load_rate > load_rate_max) { // 装载比例过大
        re_hash();
        return datas[div_hash(hash(key))].search(p)->data.second;
      }
      return datas[hash_value].search(p)->data.second;
    }
    return n->data.second;
  }

  void re_hash() {
    cap = get_next_capacity(cap);
    load_rate = load_size / static_cast<double>(cap);
    auto datas_tmp = std::vector<DoublyList<std::pair<Key_Type, Value_Type>>>(cap, DoublyList<std::pair<Key_Type, Value_Type>>());
    for (auto itr = datas.begin(); itr != datas.end(); ++itr) {
      for (auto n = itr->begin(); n != itr->end(); n = n->next) {
        size_t hash_value = div_hash(hash(n->data.first));
        datas_tmp[hash_value].push_front(n->data);
      }    
    }
    datas = datas_tmp;
  }

 private:
  inline bool is_prime(size_t num) noexcept {
    int sqrt_num = std::sqrt(num);
    for (int i = 2; i <= sqrt_num; ++i) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }

  inline size_t get_next_capacity(size_t cur_capacity) noexcept {
    if (cur_capacity == 2) {
      return 3;
    }
    size_t res = 0;
    for (size_t i = cur_capacity * 2; true; i++) {
      if (is_prime(i)) {
        res = i;
        break;
      } else {
        continue;
      }
    }
    return res;
  }

  DoublyNode<std::pair<Key_Type, Value_Type>>* search_by_key(const Key_Type& key, const DoublyList<std::pair<Key_Type, Value_Type>>& l) {
    for (auto node = l.begin(); node != l.end(); node = node->next) {
      if (node->data.first == key) {
        return node;
      }
    }
    return nullptr;
  }

  // 除法散列
  inline size_t div_hash(size_t hash_value) const {
    return hash_value % cap;
  }

  hasher<Key_Type> hash;
  std::vector<DoublyList<std::pair<Key_Type, Value_Type>>> datas; // 链表解决冲突
  size_t cap; // 容量
  size_t load_size; // 装载量
  double load_rate; // 装载因子

  constexpr static const double load_rate_max = 0.7;
};

}

}

#endif