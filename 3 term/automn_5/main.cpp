#include <iostream>
#include <mutex>
#include <stdio.h>

using namespace std;

class Errornet{};
template <typename T>
class A {
    mutex m;
    T data;
public:
    A(){}
    T operator =(const T & x){
        m.lock(); //locking class so that as long as the operation is present it doesn`t get affected by other threads
        data = x;
        m.unlock();
        return *this;
    }
    bool lock_check(){
        return m.try_lock();
    }
    T load(){
        if(!lock_check()) throw Errornet(); // preventing to calculate load
        m.lock();
        T x = data;
        m.unlock();
        return x;
    }
    void store( const T & x){
        if(!lock_check()) throw Errornet(); // preventing to calculate store
        m.lock();
        data = x;
        m.unlock();
    }
    operator T() const{
        return data;
    }
private:
    A(const A & a){}
    A(const A && a){}
};
int main() {
    A<int> a;
    a = rand();
    int b = a/13;
    cout <<a << "  "<<b <<endl;
}
