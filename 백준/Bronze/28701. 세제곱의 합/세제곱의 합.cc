#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    long long first, second, third;
    first = second = third = 0;

    for (int i = 1; i <= n; i++) {
        first += i;
        second += pow(i, 3);
        third += pow(i, 3);
    }

    cout << first << '\n' << second << '\n' << third;
}