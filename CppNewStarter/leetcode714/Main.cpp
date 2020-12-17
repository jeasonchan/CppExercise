#include <vector>
#include <iostream>

using namespace std;

namespace leetcode714 {
    class Solution {
    public:


        /**
         * @brief
         * 输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
         * 输出: 8
         *
         * @param prices
         * @param fee
         * @return
         */
        int maxProfit(vector<int> &prices, int fee) {
            int days = static_cast<int>(prices.size());
            vector<vector<int>> dp{2, vector<int>(days)};


            return 0;
        }
    };

}


int main(int argc, char *argv[]) {
    vector<int> vec{1, 2, 35, 4, 6, 54, 9, 67, 57, 57, 0};

    leetcode714::Solution solution;
    solution.maxProfit(vec, 0);

    return 0;
}