#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, m, M, T, R; cin >> N >> m >> M >> T >> R;
    int total_time = 0;
    int exc_time = 0;
    int pulse = m;

    if (T > M - m) {
        cout << -1;
        return 0;
    }

    while (exc_time < N) {
        if (pulse + T <= M) {
            pulse += T;
            exc_time++;
        }

        else {
            if (pulse - R < m)
                pulse = m;

            else {
                pulse -= R;
            }
        }

        total_time++;
    }

    cout << total_time;
}
