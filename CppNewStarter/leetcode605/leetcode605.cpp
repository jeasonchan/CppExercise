#include <vector>


namespace leetcode605 {
    using namespace std;

    class Solution {
    public:
        bool canPlaceFlowers(vector<int> &flowerbed, int n) {
            int count = 0;
            for (int i = 0; i < flowerbed.size(); ++i) {

                if (checkIfCanPlant(flowerbed, i)) {
                    ++count;
                    flowerbed[i] = has_flower;
                }


                if (count >= n) {
                    return true;
                }
            }


            return false;
        }


    private:
        const static int has_flower = 1;
        const static int no_flower = 0;

        /**
         * 检查当前位置是否能种花
         *
         * @param vector
         * @param index
         * @return
         */
        bool checkIfCanPlant(vector<int> &vector, int &index) {
            if (vector[index] == has_flower) {
                return false;
            }


            if (index - 1 < 0 && index + 1 >= vector.size()) {
                return true;
            }

            if (index - 1 < 0 && index + 1 < vector.size() && vector[index + 1] == no_flower) {
                return true;
            }

            if (index + 1 >= vector.size() && index - 1 >= 0 && vector[index - 1] == no_flower) {
                return true;
            }

            if (index - 1 >= 0 &&
                index + 1 < vector.size() &&
                vector[index - 1] == no_flower &&
                vector[index + 1] == no_flower) {
                return true;
            }

            return false;
        }



        /**
         *  数学公式，假设有左端点i和右端点j，则i和j之间作
         *
         * @param vector
         * @param index
         * @return
         */
        bool checkIfCanPlant_v2(vector<int> &vector, int &index) {

        }
    };

}


int main(int argc, char *argv[]) {
    leetcode605::Solution solution;

    std::vector<int> input{1, 0, 0, 0, 1};

    solution.canPlaceFlowers(input, 2);

    return 0;
}