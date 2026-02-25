#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    
    for (int i = 0; i < n; i++) {
        int score; cin >> score;
        v.push_back(score);
    }
    
    reverse(v.begin(), v.end());
    int cnt = 0;
    
    for (int i = 1; i < n; i++) {
        if (v[i] >= v[i - 1]) {
            cnt += (v[i] - v[i - 1] + 1);
            v[i] = v[i - 1] - 1;
        }
    }
    
    cout << cnt;
}