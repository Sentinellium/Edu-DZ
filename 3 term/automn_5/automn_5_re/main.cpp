#include <cstdio>
#include <thread>
#include <algorithm>
#include <mutex>
#include <iostream>
#include <fstream>


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
        m.lock();
        T x = data;
        m.unlock();
        return x;
    }
    void store( const T & x){
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

void Sort(A* array, int n)
{
  if(n > 1){
    int size = n;
    for(int i = 1; i < size; ++i){
      int j = i - 1;
      A key = array[i];
      while(j >= 0 && array[j] > key){
        array[j+1] = array[j];
        --j;
      }
      array[j+1] = key;
    }
  }
}


int main()
{
    A* a;
    int n = 15000;
    a = new A[n];
    for(int i = 0; i < n; i++)
        a[i] = rand()%100 - 100;
    thread t1(Sort, a, n);
    thread t2(Sort, a, n);
    t1.join();
    t2.join();
    bool check = true;
    for(int i = 0; i< (n - 1) && check; i++){
        if(a[i]>a[i+1]){
            cout << "Something happened";
            check = false;
        }
    }
    delete [] a;
    return 0;
}
