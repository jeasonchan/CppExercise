#include<vector>


namespace leetcode189 {
using namespace std;

class Solution {
public:
    void rotate_v2(vector<int>& nums, int k) {
        int length=nums.size();
        k=getEqualK(nums.size(),k);
        for(int i=1;i<=k;++i){
            int previous=nums[0];
            int temp;
            for(int j=0;j<length;++j){
                if(j==length-1){
                    nums[0]=previous;
                    continue;
                }

                temp=nums[j+1];
                nums[j+1]=previous;
                previous=temp;
            }


        }

    }

    /**
     * @brief rotate_v2
     * 第一个版本是一步一步的移动，容易超时；该版本改进，尝试一步到位；
     *
     * @param nums
     * @param k
     */
    void rotate(vector<int>& nums, int k) {
        int length=nums.size();
        k=getEqualK(length,k);

        int moved_times=0;

        for(int i=0;i<k;++i){

            //以[1,2,3,4,5,6,7]为例，尝试k=0,1,2,3,4,5,6的情况，即可发现规律
            int index=i;
            const int init_index=i;
            int value_of_index=nums[i];
            int temp;
            int target_index=-1;

            for( ;moved_times<=length;){
                target_index=getNewIndex(length,k,index);

                temp=nums[target_index];
                nums[target_index]=value_of_index;
                value_of_index=temp;
                index=target_index;
                ++moved_times;
                
                if(target_index==init_index){
                    
                    break;
                }
            }

            if(moved_times>=length){
                break;
            }
        }






    }

private:
    /**
     * @brief moveToNext
     * @param nums
     * @param k
     * @param moved_count
     * @param index 将该位置的值移动到下一个位置
     * @return 返回新位置的原先的值
     */
    inline int moveToNext(vector<int> &nums,const int k,int& moved_count,int index,int value){
        int target_index=getNewIndex(nums.size(),k,index);

        int temp=nums[target_index];
        nums[target_index]=nums[index];

        //        moveToNext(nums)




        return -1;
    }




    /**
     * @brief getEqualK
     * 转换得到等价的k,0<=k<length,因为具有周期性
     *
     * @param length
     * @param k
     * @return
     */
    inline int getEqualK(int length,int k){
        return k%length;
    }


    /**
     * @brief getNewIndex
     * @param length
     * @param k
     * @param currentIndex
     * @return
     */
    inline int getNewIndex(int length,int k,int currentIndex){
        return currentIndex<=length-1-k?currentIndex+k:currentIndex+k-length;
    }


};


}


int main(int argc,char* argv[]){
    leetcode189::Solution solution;

    std::vector<int> vec{1,2,3,4,5,6,7};

    solution.rotate(vec,2);

    return 0;
}
