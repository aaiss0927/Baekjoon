#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	cin >> n >> m;

	if (m > (n / 2)) {
		m = n - m;
	}

	if (m == 0) {
		cout << 0;
	}

	else {
		unsigned long nm_cnt_2, nm_cnt_5, dn_cnt_2, dn_cnt_5;
		nm_cnt_2 = nm_cnt_5 = dn_cnt_2 = dn_cnt_5 = 0;
		unsigned long div;

		div = 2;
		while (div <= n) {
			nm_cnt_2 += (n / div);
			div *= 2;
		}
		div = 5;
		while (div <= n) {
			nm_cnt_5 += (n / div);
			div *= 5;
		}

		div = 2;
		while (div <= m) {
			dn_cnt_2 += (m / div);
			div *= 2;
		}
		div = 5;
		while (div <= m) {
			dn_cnt_5 += (m / div);
			div *= 5;
		}

		div = 2;
		while (div <= (n - m)) {
			dn_cnt_2 += ((n - m) / div);
			div *= 2;
		}
		div = 5;
		while (div <= n - m) {
			dn_cnt_5 += ((n - m) / div);
			div *= 5;
		}

		int cnt_2 = nm_cnt_2 - dn_cnt_2;
		int cnt_5 = nm_cnt_5 - dn_cnt_5;

		int cnt = min(cnt_2, cnt_5);
		cout << cnt;
	}
}