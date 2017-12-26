#include <iostream>

using namespace std;

int main()
{
    int x,y,m;
    cin >>x>>y;
    if (x<y)
        swap(x,y);
    int **mas=new int*[x+2];
    for (int i=0;i<x+2;i++)
        mas[i]=new int[y+2];
    for (int i=0;i<x+2;i++){
        for (int k=0;k<y+2;k++){
            mas[i][k]=0;
        }
    }
     mas[2][2]=1;
     m=0;
    for (int i=2;i<y+2;i++){
        for (int k=2+m;k<x+2;k++){
            mas[k][i]+=mas[k-1][i]+mas[k-2][i]+mas[k][i-1]+mas[k][i-2]+mas[k-1][i-1]+mas[k-2][i-2];
            if (i<=k){
                mas[i][k]=mas[k][i];
            }
        }
        m++;
    }
        cout <<endl;

    cout << mas[x+1][y+1] << endl;
    return 0;
}
