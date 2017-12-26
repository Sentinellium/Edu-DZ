#include <iostream>
#include <std_lib_facilities.h>

using namespace std;

struct rational
{
    int x,y;
public:
    int gcd(int a, int b) {
        while (a != b) {
            if (a > b) {
                swap(a,b);
            }
            b=b-a;
        }
        return a;
    }
    rational goodstate(rational a){
        a.x/=a.gcd(a.x,a.y);
        a.y/=a.gcd(a.x,a.y);
        return a;
    }

    rational sum(rational a,rational b){
        a.x=(a.x)*b.y+(b.x)*a.y;
        a.y=(a.y)*b.y;
        return goodstate(a);

    }
    rational multi(rational a,rational b){
        a.x=(a.x)*b.x;
        a.y=(a.y)*b.y;
        return goodstate(a);
    }
    rational sub(rational a,rational b){
        a.x=(a.x)*b.y-(b.x)*a.y;
        a.y=(a.y)*b.y;
        return goodstate(a);
    }
    rational div(rational a,rational b){
        a.x=(a.x)*b.y;
        a.y=(a.y)*b.x;
        return goodstate(a);
    }
    void output(rational a){
        cout <<a.x <<"/"<<a.y<<endl;
    }
};

int main()
{
    rational a,b;
    a.x=;
    a.y=;
    b.x=;
    b.y=;
    a=a.(a,b);
    a=a.goodstate(a);
    a.output(a);
    return 0;
}
