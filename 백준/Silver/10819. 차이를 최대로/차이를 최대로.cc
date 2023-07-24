#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	vector<int> arr_result;
	int result;
	do {
		result = 0;
		for (int i = 0; i < arr.size() - 1; i++) {
			result += abs(arr[i] - arr[i + 1]);
		}
		arr_result.push_back(result);
	} while (next_permutation(arr.begin(), arr.end()));

	sort(arr_result.begin(), arr_result.end());
	cout << arr_result.back();
}