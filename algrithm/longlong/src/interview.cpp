#include <sstream>
#include <climits>

#include "interview.h"

using namespace ll::algorithm;

MaximumSubarray::MaximumSubarray(std::vector<int>& nums) {
  for (auto n : nums) {
      this->nums.push_back(n);
  }
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