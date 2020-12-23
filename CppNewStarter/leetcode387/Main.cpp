#include <string>
#include <array>
#include <unordered_map>
#include <queue>

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

        /**
         * 尝试使用
         *
         * @param s
         * @return
         */
        int firstUniqChar_v2(string s) {

            unordered_map<char, int> position;
            queue<pair<char, int>> q;
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                if (!position.count(s[i])) {
                    position[s[i]] = i;
                    q.emplace(s[i], i);
                } else {
                    //标记当前字母已经多次出现
                    position[s[i]] = -1;

                    //把肯定没用的清除掉
                    while (!q.empty() && position[q.front().first] == -1) {
                        q.pop();
                    }
                }
            }
            return q.empty() ? -1 : q.front().second;

        }
    };

}


int main(int argc, char *argv[]) {


    return 0;
}