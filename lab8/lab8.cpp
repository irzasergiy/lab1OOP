#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int sumOdd = 0;
    for (int i = 1; i < n; i += 2) sumOdd += a[i];

    int firstNeg = -1, lastNeg = -1;
    for (int i = 0; i < n; i++) if (a[i] < 0) { firstNeg = i; break; }
    for (int i = n - 1; i >= 0; i--) if (a[i] < 0) { lastNeg = i; break; }

    int sumBetween = 0;
    if (firstNeg != -1 && lastNeg != -1 && firstNeg < lastNeg) {
        for (int i = firstNeg + 1; i < lastNeg; i++) sumBetween += a[i];
    }

    int k = 0;
    for (int i = 0; i < n; i++) if (abs(a[i]) > 1) a[k++] = a[i];
    for (int i = k; i < n; i++) a[i] = 0;

    cout << sumOdd << " " << sumBetween << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    delete[] a;
}
