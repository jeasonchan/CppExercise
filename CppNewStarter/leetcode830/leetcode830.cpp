#include<vector>
#include<string>

namespace leetcode830 {
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int previous_index=NO_INDEX;
        char previous_char=NO_CHAR;
        vector<vector<int>> ret{};
        int length=s.size();

        for(int i=0;i<length;++i){
            if(NO_CHAR==s[i]){
                previous_char=s[i];
                previous_index=i;
            }else {
                if(previous_char==s[i]) continue;

                //产生新数组
                if(i-1-previous_index>=3-1){
                    ret.push_back({previous_index,i-1});
                }
                previous_char=s[i];
                previous_index=i;

            }

        }

        if(NO_CHAR !=previous_char && length-1-previous_index>=3-1){
            ret.push_back({previous_index,length-1});
        }

        return ret;
    }



private:
    const static int NO_INDEX=-1;
    const static char NO_CHAR='a'-1;


};

}


int main(int argc,char* argv[]){
    leetcode830::Solution solution;

    auto result=solution.largeGroupPositions("hhhheecccwwwggxxxxxiookkxxaaarrrggggpppssseeeennnhhhhddssssfssssjjjjffbmmbbbboozzzzbbbbaaaaaeeeeqqqq");


    return 0;
}
