#include<iostream>
#include<algorithm>
#include<vector>

namespace leetcode724{
using namespace std;



class Solution {
public:

    /**
     * @brief pivotIndex
     * 其实就是动态规划，用for循环依次求出index=0,1,2,3......左右两侧的数字和，找到第一个左右两边相等的索引
     *
     * @param nums
     * @return
     */
    int pivotIndex(vector<int>& nums) {
        int sum_of_all=0;
        std::for_each(nums.begin(),nums.end(),[&sum_of_all](int& each){sum_of_all+=each;});
        int right_sum=0;
        int left_sum=sum_of_all;
        int index=-1;
        int length=nums.size();

        for(int i=0;i<length;++i){
            if(0==i){
                left_sum-=nums[i];
            }else {
                right_sum+=nums[i-1];
                left_sum-=nums[i];
            }


            if(right_sum==left_sum){
                return i;
            }
        }



        return index;
    }
};



}



int main(int argc,char* argv[]){
    std::cout<<"argc="<<argc<<std::endl;

    for(int i=0;i<argc;++i){
        std::cout<<argv[i]<<" ";
    }



    std::vector<int> input{1, 7, 3, 6, 5, 6};

    leetcode724::Solution soluton;
    int ret=soluton.pivotIndex(input);


    return 0;
}
