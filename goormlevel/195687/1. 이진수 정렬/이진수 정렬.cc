#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> classified_array[21];
vector<int> temp(22);

int get_cnts_one(int n) {
	string result = "";
	int cnt = 0;
	
	while (n) {
		result = to_string((n % 2)) + result;
		n /= 2;
	}
	
	for (int i = 0; i < result.length(); i++) {
		if (result[i] == '1')
			cnt++;
	}
	
	return cnt;
}

void classify(int n) {
	int cnts_one = get_cnts_one(n);
	classified_array[cnts_one].push_back(n);
}

int main() {
	int N, K; cin >> N >> K;
	vector<int> v(N);
	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	
	for (int i = 0; i < N; i++) {
		classify(v[i]);
	}
	
	for (int i = 0; i < 21; i++) {
		sort(classified_array[i].begin(), classified_array[i].end());
		reverse(classified_array[i].begin(), classified_array[i].end());
	}
	
	temp.push_back(0);
	for (int i = 1; i <= 21; i++) {		
		for (int j = 20; j >= 21 - i; j--) {
			temp[i] += classified_array[j].size();
		}
	}
	
	int idx;
	for (int i = 1; i <= 21; i++) {		
		if (K <= temp[i]) {
			idx = i;
			break;
		}
	}
	
	int row = 21 - idx;
	int col = K - temp[idx - 1] - 1;
	
	cout << classified_array[row][col];
}

// 2^1 = 2 = 10
// 1: 0 ~ 20개 

//
// K = 6
// [20]: 5개
// [19]: 6개
// [18]: 14개
// [17]: 21개
// K = 3 : [20][2]    K = 4 : [20][3]    K = 5 : [20][4]
// K = 6 : [19][0]    K = 7 : [19][1]        K = 11 : [19][5]
// K = 12 : [18][0]        K = 25 : [18][13]
// [0, 5, 11, 25, 46]
// [0, [20].size(), [20].size() + [19].size(), [20] + [19] + [18] ... , [20] + ... [0]]

// idx = 2 -> [19]
// idx = 1 -> [20]

