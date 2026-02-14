#include <iostream>
#include <vector>
using namespace std;

int cnt_sw;
vector<int> v;

void toggle(int i) {
	v[i] = 1 - v[i];
}

int longest_sym_cnt(int num) {
	int cnt = 0;

	while (((num - cnt >= 1) && (num + cnt <= cnt_sw)) && (v[num - cnt] == v[num + cnt])) {
		cnt++;
	}

	return cnt - 1;
}

void process(int s, int num) {
	if (s == 1)
		for (int i = num; i <= cnt_sw; i += num)
			toggle(i);

	else {
		int lsc = longest_sym_cnt(num);

		for (int i = num - lsc; i <= num + lsc; i++)
			toggle(i);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> cnt_sw;
	v.push_back(0);

	for (int i = 0; i < cnt_sw; i++) {
		int s; cin >> s;
		v.push_back(s);
	}

	int cnt_st; cin >> cnt_st;

	for (int i = 0; i < cnt_st; i++) {
		int s, num; cin >> s >> num;

		process(s, num);
	}

	for (int i = 0; i < cnt_sw; i++) {
		if ((i != 0) && (i % 20 == 0)) cout << '\n';
		cout << v[i + 1] << ' ';
	}
}