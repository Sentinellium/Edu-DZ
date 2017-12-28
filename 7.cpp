#include <iostream>
#include <std_lib_facilities.h>

int pow(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
           result = (result * base)% modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int order(int p, int b)
{
    if (gcd(p, b) != 1)
    {
        cout<<"p and b are not co-prime";
        return -1;
    }
    int k = 3;
    while (1)
    {
        if (pow(b, k, p) == 1)
            return k;
        k++;
    }
}
int convertx2e(int x, int& e)
{
    e = 0;
    while (x % 2 == 0)
    {
        x /= 2;
        e++;
    }
    return x;
}

int STonelli(int n, int p)
{
    if (gcd(n, p) != 1)
    {
        cout <<"a and p are not coprime";
        return -1;
    }
    if (pow(n, (p - 1) / 2, p) == (p - 1))
    {
        cout<<"no sqrt possible";
        return -1;
    }
    int s, e;
    s = convertx2e(p - 1, e);
    int q;
    for (q = 2; ; q++)
    {
        if (pow(q, (p - 1) / 2, p) == (p - 1))
            break;
    }
    int x = pow(n, (s + 1) / 2, p);
    int b = pow(n, s, p);
    int g = pow(q, s, p);

    int r = e;
    while (1)
    {
        int m;
        for (m = 0; m < r; m++)
        {
            if (order(p, b) == -1)
                return -1;
            if (order(p, b) == pow(2, m))
                break;
        }
        if (m == 0)
            return x;
        x = (x * pow(g, pow(2, r - m - 1), p)) % p;
        g = pow(g, pow(2, r - m), p);
        b = (b * g) % p;

        if (b == 1)
            return x;
        r = m;
    }
}
int main()
{
    int n = 9;
    int p = 71;
    int x = STonelli(n, p);
    if (x == -1)
        cout<<"Modular square root does not exist";
    else
        cout<<"Modular square root of "<<n<<" and " <<p<< " is " <<x<<endl;
}
