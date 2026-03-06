#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<int>& numbers, int idx, int sum, int target, int& answer) {
    if (idx >= numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    
    int cur = numbers[idx];
    dfs(numbers, idx + 1, sum + cur, target, answer);
    dfs(numbers, idx + 1, sum - cur, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, 0, target, answer);
    return answer;
}

// 2 <= numbers.size() <= 20
// 1 <= numbers[i] <= 50
// 1 <= target <= 1000
// 각 numbers[i] 더하거나 빼서 target 만들기
// return: target 만드는 방법의 수

// 4
// 1     -1
// 2 -2   2 -2