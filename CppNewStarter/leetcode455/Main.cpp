#include <vector>
#include <algorithm>


namespace leetcode455 {
    using namespace std;

    class Solution {
    public:

        /**
         *
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

        }
    };


}


int main(int argc, char *argv[]) {


    return 0;

}