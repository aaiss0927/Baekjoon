#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, S;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> N >> S;
	v = vector<int>(N);
	int ans = INT_MAX;

	for (int i = 0; i < N; i++)
		cin >> v[i];

	bool flag_finished = false;
	int s, e; s = e = 0;
	int sum = v[0];

	while (1) {
		e = s ? e : e < s;

		while (sum < S) {
			if (e == N - 1) {
				flag_finished = true;
				break;
			}
			e++;
			sum += v[e];
		}
			
		if (flag_finished)
			break;

		while (sum >= S) {
			sum -= v[s];
			s++;
		}
		s--;

		if (e - s + 1 < ans)
			ans = e - s + 1;
		s++;

		if (s >= N)
			break;
	}

	if (ans == INT_MAX)
		cout << 0;
	else
		cout << ans;
}

// 10 51
// 5 1 3 2 10 7 4 9 2 8
// (s, e) = (0, 0) -> (0, 4) 초기 s,e 에서 15넘을 때 까지 e++
// (0, 4) -> (2, 4) v 15넘은 상태에서 s++, 일단 최솟값 후보 v
// s++; (3, 4) -> (3, 5) 마지막 상태에서 s++, 15넘을 때 까지 e++
// (3, 5) -> (4, 5)v 15넘은 상태에서 s++, 최솟값 후보 v