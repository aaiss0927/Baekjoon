#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> body; body.emplace_back(1, 1);
	vector<pair<int, int>> apple;
	queue<pair<int, char>> rotate;
	int t = 0;
	pair<int, int> head = make_pair(1, 1);
	char direction = 'E';
	bool isApple = false;
	bool flag = false;

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		apple.emplace_back(x, y);
	}

	int L; cin >> L;
	for (int i = 0; i < L; i++) {
		int X; char C;
		cin >> X >> C;
		rotate.emplace(X, C);
	}

	while (!flag) {
		t++;

		if (!rotate.empty()) {
			while (rotate.front().first + 1 == t) {
				if (direction == 'E') {
					if (rotate.front().second == 'L') {
						direction = 'N';
					}
					else if (rotate.front().second == 'D') {
						direction = 'S';
					}
				}
				else if (direction == 'W') {
					if (rotate.front().second == 'L') {
						direction = 'S';
					}
					else if (rotate.front().second == 'D') {
						direction = 'N';
					}
				}
				else if (direction == 'S') {
					if (rotate.front().second == 'L') {
						direction = 'E';
					}
					else if (rotate.front().second == 'D') {
						direction = 'W';
					}
				}
				else if (direction == 'N') {
					if (rotate.front().second == 'L') {
						direction = 'W';
					}
					else if (rotate.front().second == 'D') {
						direction = 'E';
					}
				}
				rotate.pop();
				if (rotate.empty()) {
					break;
				}
			}
		}

		if (direction == 'E') {
			head.second++;
			body.emplace_back(head.first, head.second);
			for (auto it = apple.begin(); it != apple.end(); it++) {
				if (it->first == head.first && it->second == head.second) {
					isApple = true;
					apple.erase(it);
					break;
				}
			}

			for (int i = 0; i < body.size() - 1; i++) {
				if (head.first == body[i].first && head.second == body[i].second) {
					flag = true;
					break;
				}
			}

			if (!isApple) {
				body.erase(body.begin());
			}
		}
		else if (direction == 'W') {
			head.second--;
			body.emplace_back(head.first, head.second);
			for (auto it = apple.begin(); it != apple.end(); it++) {
				if (it->first == head.first && it->second == head.second) {
					isApple = true;
					apple.erase(it);
					break;
				}
			}

			for (int i = 0; i < body.size() - 1; i++) {
				if (head.first == body[i].first && head.second == body[i].second) {
					flag = true;
					break;
				}
			}

			if (!isApple) {
				body.erase(body.begin());
			}
		}
		else if (direction == 'S') {
			head.first++;
			body.emplace_back(head.first, head.second);
			for (auto it = apple.begin(); it != apple.end(); it++) {
				if (it->first == head.first && it->second == head.second) {
					isApple = true;
					apple.erase(it);
					break;
				}
			}

			for (int i = 0; i < body.size() - 1; i++) {
				if (head.first == body[i].first && head.second == body[i].second) {
					flag = true;
					break;
				}
			}

			if (!isApple) {
				body.erase(body.begin());
			}
		}
		else if (direction == 'N') {
			head.first--;
			body.emplace_back(head.first, head.second);
			for (auto it = apple.begin(); it != apple.end(); it++) {
				if (it->first == head.first && it->second == head.second) {
					isApple = true;
					apple.erase(it);
					break;
				}
			}

			for (int i = 0; i < body.size() - 1; i++) {
				if (head.first == body[i].first && head.second == body[i].second) {
					flag = true;
					break;
				}
			}

			if (!isApple) {
				body.erase(body.begin());
			}
		}

		if (head.first > N || head.first < 1 || head.second > N || head.second < 1) {
			flag = true;
		}

		isApple = false;
	}
	cout << t;
}