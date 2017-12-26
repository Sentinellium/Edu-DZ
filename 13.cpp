#include <iostream>

using namespace std;

int main()
{
    int r,b,k,min;
    cout << "enter x" << endl;
    cin >>r;
    int *n=new int[r+1];
    for (int i=0;i<r+1;i++){
        n[i]=0;
    }
    int i=0;
    k=0;
    while (k<r+1){
        k=i*i;
        if (k<r+1)
            n[k]=1;
        i++;
    }
    for (int i=1;i<r+1;i++){
        min=0;
        for (int k=0;k<i/2+2;k++){
            if ((n[k]!=0) && (n[i-k]!=0)){
                if (min==0){
                    min=n[i-k]+n[k];
                }
                if (min>n[i-k]+n[k]){
                    min=n[i-k]+n[k];
                }
            }
        }
        if (n[i]!=1)
            n[i]=min;
    }
            cout <<"n=" <<n[r]<< endl;
}
