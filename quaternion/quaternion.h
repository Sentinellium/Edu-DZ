class quaternion {
    private:
    double a, b, c, d;
    public:
    quaternion() : a(0), b(0), c(0), d(0) {}
    quaternion(double _a, double _b, double _c, double _d) : a(_a), b(_b), c(_c), d(_d) {}
    quaternion &operator+=(const quaternion &x);
    quaternion &operator*=(const quaternion &x);
    quaternion &operator*=(const double x);
    quaternion operator-();
    quaternion &operator-=(const quaternion &x);
    quaternion operator!();
    double norm();
    quaternion &operator/=(const quaternion &x);
    void print(const char msg[]);
};
