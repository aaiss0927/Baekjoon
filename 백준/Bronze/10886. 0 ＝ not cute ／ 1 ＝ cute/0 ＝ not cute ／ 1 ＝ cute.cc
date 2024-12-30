#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int vote; cin >> vote;
        sum += vote;
    }

    if (2 * sum > n)
        cout << "Junhee is cute!";
    else
        cout << "Junhee is not cute!";
}