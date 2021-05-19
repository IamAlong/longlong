#include <sstream>
#include <climits>
#include <iostream>
#include "interview.h"
#include "util.hpp"

using namespace ll::algorithm;

MaximumSubarray::MaximumSubarray(const std::vector<int>& nums)
    : nums { nums } {
}
  
std::string MaximumSubarray::Maximum::to_string() {
  std::stringstream ss;
  ss << "{ left: " << left << " right: " << right << " sum: " << sum << " }";
  return ss.str();
}

MaximumSubarray::Maximum MaximumSubarray::get_mid_sum(int l, int mid, int r) {
  Maximum res(l, r, 0);
  int sum_max = INT_MIN;
  int sum_l = 0;
  int left = mid;
  for (int i = left; i >= l; i--) {
    sum_l += nums[i];
    if (sum_l >= sum_max) {
      sum_max = sum_l;
      left = i;
    }
  }
  res.left = left;
  sum_l = sum_max;
  sum_max = INT_MIN;
  int sum_r = 0;
  int right = mid + 1;
  for (int i = right; i <= r; i++) {
    sum_r += nums[i];
    if (sum_r >= sum_max) {
      sum_max = sum_r;
      right = i;
    }
  }
  res.right = right;
  res.sum = sum_l + sum_max;
  return res;
}

MaximumSubarray::Maximum MaximumSubarray::get_maximum(int l, int r) {
  if (nums.empty()) {
    return Maximum { -1, -1, 0 };
  }
  if (r >= nums.size() || r < l) {
    r = nums.size() - 1;
  }
  if (l == r) {
    return Maximum{ l, r, this->nums[l] };
  }
  int mid = r - (r - l) / 2 - 1;
  auto left_maximum = get_maximum(l, mid);
  auto right_maximum = get_maximum(mid + 1, r);
  auto mid_maximum = get_mid_sum(l, mid, r);
  if (left_maximum.sum > mid_maximum.sum && left_maximum.sum > right_maximum.sum) {
    return left_maximum;
  } else if (right_maximum.sum > left_maximum.sum && right_maximum.sum > mid_maximum.sum) {
    return right_maximum;
  }
  return mid_maximum;
}

MaximumSubarray::Maximum MaximumSubarray::get_maximum_v2() {
  if (nums.empty()) {
    return Maximum { -1, -1, 0 };
  }
  Maximum res { 0, nums.size() - 1, INT_MIN };
  int sum = 0;
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    count++;
    if (sum >= res.sum) {
      res.sum = sum;
      res.right = i;
      res.left = res.right - count + 1;
    }
    if (sum < 0) {
      sum = 0;
      count = 0;
    }
  }

  return res;
}

size_t FindKthNum::partition(std::vector<int>::iterator start, std::vector<int>::iterator end, cmp c)  {
  int x = *start;
  auto left = start;
  auto right = end;
  while (left < right) {
    while (c(*(++left), x) && left < end);
    while (c(x, *(--right)) && right > start);
    if (left < right) {
      swap(*left, *right);
    }
  }
  swap(*right, *start);
  return right - start;
}

int FindKthNum::find_kth_num(std::vector<int>::iterator start, std::vector<int>::iterator end, size_t k) {
  if (end - start == 1) {
    return *start;
  }
  if (end > start) {
    size_t tmp = partition(start, end, std::less<int>());
    auto left = start, right = end;
    if (end - start - k == tmp) {
      return *(start + tmp);
    } else if (end - start - k > tmp) {
      return find_kth_num(start + tmp + 1, end, k);
    } else {
      return find_kth_num(start, start + tmp, k - (end - start - tmp));
    }
  }
  
  return -1;
}

GetMinAndMax::GetMinAndMax(const std::vector<int>& nums)
    : nums { nums }{
}

void GetMinAndMax::get_min_max(int& min, int& max) {
  if (nums.empty()) {
    return;
  }
  int min_tmp, max_tmp;
  size_t start = 0;
  if (nums.size() % 2 == 1) {
    min_tmp = nums[0];
    max_tmp = nums[0];
    start = 1;
  } else {
    if (nums[0] > nums[1]) {
      max_tmp = nums[0];
      min_tmp = nums[1];
    } else {
      max_tmp = nums[1];
      min_tmp = nums[0];
    }
    start = 2;
  }
  for (; start < nums.size(); start += 2) {
    if (nums[start] > nums[start + 1]) {
      if (nums[start] > max_tmp) {
        max_tmp = nums[start];
      }
      if (nums[start + 1] < min_tmp) {
        min_tmp = nums[start + 1];
      }
    } else {
      if (nums[start] < min_tmp) {
        min_tmp = nums[start];
      }
      if (nums[start + 1] > max_tmp) {
        max_tmp = nums[start + 1];
      }
    }
  }
  min = min_tmp;
  max = max_tmp;
}