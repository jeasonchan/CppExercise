//
// Created by chenr on 2020-09-01.
//

#ifndef CPPNEWSTARTER_SHAREPTR_HPP
#define CPPNEWSTARTER_SHAREPTR_HPP

#include <string>

template<typename T>
class SharePtr {
private:
    T *_ptr;
    int *_pCount;

    void release() {
        if (1 == *_pCount) {
            delete _ptr;
            delete _pCount;
        } else {
            --*_pCount;
        }
    }

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
        release();
    }


    //赋值符号，从语义看，就是不改变input的
    //并且用新值代替旧只，也就是，先对处理旧的，再接纳新的，
    //也就是，减少旧对象的引用计数，增加新对象的引用计数
    SharePtr<T> &operator=(const SharePtr<T> &input) {
        if (this != &input && this->_ptr != input._ptr) {
            //减少旧对象的引用计数
            --*_pCount;
            if (0 == *_pCount) {
                delete _ptr;
                delete _pCount;
            }
            _ptr = input._ptr;
            _pCount = input._pCount;
            ++*_pCount;
        }

        return *this;
    }

    T &operator*() {
        return *_ptr;
    }

    T *operator->() {
        return _ptr;
    }
};

class LinkNode {
public:
    SharePtr<std::string> next;
};

void aaa() {

    SharePtr<LinkNode> nodeA();
    SharePtr<LinkNode> nodeB();

}


#endif //CPPNEWSTARTER_SHAREPTR_HPP
