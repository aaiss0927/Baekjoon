#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    stack<int> s;
    int cnt = 0;

    while (n--) {
        int cmd; cin >> cmd;

        if (cmd == 1) {
            int x; cin >> x;
            s.push(x);
            cnt++;
        }

        else if (cmd == 2) {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
                cnt--;
            }
                
            else
                cout << -1 << '\n';
        }

        else if (cmd == 3) {
            cout << cnt << '\n';
        }
            
        else if (cmd == 4) {
            if (s.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }

        else if (cmd == 5) {
            if (!s.empty())
                cout << s.top() << '\n';
            else
                cout << -1 << '\n';
        }
    }
}