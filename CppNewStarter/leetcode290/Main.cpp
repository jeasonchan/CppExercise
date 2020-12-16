#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

namespace leetcode290 {
    class Solution {
    public:

        /**
         * @brief
         * 输入: pattern = "abba", str = "dog cat cat dog"
         * 输出: true
         * @param pattern
         * @param s
         * @return
         */
        bool wordPattern(string pattern, string s) {
            size_t pattern_size = pattern.size();
            size_t str_size = count(s);
            unordered_map<char, string> pattern2str{pattern_size};
            unordered_map<string, char> str2pattern{str_size};
            if (pattern_size != str_size) {
                return false;
            }


            std::size_t offSet = 0;
            for (char &eachChar:pattern) {
                auto index = s.find(' ', offSet);
                if (index < 0) {
                    return false;
                }
                string str = s.substr(offSet, index - offSet);
                offSet = index + 1;


                auto patternIt = pattern2str.find(eachChar);
                auto strIt = str2pattern.find(str);

                if (pattern2str.end() == pattern2str.find(eachChar)) {
                    pattern2str.emplace(eachChar, str);
                    if (str2pattern.end() != strIt) {
                        return false;
                    }
                    str2pattern.emplace(str, eachChar);
                } else {
                    if (patternIt->second != str) {
                        return false;
                    }

                }


            }

            return true;

        }

    private:
        size_t count(string &input) {
            size_t offSet = 0;
            size_t count = 0;
            int index = 0;
            while ((index = input.find(' ', offSet)) >= 0) {
                offSet = index + 1;
                ++count;
            }

            return count + 1;
        }
    };

}


int main(int argc, char *argv[]) {
    string pattern = "aaa";
    string str = "aa aa aa aa";

    leetcode290::Solution solution;

    auto result = solution.wordPattern(pattern, str);

    cout << result << endl;

    return 0;
}