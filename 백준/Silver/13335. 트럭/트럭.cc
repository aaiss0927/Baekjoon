#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> t;
    int n, w, L;
    cin >> n >> w >> L;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        t.push(x);
    }

    queue<int> q;
    int curW = 0;
    int count = 0;

    for (int i = 0; i < w; i++) {
        q.push(-1);
    }

    int num = n * w + 1;
    while (!t.empty() && num--) {
        if (q.front() != -1) {
            curW -= q.front();
        }

        if (curW + t.front() > L) {
            
            q.pop();
            q.push(-1);
            count++;
        }

        else {
            q.pop();
            q.push(t.front());
            curW += t.front();
            t.pop();
            count++;
        }
    }

    count += w;
    cout << count;
}