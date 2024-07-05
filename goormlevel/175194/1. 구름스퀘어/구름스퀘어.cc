#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<pair<int, int>> times;
	
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		times.push_back({a, b});
	}
	
	sort(times.begin(), times.end());
	
	int cur_start = 0;
	int cur_end = 0;
	int cnt = 0;
	
	for (int i = 0; i < N; i++) {
		if (times[i].first == cur_start) {
			continue;
		}
		
		if (times[i].first <= cur_end && times[i].second >= cur_end) {
			continue;
		}
		
		if (times[i].second < cur_end) {
			cnt--;
		}
		
		cur_start = times[i].first;
		cur_end = times[i].second;
		cnt++;
	}
	cout << cnt;
}

// 정렬
// 1 2 3 4 5 6 7 8 9 10 11 12 13
// - -
//   - -
//     - - - -
//       - -
// - - - - - - - - - -
//                      -  -  -
//
// 1 2 3 4 5 6 7 8 9 10 11
// - -
//     -
//     - - -
//       - - - - - - -
//         - -
//             - - -
//                   -  -