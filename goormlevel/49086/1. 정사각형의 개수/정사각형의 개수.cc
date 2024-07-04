#include <iostream>
using namespace std;
int main() {
	long long N; cin >> N;
	long long result = N * (N + 1) * (2 * N + 1) / 6;
	cout << result;	
}

// n * (n + 1) * (2n + 1) / 6