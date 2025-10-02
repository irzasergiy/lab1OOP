#include <iostream>
#include <cmath>
using namespace std;

double a_function(double x, double y, double z, double b) {
    return (sqrt(pow(x, 2) - pow(z, 0.3)) /
        (1 + pow(x, 1) / tgamma(1) + pow(y, 2) / tgamma(2) + pow(z, 3) / tgamma(3)));
}

double b_function(double x, double y, double z) {
    return (pow(abs(x) + y, 2) / (pow(z, 3) + x / 3)) - log(abs(pow(x, 2) + z));
}

double a_function_4(double x, double y, double z, double b) {
    return pow(y, 2) + (z / pow(x, 2)) + pow(sin(b), 2);
}

double b_function_4(double x, double y, double z) {
    return (pow(abs(x) + y, 2) / (pow(z, 3) + x / 3)) - log(abs(pow(x, 2) + z));
}
int main() {
    setlocale(LC_CTYPE, "ukr");

    double x = 0.48 * 4, y = 0.47 * 4, z = -1.32 * 4;

    double b = b_function_4(x, y, z);


    cout << "Ôóíêö³ÿ b[x, y, z] (âàð³àíò 4): " << b << endl;
    cout << "Ôóíêö³ÿ a[x, y, z, b] (âàð³àíò 4): " << a_function_4(x, y, z, b) << endl;
    

    for (double x = -1.0; x <= 1.0; x += 0.2) {

        double b = b_function_4(x, y, z);
        double a = a_function_4(x, y, z, b);


        cout << "x = " << x << " | ";
        cout << "a[x, y, z, b] = " << a << " | ";
        cout << "b[x, y, z] = " << b << endl;
    }
    return 0;
}
