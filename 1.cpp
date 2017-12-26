#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >>n>>m;
    int *a = new int[n*m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            *(a+i*m+j)=(i+1)*(j+1);
            cout <<*(a+i*m+j)<<" ";
        }
        cout <<endl;
    }
    delete[] a;
}
