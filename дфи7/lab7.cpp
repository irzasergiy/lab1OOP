#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    multiset<int> s;
    for (int i = 0; i < 50; i++) s.insert(rand() % 21);

    for (auto it = s.begin(); it != s.end(); ) {
        int v = *it;
        int c = s.count(v);
        cout << v << " " << c << endl;
        it = s.upper_bound(v);
    }
}
