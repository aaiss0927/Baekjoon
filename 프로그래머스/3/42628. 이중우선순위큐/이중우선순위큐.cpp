#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    // 1. 최대 힙과 최소 힙 준비
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    
    // 2. 숫자의 존재 여부(개수)를 관리할 맵 (Lazy Deletion의 핵심)
    map<int, int> counts; 
    int valid_size = 0; // 현재 큐에 있는 실제 유효한 숫자의 개수

    for (const string& op : operations) {
        char cmd = op[0];
        int num = stoi(op.substr(2));

        if (cmd == 'I') {
            max_pq.push(num);
            min_pq.push(num);
            counts[num]++;
            valid_size++;
        } 
        else if (valid_size > 0) { // 삭제 연산 (유효한 숫자가 있을 때만)
            if (num == 1) { // 최댓값 삭제
                // 청소: 이미 다른 곳에서 삭제된 놈은 pop
                while (!max_pq.empty() && counts[max_pq.top()] == 0) {
                    max_pq.pop();
                }
                if (!max_pq.empty()) {
                    counts[max_pq.top()]--;
                    max_pq.pop();
                    valid_size--;
                }
            } 
            else { // 최솟값 삭제
                // 청소: 이미 다른 곳에서 삭제된 놈은 pop
                while (!min_pq.empty() && counts[min_pq.top()] == 0) {
                    min_pq.pop();
                }
                if (!min_pq.empty()) {
                    counts[min_pq.top()]--;
                    min_pq.pop();
                    valid_size--;
                }
            }
        }
    }

    // 최종 결과 전 마지막 청소
    while (!max_pq.empty() && counts[max_pq.top()] == 0) max_pq.pop();
    while (!min_pq.empty() && counts[min_pq.top()] == 0) min_pq.pop();

    if (valid_size == 0) return {0, 0};
    return {max_pq.top(), min_pq.top()};
}