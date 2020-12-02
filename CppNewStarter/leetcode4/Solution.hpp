//
// Created by chenr on 2020/12/3.
//

#ifndef CPPNEWSTARTER_SOLUTION_HPP
#define CPPNEWSTARTER_SOLUTION_HPP

#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::vector<int> combined;
        combined.insert(combined.end(), nums1.begin(), nums1.end());
        combined.insert(combined.end(), nums2.begin(), nums2.end());

        std::sort(combined.begin(), combined.end(), [](const int &o1, const int &o2) { return o1 < o2; });

        int size = combined.size();
        if (0 == size % 2) {
            return (combined[(size - 1) / 2] + combined[(size + 1) / 2]) / 2.0f;
        }
        return combined[combined.size() / 2];
    }
};


#endif //CPPNEWSTARTER_SOLUTION_HPP
