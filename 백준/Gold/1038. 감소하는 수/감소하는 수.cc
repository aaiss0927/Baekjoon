#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v;
vector<string> descent_list;
bool is_used[10];

void back_tracking(int cnt, int lim) {
	if (v.size() == cnt) {
		string temp = "";
		
		for (int n : v) {
			temp += to_string(n);
		}

		descent_list.push_back(temp);
		return;
	}

	for (int i = 0; i < lim; i++) {
		if ((v.empty() && i == 0) || is_used[i])
			continue;

		is_used[i] = true;
		v.push_back(i);
		back_tracking(cnt, i);
		v.pop_back();
		is_used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	descent_list.push_back("0");
	
	for (int i = 1; i <= 10; i++) {
		back_tracking(i, 10);
	}
	
	if (n >= descent_list.size())
		cout << -1;

	else
		cout << descent_list[n];
}