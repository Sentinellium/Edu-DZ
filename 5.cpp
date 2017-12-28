#include <std_lib_facilities.h>
#include <iostream>

struct str
{
    char *stri;
    int len;
    str(const char *s)
    {
        stri=new char[strlen(s)+1];
        len=strlen(s);
        memcpy(stri, s, len+1);
    }
    ~str() {
        delete[] stri;
    }
    void show()
    {
        cout <<stri<<endl;
    }
    int getlen()
    {
        return len;
    }
    str operator=(str &s)
    {
        delete[] stri;
        stri = new char[s.len];
        len = s.len;
        memcpy(stri, s.stri, len);
        return *this;
    }
};

int main() {
    str s="123";
    str d = "123456";
    cout<<"len s="<<s.getlen()<<endl;
    cout <<"s=";
    s.show();
    cout<<"len d="<<d.getlen()<<endl;
    cout<<"d=";
    d.show();
    return 0;
}
