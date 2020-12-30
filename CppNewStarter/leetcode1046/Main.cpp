#include <vector>
#include <queue>

namespace leetcode1046 {
    using namespace std;

    class Solution {
    public:
        int lastStoneWeight(vector<int> &stones) {
            auto less = [](int &o1, int &o2) -> bool { return o1 < o2; };

            //其实可以直接用std中仿函数  std::less<int>，此处可以训练用的lambda表达式
            priority_queue<int, vector<int>, decltype(less)> q();

        }
    };

}


int main(int argc, char *argv[]) {

    return 0;
}