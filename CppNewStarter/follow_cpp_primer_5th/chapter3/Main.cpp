//
// Created by chenr on 2020-09-27.
//
#include <iostream>
#include <cctype>


int main() {
    {
        std::string s1 = "123";
        std::isalpha(s1[0]);

        for (auto each:s1) {
            //string对象中，每个子序列是char型
            //每次迭代，如果有下一个char，则下一个char被拷贝给each变量
            each;
            std::cout << each << std::endl;
        }


        std::string s2 = "adhakdhkada!!!!k aoeoqeaw aeuoajdlad";
        //统计标点符号的个数
        decltype(s2.size()) punctNum = 0;
        for (auto each:s2) {
            //使用cctype中的方法
            if (ispunct(each)) {
                ++punctNum;
            }
        }


        //从上面的代码和注释中看出，每次循环迭代，each的值始终是值拷贝，
        // 那如何通过范围for直接改变string中的字符？？？
        for (auto &eachRef:s2) {
            //通过的C库中的方法将char转为大写
            eachRef = std::toupper(eachRef);
        }
    }

}
