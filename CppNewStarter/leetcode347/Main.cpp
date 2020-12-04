//
// Created by chenr on 2020/12/4.
//

#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include <iostream>
#include <algorithm>

class Solution {
public:
    static bool cmp(std::pair<int, int> &m, std::pair<int, int> &n) {
        return m.second > n.second;
    }

    std::vector<int> topKFrequent2(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> occurrences;
        for (auto &v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto&[num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        std::vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }


    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> record;
        for (auto &each:nums) {
            ++record[each];
        }

        auto biggerOrder = [](std::pair<int, int> &o1, std::pair<int, int> &o2) { return o1.second > o2.second; };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(biggerOrder)> queue(
                biggerOrder);
        for (auto &eachPair:record) {

            //todo optimize
            if (queue.size() < k) {
                queue.emplace(eachPair);
            } else {
                if (eachPair.second > queue.top().second) {
                    queue.pop();
                    queue.emplace(eachPair);
                }
            }

        }

        //与先申请好内存，避免扩容的性能损失
        std::vector<int> ret(k);
        int index = 0;
        while (!queue.empty()) {
            ret[index++] = queue.top().first;
            queue.pop();
        }

        return std::move(ret);
    }

};


int main() {
    std::vector<int> input{1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution solution;
    std::vector<int> &&ret = solution.topKFrequent(input, k);

    std::for_each(ret.cbegin(), ret.cend(), [](auto &input) { std::cout << input << std::endl; });
//    std::cout << ret << std::endl;
    return 0;
}