#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


namespace leetcode1202 {
    using namespace std;


    class DisjointSetUnion {
    private:
        vector<int> f, rank;
        int n;

    public:
        DisjointSetUnion(int _n) {
            n = _n;
            rank.resize(n, 1);
            f.resize(n);
            for (int i = 0; i < n; i++) {
                f[i] = i;
            }
        }

        /**
         * 找出元素x的代表元，代表元是自己就说明需要新插入或者
         * @param x
         * @return
         */
        int find(int x) {
            return f[x] == x ? x : f[x] = find(f[x]);
        }

        void unionSet(int x, int y) {
            int fx = find(x), fy = find(y);
            if (fx == fy) {
                return;
            }
            if (rank[fx] < rank[fy]) {
                swap(fx, fy);
            }
            rank[fx] += rank[fy];
            f[fy] = fx;
        }
    };

    class Solution {
    public:
        string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
            DisjointSetUnion dsu(s.length());
            for (auto &it : pairs) {
                dsu.unionSet(it[0], it[1]);
            }
            unordered_map<int, vector<int>> mp;
            for (int i = 0; i < s.length(); i++) {
                mp[dsu.find(i)].emplace_back(s[i]);
            }
            for (auto&[x, vec] : mp) {
                sort(vec.begin(), vec.end(), greater<int>());
            }
            for (int i = 0; i < s.length(); i++) {
                int x = dsu.find(i);
                s[i] = mp[x].back();
                mp[x].pop_back();
            }
            return s;
        }
    };

}


int main(int argc, char *argv[]) {
    using namespace std;

    unordered_set<unordered_set<int>> record{};



    return 0;
}