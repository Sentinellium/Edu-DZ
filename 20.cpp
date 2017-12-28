#include<iostream>
#include<cmath>

using namespace std;

int heap[100000];
int sz;
int k=0;


void normUP(int x)
{
    while(x!=0 && heap[x]>heap[(x-1)/2])
    {
        swap(heap[x],heap[(x-1)/2]);
        x = (x-1) / 2;
    }
}


void norm(int x)
{
    int t;
    while (2*x+1<sz) {
        t=2*x+1;
        if (2*x+2<sz && heap[t]<heap[2*x+2])
            t = 2*x+2;
        if (heap[x]>=heap[t])
            return;
        swap(heap[x],heap[t]);
        x=t;
    }
}


void add(int x)
{
    heap[sz++] = x;
    k += 1;
    normUP(x);
}


int del()
{
    int temp = heap[0];
    swap(heap[0], heap[--sz]);
    norm(0);
    return temp;
}

int main()
{
    int a[10];
    for(int i=9;i>-1;i--){
        a[i]=i;
    }
    for(int i=0;i<10;i++)
        add(a[i]);
    for(int i=1;i<10;i++){
        a[10-i] = del();
    }
    for(int i=0; i<10;i++)
        cout << a[i] << " ";
    return 0;
}
