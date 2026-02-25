#include <iostream>
using namespace std;

int n, l;

int main() {
    cin >> n >> l;
    
    for (int i = l; i <= 100; i++) {
        if (i % 2) {
            if (n % i == 0) {
                int mid = n / i;
                int len = i / 2;
                
                if ((mid - len < 0) || (mid + len > 1000000000))
                    continue;
                
                for (int j = mid - len; j <= mid + len; j++)
                    cout << j << ' ';
                
                return 0;
            }
        }
        
        else {
            if ((n % i != 0) && ((2*n) % i == 0)) {
                int mid = n / i;
                int len = i / 2;
                
                if ((mid - len + 1 < 0) || (mid + len > 1000000000))
                    continue;
                
                for (int j = mid - len + 1; j <= mid + len; j++)
                    cout << j << ' ';
                
                return 0;
            }
        }
    }
    
    cout << -1;
}