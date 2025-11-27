#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
int findElement(T a[], int n, T x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

template <typename T>
class Transform {
    T* a;
    int n;
public:
    Transform(T* a, int n) : a(a), n(n) {}
    void apply() {
        for (int i = 0; i < n; i++) a[i] = static_cast<T>(exp(a[i]));
    }
};

int main() {
    double a[] = { 1, 2, 3, 4, 5 };
    Transform<double> t(a, 5);
    t.apply();
    cout << findElement(a, 5, exp(3.0));
}
