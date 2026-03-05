#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int cnt = 0;
bool is_not_prime[10000000];

void chae() {
    is_not_prime[0] = is_not_prime[1] = true;
    
    for (int i = 2; i < 10000; i++) {
        if (is_not_prime[i]) continue;
        
        for (int j = 2 * i; j < 10000000; j += i)
            is_not_prime[j] = true;
    }
}
// 1  2  3  4  5  6  7  8  9  10
// 11 12 13 14 15 16 17 18 19 20
// 소수 아닌 것 체크
// 초기 is_not_prime은 모두 false <=> 일단 모두 소수로 체크 됨

vector<char> v;
set<int> s;
bool is_used[7];

void bt(const string& numbers, int target_len) {    
    if (v.size() == target_len) {
        string temp = "";
        
        for (const auto& v_ : v)
            temp += v_;
        
        int result = stoi(temp);
            
        if (!is_not_prime[result] && s.find(result) == s.end()) {
            s.insert(result);
            cnt++;
        }
        
        return;
    }
    
    for (int i = 0; i < numbers.length(); i++) {
        if (is_used[i]) continue;
        
        v.push_back(numbers[i]);
        is_used[i] = true;
        bt(numbers, target_len);
        is_used[i] = false;
        v.pop_back();
    }
}
// numbers를 벡터로 쪼갬 => {0, 1, 1}
// v에 numbers[0 ~ numbers.size() - 1] 넣었다 빼기
// v.size() == numbers.size()면 return
int solution(string numbers) {
    chae();
    
    for (int i = 1; i <= numbers.length(); i++)
        bt(numbers, i);
    
    return cnt;
}

// 1 <= numbers.size() <= 7
// 0 <= numbers[i] <= 9
// 0 <= final_num < 10^7

// _______
// 모든 경우의 수: 9 * 10^6 ~= 10^7 => 백트래킹 가능