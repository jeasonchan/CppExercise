//
// Created by chenr on 2020/10/27.
//

#include <new>

#ifndef CPPNEWSTARTER_BASE_H
#define CPPNEWSTARTER_BASE_H

namespace {
    class Base {

    public:
        virtual void hhah() = 0;
    };


    class Child : public Base {
    public:
        void hhah() override;
    };
}


int main() {
    char *a = new char[sizeof(Base)];
    Child *b = new(a) Child;

    b->hhah();

    return 0;
};

#endif //CPPNEWSTARTER_BASE_H
