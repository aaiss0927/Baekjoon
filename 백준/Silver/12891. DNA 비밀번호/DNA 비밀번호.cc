#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int s, p; cin >> s >> p;
	string str; cin >> str;
	int min_cnt[4];
	int cnt[4] = { 0, 0, 0, 0 };

	for (int i = 0; i < 4; i++)
		cin >> min_cnt[i];

	int result_cnt = 0;

	for (int i = 0; i < p; i++) {
		if (str[i] == 'A')
			cnt[0]++;
		else if (str[i] == 'C')
			cnt[1]++;
		else if (str[i] == 'G')
			cnt[2]++;
		else if (str[i] == 'T')
			cnt[3]++;
	}

	bool cond = true;

	for (int i = 0; i < 4; i++) {
		if (cnt[i] < min_cnt[i])
			cond = false;
	}

	if (cond)
		result_cnt++;

	for (int i = 1; i <= s - p; i++) {
		if (str[i + p - 1] == 'A')
			cnt[0]++;
		else if (str[i + p - 1] == 'C')
			cnt[1]++;
		else if (str[i + p - 1] == 'G')
			cnt[2]++;
		else if (str[i + p - 1] == 'T')
			cnt[3]++;

		cond = true;

		if (str[i - 1] == 'A')
			cnt[0]--;
		else if (str[i - 1] == 'C')
			cnt[1]--;
		else if (str[i - 1] == 'G')
			cnt[2]--;
		else if (str[i - 1] == 'T')
			cnt[3]--;

		for (int i = 0; i < 4; i++) {
			if (cnt[i] < min_cnt[i])
				cond = false;
		}

		if (cond)
			result_cnt++;
	}

	cout << result_cnt;
}