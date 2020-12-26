#include <vector>
#include <algorithm>


namespace leetcode455 {
    using namespace std;

    class Solution {
    public:

        /**
         * 官方答案
         * @param g 小朋友的胃口值
         * @param s 饼干尺寸队列
         * @return
         */
        int findContentChildren(vector<int> &g, vector<int> &s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int numOfChildren = g.size(), numOfCookies = s.size();
            int count = 0;
            for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++) {
                while (j < numOfCookies && g[i] > s[j]) {
                    j++;
                }

                //这个越界判断十分容易忘了！！！边界情况是，饼干都不满足小朋友的胃口。
                //这种使用while循环找出下一个满足条件的状态的方法，一定要先判断一下是否越界
                if (j < numOfCookies) {
                    count++;
                }
            }
            return count;
        }


        /**
         *
         * @param g 小朋友的胃口值
         * @param s 饼干尺寸队列
         * @return
         */
        int findContentChildren_v2(vector<int> &g, vector<int> &s) {
            std::sort(g.begin(), g.end(), [](auto &o1, auto &o2) { return o1 > o2; });//期望的排序顺序是，o1>o2
            std::sort(s.begin(), s.end(), [](auto &o1, auto &o2) { return o1 > o2; });

            int ret = 0;

            int childIndex = 0;
            //遍历饼干
            for (auto &eachCookie:s) {
                for (int i = childIndex; i < g.size(); ++i) {
                    if (g[i] <= eachCookie) {
                        ++ret;
                        childIndex = i + 1;
                        break;
                    }
                }

            }


            return ret;
        }

/**
         *
         * 改写V2，尝试使用while循环查找下一个满足的条件的index
         * 但是，运行时间比v2版本稍长
         * @param g 小朋友的胃口值
         * @param s 饼干尺寸队列
         * @return
         */
        int findContentChildren_v3(vector<int> &g, vector<int> &s) {
            std::sort(g.rbegin(), g.rend());
            std::sort(s.rbegin(), s.rend());

            int ret = 0;
            int childIndex = 0;
            for (auto &cookieSize:s) {
                while (childIndex < g.size() && g[childIndex] > cookieSize) {
                    ++childIndex;
                }

                if (childIndex < g.size()) {
                    ++ret;
                    ++childIndex;
                }

            }

            return ret;

        }


    };


}


int main(int argc, char *argv[]) {
    std::vector<int> g{10, 9, 8, 7};
    std::vector<int> s{5, 6, 7, 8};

    leetcode455::Solution solution;
    solution.findContentChildren_v3(g, s);

    return 0;

}