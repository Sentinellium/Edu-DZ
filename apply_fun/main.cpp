#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <iomanip> 
using namespace std;

template <typename T>
void apply(void(*f)(T&), T &x) {
    f(x);
}

template <typename T, size_t S>
void apply(void(*f)(T&), T a[]) {
    for (size_t i(0); i < S; ++i)
        apply<T>(f, a[i]);
}

template <typename T, typename U>
void apply(void(*f)(T&), U &x) {
    for (auto &it: x)
        apply<T>(f, it);
}

void randomize(auto &x) {
    x = rand() % 150 + rand() * 1.0 / rand();
}

void print(auto &x) {
    cout << x << ' ';
}

vector <int> v(10);
list <int> l(5);

int main() {
    cout << fixed << setprecision(3);
    puts("Random generate");
    puts("Single element:");
    
    int x;
    apply<int>(&randomize, x);
    apply<int>(&print, x);

    puts("\nArray double[10]:");
    double a[10];
    apply<double, 10>(&randomize, a);
    apply<double, 10>(&print, a);

    puts("\nList<int>(5):");
    list <int> l(5);
    apply<int, list<int> >(&randomize, l);
    apply<int, list<int> >(&print, l);

    puts("\nVector<double>(15):");
    vector <double> v(15);
    apply<double, vector<double> >(&randomize, v);
    apply<double, vector<double> >(&print, v);
    return 0;
}
