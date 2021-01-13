#ifndef _INTERVIEW_H_
#define _INTERVIEW_H_

#include <vector>
#include <string>

namespace ll {

namespace algorithm {

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
  MaximumSubarray(std::vector<int>& nums);

  // 分治
  Maximum get_maximum(int l, int r);
  // DP
  Maximum get_maximum_v2();

 private:
  Maximum get_mid_sum(int l, int mid, int r);
  std::vector<int> nums;
};

} // namespace algorithm

} // namespace ll

#endif