#ifndef _INTERVIEW_H_
#define _INTERVIEW_H_

#include <vector>
#include <string>
#include "handler.h"

namespace ll {

namespace algorithm {

/**
 * 最大字数组和
 */
class MaximumSubarray {
 public:
  struct Maximum { 
    Maximum(int l, int r)
      : left { l },
        right { r },
        sum { 0 } {}
    Maximum(int l, int r, int s)
      : left { l },
        right { r },
        sum { s } {}
    Maximum(const Maximum& rh) {
      left = rh.left;
      right = rh.right;
      sum = rh.sum;
    }

    std::string to_string();

    int left;
    int right;
    int sum;
  };
 public:
  MaximumSubarray(const std::vector<int>& nums);

  // 分治
  Maximum get_maximum(int l, int r);
  // DP
  Maximum get_maximum_v2();

 private:
  Maximum get_mid_sum(int l, int mid, int r);
  std::vector<int> nums;
};

/**
 * 查第K大值
 */
class FindKthNum {
 public:
  int find_kth_num(std::vector<int>::iterator start, std::vector<int>::iterator end, size_t k);
 private:
  size_t partition(std::vector<int>::iterator start, std::vector<int>::iterator end, cmp c);
};

/**
 * 找出最大最小值
 */
class GetMinAndMax {
  public:
   GetMinAndMax(const std::vector<int>& nums);
   void get_min_max(int& min, int& max);
  private:
   std::vector<int> nums;
};

} // namespace algorithm

} // namespace ll

#endif