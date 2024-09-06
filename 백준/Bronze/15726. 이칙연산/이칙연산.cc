#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int a, b, c; cin >> a >> b >> c;
    int maxi;

    if ((a * double(b) / c) > ((double(a) / b) * c))
        maxi = a * double(b) / c;
    else
        maxi = double(a) / b * c;

    cout << int(maxi);
}