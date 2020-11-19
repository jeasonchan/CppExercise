//
// Created by chenr on 2020/10/2.
//
#include <iostream>
#include <vector>
#include 

void createFunction1(unsigned int n) {
    unsigned i, j;
    const int b = 123;

    //elements in array is int[123] type
    //st like int[b] *array2D=new (int[123])[n]
    int (*array2D)[b] = new int[n][b];
    for (int height = 0; height < n; ++height) {
        for (int width = 0; width < b; ++width) {
            std::cout << array2D[height][width] << " ";
        }
    }

    delete[] array2D;
}


void createFunction2(unsigned int height, unsigned int width) {
    //element in array is int* type
    int **array2D = new int *[height];

    //create each row
    for (int i = 0; i < width; ++i) {
        *array2D = new int[width];
    }

    //destroy array
    for (int i = 0; i < height; ++i) {
        delete[] array2D[i];
    }
    delete[] array2D;

}

class Persons {
public:
    int *begin();

    int *end();

    Persons *getThis();

    Persons *operator->() noexcept;

    Persons &operator*() noexcept;

};


int main() {
    int a[2][3] = {1, 2, 3};
    auto b = a;
    auto b4 = &a[0][0];

    int (*a2)[3] = new int[2][3];
    auto b2 = a2;


    int *a3 = new int[5];;
    auto b3 = a3;

    std::vector<int> aaa{1};

    std::vector<int>::iterator it = aaa.begin();

    std::vector<Persons> vector_persons{};
    auto it2 = vector_persons.begin();
    it2->begin();

    Persons persons;
    persons.getThis()->begin();

    //按道理，->这个操作符返回类型的是对象的指针，通过指针调方法，应该再来个->才对……
    persons->begin();
    (*persons).begin();

    for (auto p:persons) {

    }

    return 0;
}