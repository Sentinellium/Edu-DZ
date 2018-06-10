#include <cstdio>
#include <cmath>
#include <quaternion.h>
#include <operators.h>
#include <iostream>

int main() {
    quaternion a(1, 2, 1, 2), b(1, 2, 2, 1), c;
    a.print("a: ");
    b.print("b: ");
    (!a).print("conj a: ");
    printf("norm a: %.4f\n", sqrt(a.norm()));
    (a + b).print("a + b: ");
    (a - b).print("a - b: ");
    (a * b).print("a * b: ");
    (b * a).print("b * a: ");
    (a / b).print("a / b: ");
    (b / a).print("b / a: ");
    return 0;
}
