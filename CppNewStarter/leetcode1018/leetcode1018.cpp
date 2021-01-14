#include <vector>


namespace leetcode1018{
    using namespace std;
    class Solution {
    public:
        /**
         * 官方解法一
         * @param A
         * @return
         */
        vector<bool> prefixesDivBy5(vector<int>& A) {
            vector<bool> list;
            int prefix = 0;
            int length = A.size();
            for (int i = 0; i < length; i++) {
                prefix = ((prefix << 1) + A[i]) % 5;
                list.emplace_back(prefix == 0);
            }
            return list;
        }

        vector<bool> prefixesDivBy5(vector<int>& A) {
//            vector



        }
    };



}


int main(int argc,char* argv[]){
    using namespace std;


    return 0;
}