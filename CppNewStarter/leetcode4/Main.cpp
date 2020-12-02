//
// Created by chenr on 2020/12/3.
//

#include "Solution.hpp"
#include <cstring>

int main() {
    Solution solution;
    std::vector<int> nums1{1, 2, 3, 4, 4};
    std::vector<int> nums2{242, 23, 52, 5, 4, 5};
    solution.findMedianSortedArrays(nums1, nums2);


    return EXIT_SUCCESS;
}