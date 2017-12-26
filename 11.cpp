#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            swap(a,b);
        }
        b=b-a;
    }
    return a;
}

int main()
{
    int n,m;
    cin >>n;
    m=0;
    for (int i=1;i<=n;i++){
        if (gcd(i,n)!=1)
            m++;
    }
    cout << m << endl;
    return 0;
}
