#include <iostream>

using namespace std;

int main()
{
    int r,b,k,s;
    cout << "enter n,k" << endl;
    cin >>r>>k;
    int *n=new int[r];
    for (int i=0;i<r;i++){
        n[i]=0;
    }
    int i=0;
    b=0;
    n[0]=1;
    for (int i=1;i<r;i++){
        s=0;
        if (i-k>=0)
            b=i-k;
        else
            b=0;
        for (int k=b;k<i;k++){
                n[i]+=n[k];
            }
        }
            cout <<"N of ways=" <<n[r-1]<< endl;
}
