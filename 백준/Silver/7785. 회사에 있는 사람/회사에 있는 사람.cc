#include <iostream>
#include <set>

using namespace std;

int main() {
	set<string> s;
	int N; cin >> N;
	string name, cmd;
	
	while (N--) {
		cin >> name >> cmd;
		if (cmd == "enter") {
			s.insert(name);
		}
		else if (cmd == "leave") {
			s.erase(name);
		}
	}

	set<string>::reverse_iterator r_it;
	for (r_it = s.rbegin(); r_it != s.rend(); r_it++) {
		cout << *r_it << '\n';
	}
}