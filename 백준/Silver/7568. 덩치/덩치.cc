#include <bits/stdc++.h>
using namespace std;

class Person {
private:
	int weight, length;
public:
	int rank = 1;
	Person()
		: weight(0), length(0) {}
	Person(int weight_, int length_)
		:weight(weight_), length(length_) {}
	bool operator<(Person right) {
		if (this->weight < right.weight && this->length < right.length) {
			return true;
		}
		return false;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<Person> person(N);
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		person[i] = Person(x, y);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (person[i] < person[j]) {
				person[i].rank++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << person[i].rank << ' ';
	}
}