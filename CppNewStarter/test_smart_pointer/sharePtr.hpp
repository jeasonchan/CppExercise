//
// Created by chenr on 2020-09-01.
//

#ifndef CPPNEWSTARTER_SHAREPTR_HPP
#define CPPNEWSTARTER_SHAREPTR_HPP

template<typename T>
class SharePtr {
private:
    T *_ptr;
    int *_pCount;

public:
    //clang规范规定，单入参的构造函数都必须用explicit以避免隐式转换
    explicit SharePtr(T *ptr) : _ptr(ptr) {
    }

    //拷贝构造函数，语义上就有不改变input
    SharePtr(const SharePtr<T> &input) :
            _ptr(input._ptr), _pCount(input._pCount) {
        ++*_pCount;
    }

    ~SharePtr() {
        if (1 == *_pCount) {
            delete _ptr;
            delete _pCount;
        } else {
            --*_pCount;
        }
    }


    SharePtr<T>& operator=(){

    }
};


#endif //CPPNEWSTARTER_SHAREPTR_HPP
