#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<bool> is_prime(10000000, true);

void check_prime() {
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= 10000000; i++) {
        if (is_prime[i] == false) continue;
        for (int j = i * 2; j <= 10000000; j += i) is_prime[j] = false;
    }
}

vector<char> v;
vector<bool> visited(7, false);
unordered_set<int> cand;

void bt(int n, string numbers) {
    if (v.size() == n) {
        string s = "";
        for (char c : v) s += c;
        int s_int = stoi(s);
        cand.insert(s_int);
        return;
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i]) continue;
        
        visited[i] = true;
        v.push_back(numbers[i]);
        bt(n, numbers);
        v.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    check_prime();
    for (int i = 1; i <= numbers.length(); i++) bt(i, numbers);
    for (auto it = cand.begin(); it != cand.end(); it++) if (is_prime[*it]) answer++;
    return answer;
}

// 1 <= n <= 7
// 실제 수 0 <= 9999999(10^7)
// 소수 판별
// 주어진 숫자 1개 ~ n개로 perm: 백트래킹

//  1  2  3  4  5  6  7  8  9 10
// 11 12 13 14 15 16 17 18 19 20