#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    map<string, int> m;
    string str;
    int total = 0;
    
    while (getline(cin, str)) {
        m[str]++;
        total++;
    }
    
    for (auto m_ : m) {
        cout << m_.first << ' ';
        double value = m_.second / double(total) * 100;
        cout << fixed;
        cout.precision(4);
        cout << value << '\n';
    }
}