#include<vector>


namespace leetcode509 {
using namespace std;

class Solution {

public:
    int fib(int n) {
        if(n==0){
            return 0;
        }

        if(n==1){
            return 1;
        }

        //n>=2
        return fib(n-1)+fib(n-2);
    }

    /**
     * @brief fib_v2
     * 带缓存的计算方法
     * @param n
     * @return
     */
    int fib_v2(int n){
        std::vector<int> recod(n+2,-1);
        recod[0]=0;
        recod[1]=1;
        for(int i=2;i<=n;++i){
            recod[i]=recod[i-1]+recod[i-2];
        }

        return recod[n];
    }
};


}


int main(int argc,char* argv[]){




    return 0;
}
