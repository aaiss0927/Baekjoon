#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    
    int cnt_2, cnt_5;
    cnt_2 = cnt_5 = 0;
    
    cnt_2 = n % 5;
    if (cnt_2 % 2 == 1) cnt_2 = (cnt_2 + 5) / 2;
    else cnt_2 /= 2;

    cnt_5 = (n - 2 * cnt_2) / 5;
    
    if (cnt_2 < 0 || cnt_5 < 0) {
        cout << -1;
        return 0;
    }
    
    cout << cnt_2 + cnt_5;
}