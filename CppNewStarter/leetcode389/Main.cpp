#include <iostream>
#include <string>
#include <array>

namespace leetcode389 {
    using namespace std;

    class Solution {
    public:
        char findTheDifference(string s, string t) {
            array<int, 26> letterRecord{0};
            for (auto &each:s) {
                ++letterRecord[each - 'a'];
            }

            for (auto &each:t) {
                if ((--letterRecord[each - 'a']) < 0) {
                    return each;
                }
            }

            return 0;
        }

        /**
         * 充分利用异或运算的结合率和交换率
         *
         * @param s
         * @param t
         * @return
         */

        char findTheDifference_v2(string s, string t) {
            char ret = 0;
            for (auto &each:s) {
                ret ^= each;
            }

            for (auto &each:t) {
                ret ^= each;
            }


            return ret;
        }
    };

}


int main(int argc, char *argv[]) {
    leetcode389::Solution solution;

    solution.findTheDifference_v2("asdfghjkl", "asdfghtjkl");

    return 0;
}
