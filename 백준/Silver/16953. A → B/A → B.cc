#include <iostream>
using namespace std;

int a, b;
bool flag;

void bt(int b, int cnt) {
    if ((b == a) && !flag) {
        cout << cnt;
        flag = true;
        return;
    }
    
    if (b < a) return;
    
    if (b % 2 == 0)
        bt(b / 2, cnt + 1);
    
    if (b % 10 == 1)
        bt(b / 10, cnt + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    bt(b, 1);
    
    if (!flag) cout << -1;
}