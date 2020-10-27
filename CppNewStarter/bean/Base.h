//
// Created by chenr on 2020/10/27.
//

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


#endif //CPPNEWSTARTER_BASE_H
