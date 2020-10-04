//
// Created by chenr on 2020/10/2.
//
#include <iostream>

void createFunction1(unsigned int n) {
    unsint i, j;
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

int main() {
    int a[2][3] = {1, 2, 3};
    auto b = a;
    auto b4 = &a[0][0];

    int (*a2)[3] = new int[2][3];
    auto b2 = a2;


    int *a3 = new int[5];;
    auto b3 = a3;


    return 0;
}