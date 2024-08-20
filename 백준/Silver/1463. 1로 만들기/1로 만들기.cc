#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<bool> visited;
queue<int> q;
vector<int> s_p;

void bfs() {
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (s_p[n] != -1)
			return;

		if (!(cur + 1 > n) && !visited[cur + 1]) {
			visited[cur + 1] = true;
			s_p[cur + 1] = s_p[cur] + 1;
			q.push(cur + 1);
		}
		
		if (!(cur * 2 > n) && !visited[cur * 2]) {
			visited[cur * 2] = true;
			s_p[cur * 2] = s_p[cur] + 1;
			q.push(cur * 2);
		}
			

		if (!(cur * 3 > n) && !visited[cur * 3]) {
			visited[cur * 3] = true;
			s_p[cur * 3] = s_p[cur] + 1;
			q.push(cur * 3);
		}
	}
}

int main() {
	cin >> n;
	visited = vector<bool>(n + 1, false);
	s_p = vector<int>(n + 1, -1);

	q.push(1);
	visited[1] = true;
	s_p[1] = 0;
	bfs();
	cout << s_p[n];
}