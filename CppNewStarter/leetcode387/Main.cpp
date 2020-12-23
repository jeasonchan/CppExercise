#include <string>
#include <array>


namespace leetcode387 {
    using namespace std;


    class Solution {
    public:

        /**
         * 第一次遍历记录每个字母用几次，第二次遍历找出第一个只出现了一次的字母
         *
         * 用了两次遍历，感觉应该一边遍历一边比较
         * @param s
         * @return
         */
        int firstUniqChar(string s) {
            array<int, 26> record{0};

            for (auto &each:s) {
                ++record[each - 'a'];
            }


            int index = -1;
            int i = 0;
            for (auto &each:s) {
                if (1 == record[each - 'a']) {
                    return i;
                }
                ++i;
            }


            return index;
        }
    };

}


int main(int argc, char *argv[]) {


    return 0;
}