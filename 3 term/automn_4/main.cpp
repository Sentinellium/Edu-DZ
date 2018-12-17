#include <thread>
#include <iostream>
#include <stdio.h>

using namespace std;
void Sort(int* array, int n)
{
  if(n > 1){
    int size = n;
    for(int i = 1; i < size; ++i){
      int j = i - 1;
      int key = array[i];
      while(j >= 0 && array[j] > key){
        array[j+1] = array[j];
        --j;
      }
      array[j+1] = key;
    }
  }
}
int main(){
    int* a;
    int n = 15000;
    a = new int[n];
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
