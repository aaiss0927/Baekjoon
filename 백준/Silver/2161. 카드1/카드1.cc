#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (1) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}

		cout << q.front() << ' ';
		q.pop();		

		int top_card = q.front();
		q.pop();
		q.push(top_card);
	}
}