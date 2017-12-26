#include <std_lib_facilities.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    int *p = new int [n];
    for (int r=0;r<n;r++)
        p[r]=rand();
    int *k = &p[0];
    int *d = &p[0];
    for (int i=0;i<n;i++){
        cout << *d <<endl;
        d+=1;
    }
    d-=n;
    for (int j=0;j<n;j++){
        for (int i=0;i<n;i++){
            if (*d>*k){
                //cout << *d <<"       "<<*k<<endl;
                swap(*d,*k);
                //cout << *d <<"       "<<*k<<endl;
            }
            k+=1;
        }
        k-=n;
        d+=1;
    }
    d-=n;
    cout <<endl<<endl;
    for (int i=0;i<n;i++){
        cout << *d <<endl;
        d+=1;
    }
    return 0;
    delete [] p;
}
