#include <bits/stdc++.h>
using namespace std;

int N;

struct Element {
	int num;
	int s_idx;

	Element() {
		num = 1001;
		s_idx = -1;
	}

	Element(int num) {
		this->num = num;
		s_idx = -1;
	}
};

class Deque {
private:
	Element* arr;
	int size;

public:
	Deque() {
		arr = new Element[N];
		size = 0;
	}

	void push_front(Element e) {
		size++;
		for (int i = size - 1; i >= 1; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = e;
	}

	void push_back(Element e) {
		arr[size++] = e;
	}

	void pop_front() {
		for (int i = 0; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}

	void pop_back() {
		size--;
	}

	Element front() {
		return arr[0];
	}

	Element back() {
		return arr[size - 1];
	}

	int getNum(int idx) {
		return arr[idx].num;
	}
	
	int getS_idx(int idx) {
		return arr[idx].s_idx;
	}

	int getSize() {
		return size;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	Deque dq;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		Element e = Element(num);
		e.s_idx = i;
		dq.push_back(e);
	}
	
	cout << 1 << " ";
	while (dq.getSize() > 2) {
		int count = dq.getNum(0);
		dq.pop_front();

		if (count > 0) {
			for (int i = 0; i < count - 1; i++) {
				Element e = dq.front();
				dq.pop_front();
				dq.push_back(e);
			}
		}

		else {
			count = -count;
			for (int i = 0; i < count; i++) {
				Element e = dq.back();
				dq.pop_back();
				dq.push_front(e);
			}
		}

		cout << dq.front().s_idx + 1 << " ";
	}
	cout << dq.back().s_idx + 1;
}