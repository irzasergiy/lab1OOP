#include <iostream>
#include <string>
using namespace std;

class BATKO {
protected:
    string imya;
public:
    BATKO(string i) : imya(i) {}
    virtual void show() { cout << imya << endl; }
};

class DITINA : public BATKO {
    string imya_ditini;
public:
    DITINA(string i_d, string i_b) : BATKO(i_b), imya_ditini(i_d) {}
    void show() override { cout << imya_ditini << " " << imya << endl; }
};

int main() {
    setlocale(LC_CTYPE, "ukr");

    BATKO b("Іван");
    b.show();
    DITINA d("Петро", "Іван");
    d.show();
    return 0;
}
