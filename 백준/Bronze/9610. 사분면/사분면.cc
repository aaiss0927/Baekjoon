#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;

    int q1, q2, q3, q4, ax;
    q1 = q2 = q3 = q4 = ax = 0;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        if (x > 0 && y > 0)
            q1++;
        else if (x < 0 && y > 0)
            q2++;
        else if (x < 0 && y < 0)
            q3++;
        else if (x > 0 && y < 0)
            q4++;
        else
            ax++;
    }

    cout << "Q1: " << q1 << '\n';
    cout << "Q2: " << q2 << '\n';
    cout << "Q3: " << q3 << '\n';
    cout << "Q4: " << q4 << '\n';
    cout << "AXIS: " << ax << '\n';
}