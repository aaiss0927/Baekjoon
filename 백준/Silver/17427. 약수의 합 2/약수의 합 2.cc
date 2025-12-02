#include <iostream>
#define ll long long
using namespace std;

ll solution(int N) {
	ll answer = 0;

	for (int i = 1; i <= N; i++)
		answer += i * (N / i);

	return answer;
}

int main() {
	int N; cin >> N;
	cout << solution(N);
}

// N, g(N) = ?

// f(1) = 1
// f(2) = 1 + 2
// f(3) = 1 + 3
// f(4) = 1 + 2 + 4
// f(5) = 1 + 5
// f(6) = 1 + 2 + 3 + 6
// g(6) = 1 * 6/1 + 2 * (6/2) + 3 * (6/3) + ,,,