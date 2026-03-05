#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int, int> m;
    
    for (int i = 1; i <= n; i++) m[i]++;
    for (const auto& l : lost) m[l]--;
    for (const auto& r : reserve) m[r]++;
    
    for (int i = 1; i <= n; i++) {
        if (m[i] == 0) {
            if (m[i - 1] >= 2) {
                m[i]++;
                m[i - 1]--;
            }
            
            else if (m[i + 1] >= 2) {
                m[i]++;
                m[i + 1]--;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (m[i] >= 1) answer++;
    }
    
    return answer;
}

// 번호 체격 순
// 1 2 3 4 5
// 2 0 2 0 2

// 1 2 3 4 5
// 1 0 2 0 1