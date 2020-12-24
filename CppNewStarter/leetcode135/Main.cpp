#include <vector>
#include <array>

namespace leetcode135 {
    using namespace std;

    class Solution {
    public:
        int candy(vector<int> &ratings) {
            int n = ratings.size();
            int ret = 1;
            int inc = 1, dec = 0, pre = 1;
            for (int i = 1; i < n; i++) {
                if (ratings[i] >= ratings[i - 1]) {
                    dec = 0;
                    pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                    ret += pre;
                    inc = pre;
                } else {
                    dec++;
                    if (dec == inc) {
                        dec++;
                    }
                    ret += dec;
                    pre = 1;
                }
            }
            return ret;
        }


        /**
         * 尝试使用动态规划
         *
         * @param ratings
         * @return
         */
        int candy_v2(vector<int> &ratings) {
            vector<int> dp(ratings.size(), 1);
            int ret = ratings.size();

            for (int i = 0; i < ratings.size(); ++i) {


            }


            return ret;
        }

    };


}


int main(int argc, char *argv[]) {


    return 0;
}