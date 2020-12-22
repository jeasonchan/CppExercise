#include <vector>
#include <iostream>


namespace leetcode746 {
    using namespace std;


    class Solution {
    public:


        /*
         * 思路错误，无法处理[0,1,2,2]这种情况
         */
        int minCostClimbingStairs(vector<int> &cost) {
            //插入一个作为最高点
            cost.push_back(0);
            int ret = -1;
            int current_index = 0;
            while (current_index + 2 < cost.size()) {
                if (-1 == ret) {
                    ret = min(cost[current_index], cost[current_index + 1]);
                    current_index = cost[current_index] <= cost[current_index + 1] ? current_index : current_index + 1;
                    continue;
                }

                ret += min(cost[current_index + 1], cost[current_index + 2]);
                current_index =
                        cost[current_index + 1] < cost[current_index + 2] ? current_index + 1 : current_index + 2;


            }
            return ret;
        }


        int minCostClimbingStairs_v2(vector<int> &cost) {


        }
    };

}


int main(int argc, char *argv[]) {
    std::vector<int> vec{0, 1, 2, 2};

    leetcode746::Solution solution;

    int result = solution.minCostClimbingStairs(vec);

    return 0;
};