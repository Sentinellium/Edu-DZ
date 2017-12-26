#include <iostream>

using namespace std;

int main()
{
    int n,m,a,b;
    cout << "enter n" << endl;
    cin >>n;

    int **mas=new int*[n];
    for (int i=0;i<n;i++){
        mas[i]=new int[2];
        a=rand()%100;
        b=rand()%100;
        if (a>b){
            mas[i][0]=b;
            mas[i][1]=a;
        }
        else{
            mas[i][1]=b;
            mas[i][0]=a;
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (mas[j][1]>mas[j+1][1]) {
                swap(mas[j],mas[j+1]);
            }
        }
    }
    for (int i=0;i<n;i++){
        //cout <<mas[i][0]<<"   "<<mas[i][1]<<endl;
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if ((mas[i][0]>mas[j][0]) && (mas[i][1]<mas[j][1])) {
                mas[j][0]=-1;
                mas[j][1]=-1;
            }
        }
    }
    cout <<endl;
    for (int i=0;i<n;i++){
        //cout <<mas[i][0]<<"   "<<mas[i][1]<<endl;
        if ((mas[i][0]!=-1) && (m==0))
            m=mas[i][1];
    }
    int s=1;
    for (int i=0;i<n;i++){
        if ((mas[i][0]!=-1) && (mas[i][0]>m)){
            s++;
            m=mas[i][1];
        }
    }
    cout <<s<<endl;
}
