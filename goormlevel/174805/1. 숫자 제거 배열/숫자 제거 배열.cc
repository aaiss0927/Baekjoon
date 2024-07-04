#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, K; cin >> N >> K;
	int cnt = 0;
	
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		
		string str_k = to_string(K);
		string str_a = to_string(a);
		if (str_a.find(str_k) == -1) {
			cnt++;
		}
	}
	
	cout << cnt;
}