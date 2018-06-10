#include <quaternion.h>
#include <operators.h>

quaternion operator+(quaternion a, const quaternion &b) {
    a += b;
    return a;
}

quaternion operator*(quaternion a, const quaternion &b) {
    a *= b;
    return a;
}

quaternion operator*(quaternion a, const double b) {
    a *= b;
    return a;
}

quaternion operator*(const double a, quaternion b) {
    return b * a;
}

quaternion operator-(quaternion a, const quaternion &b) {
    a -= b;
    return a;
}

quaternion operator/(quaternion a, const quaternion &b) {
    a /= b;
    return a;
}
