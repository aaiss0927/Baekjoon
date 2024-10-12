#include <iostream>
#include <vector>
using namespace std;

vector<bool> is_prime(1041, true);

void init() {
    for (int i = 2; i * i <= 1040; i++) {
        for (int j = i * i; j <= 1040 ; j += i) {
            is_prime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    string str; cin >> str;

    int n = 0;

    for (char c : str) {
        if (islower(c))
            n += (c - 'a') + 1;
        else
            n += (c - 'A') + 27;
    }

    if (is_prime[n])
        cout << "It is a prime word.";
    else
        cout << "It is not a prime word.";
}
