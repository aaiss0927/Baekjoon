#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s; // 가격이 떨어지지 않은 시점의 '인덱스'를 저장

    for (int i = 0; i < n; i++) {
        // 하락장을 만났을 때 (현재 가격 < 스택 TOP 가격)
        while (!s.empty() && prices[s.top()] > prices[i]) {
            int top_idx = s.top();
            s.pop();
            answer[top_idx] = i - top_idx; // 버틴 시간 기록
        }
        s.push(i); // 현재 시점 저장
    }

    // 끝까지 가격이 떨어지지 않은 인덱스들 처리
    while (!s.empty()) {
        int top_idx = s.top();
        s.pop();
        answer[top_idx] = n - 1 - top_idx;
    }

    return answer;
}