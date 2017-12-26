#include <iostream>

using namespace std;

int main()
{
    int n;
    float m;
    cout << "enter n,w" << endl;
    cin >>n;
    cin >>m;

    float *w=new float[n];
    int *c=new int[n];
    for (int i=0;i<n;i++){
        w[i]=rand();
        c[i]=rand();
        cout <<w[i]<<"  "<<c[i]<<endl;
    }
    for (int i=0;i<n;i++){
        for (int k=0;k<n-1;k++){
            if (c[k]/w[k]<c[k+1]/w[k+1]){
                swap(c[k],c[k+1]);
                swap(w[k],w[k+1]);
            }
        }
    }
    float s=0;
    for (int i=0;i<n;i++){
        if (m>w[i]){
            m-=w[i];
            s+=c[i];
        }
        else{
            s+=m*(c[i]/w[i]);
            break;
        }

    }
    cout <<s<<endl;
}
