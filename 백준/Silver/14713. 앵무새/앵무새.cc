#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	cin.ignore();
	queue<string>* q = new queue<string>[N];
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		istringstream iss(str);
		string word;
		while (iss >> word) {
			q[i].push(word);
		}
	}

	queue<string> cmd;
	string str;
	getline(cin, str);
	istringstream iss(str);
	string word;
	while (iss >> word) {
		cmd.push(word);
	}

	int count_word = 0;;
	for (int i = 0; i < N; i++) {
		count_word += q[i].size();
	}

	if (count_word != cmd.size()) {
		cout << "Impossible";
		return 0;
	}

	bool flag;
	while (!cmd.empty()) {
		flag = false;
		for (int i = 0; i < N; i++) {
			if (q[i].empty()) {
				continue;
			}
			if (cmd.front() == q[i].front()) {
				cmd.pop();
				q[i].pop();
				flag = true;
				if (cmd.empty()) {
					cout << "Possible";
					return 0;
				}
			}
		}
		if (!flag) {
			cout << "Impossible";
			return 0;
		}
	}
}