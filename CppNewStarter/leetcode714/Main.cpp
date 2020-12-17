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

            //第0天，手上没有股票时的最大收益
            dp[0][0] = 0;

            //第0天，手上有股票时的最大收益
            dp[1][0] = -prices[0];

            for (int i = 1; i < prices.size(); ++i) {
                dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i] - fee);
                dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
            }

            return dp[0][days - 1];
        }
    };

}


int main(int argc, char *argv[]) {
    vector<int> vec{1, 3, 2, 8, 4, 9};

    leetcode714::Solution solution;
    solution.maxProfit(vec, 2);

    return 0;
}