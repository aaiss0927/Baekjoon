#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            
            if (num > maxi) maxi = num;
            if (num < mini) mini = num;
        }
        
        cout << mini << ' ' << maxi << '\n';
    }
}