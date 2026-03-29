#ifndef MINIVECTOR_HPP
#define MINIVECTOR_HPP

#include <iostream>
#include <new>
using namespace std;

template <typename T>
class MiniVector{
private:
    char* raw;
    int sz;
    int cap;

    T* ptr(int i) const{
        return reinterpret_cast<T*>(raw) + i;
    }

    void resize(int newCap){
        char* newRaw=new char[newCap * sizeof(T)];
        T* newData=reinterpret_cast<T*>(newRaw);
        for (int i=0;i<sz;i++){
            new (newData + i) T(*ptr(i));
            ptr(i)->~T();
        }
        delete[] raw;
        raw=newRaw;
        cap=newCap;
    }

public:
    //constructor
    MiniVector(){
        sz=0;
        cap=4;
        raw=new char[cap * sizeof(T)];
    }

    //copy constructor
    MiniVector(const MiniVector& other){
        sz=other.sz;
        cap=other.cap;
        raw=new char[cap * sizeof(T)];
        for (int i=0;i<sz;i++){
            new (ptr(i)) T(*other.ptr(i));
        }
    }

    //copy assignment operator
    MiniVector& operator=(const MiniVector& other){
        if (this==&other){
            return *this;
        }
        for (int i=0;i<sz;i++){
            ptr(i)->~T();
        }
        delete[] raw;
        sz=other.sz;
        cap=other.cap;
        raw=new char[cap * sizeof(T)];
        for (int i=0;i<sz;i++){
            new (ptr(i)) T(*other.ptr(i));
        }
        return *this;
    }

    //destructor
    ~MiniVector(){
        for (int i=0;i<sz;i++){
            ptr(i)->~T();
        }
        delete[] raw;
        raw=NULL;
    }

    //add element to the end
    void push_back(const T& value){
        if (sz==cap){
            resize(cap*2);
        }
        new (ptr(sz)) T(value);
        sz++;
    }

    //remove element at index
    void removeAt(int index){
        if (index<0||index>=sz){
            cout<<"Invalid index\n";
            return;
        }
        for (int i=index;i<sz-1;i++){
            *ptr(i)=*ptr(i+1);
        }
        ptr(sz-1)->~T();
        sz--;
    }

    //clear everything
    void clear(){
        for (int i=0;i<sz;i++){
            ptr(i)->~T();
        }
        sz=0;
    }

    //subscript operator
    T& operator[](int index){
        return *ptr(index);
    }
    const T& operator[](int index) const{
        return *ptr(index);
    }

    //get size
    int size() const{
        return sz;
    }

    //get capacity
    int capacity() const{
        return cap;
    }

    bool empty() const{
        return sz==0;
    }
};

#endif
