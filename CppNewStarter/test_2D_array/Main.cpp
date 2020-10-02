//
// Created by chenr on 2020/10/2.
//

int main() {
    int a[2][3] = {1, 2, 3};
    auto b = a;

    int (*a2)[3] = new int[2][3];
    auto b2 = a2;

    int *a3 = new int[5];;
    auto b3 = a3;

    return 0;
}