#include <vector>
#include <iostream>


namespace leetcode738 {
    using namespace std;

    class Solution {
    public:
        int monotoneIncreasingDigits(int N) const {
            vector<unsigned short> record{};

            int bitNum = 0;
            for (int i = 0; N > 0; ++i) {
                record[i] = N % 10;
                N = N - record[i];
                bitNum = i;
            }

            int ret = 0;
            for (int i = bitNum; i >= 0; --i) {



            }


            return ret;

        }
    };


}


int main(int argc, char *argv[]) {


    return 0;
}
