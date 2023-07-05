#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	stack<int> s;
	char top_array;
	for (int i = 1; i <= N; i++) {
		int top;
		if (!v.empty() && !s.empty()) {
			top = min(v.front(), s.top());
			if (top == v.front()) {
				top_array = 'v';
			}
			else {
				top_array = 's';
			}
		}
		else if (v.empty() && !s.empty()) {
			top = s.top();
			top_array = 's';
		}
		else if (!v.empty() && s.empty()) {
			top = v.front();
			top_array = 'v';
		}
		else {
			cout << "Nice";
			return 0;
		}

		if (top_array == 'v') {
			while (top != i) {
				if (!s.empty()) {
					if (s.top() < top) {
						cout << "Sad";
						return 0;
					}
				}
				v.erase(v.begin());
				s.push(top);
				top = v.front();
			}
			if (top == i) {
				v.erase(v.begin());
				if (v.empty()) {
					cout << "Nice";
					return 0;
				}
			}
		}
		else {
			s.pop();
		}
	}
}