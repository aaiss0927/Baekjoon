#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

void pq_printer(priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq) {
    while (!pq.empty()) {
        cout << get<0>(pq.top()) << ' ' << get<1>(pq.top()) << ' ' << get<2>(pq.top()) << '\n';
        pq.pop();
    }
}

void q_printer(queue<tuple<int, int, int>> q) {
    while (!q.empty()) {
        cout << get<0>(q.front()) << ' ' << get<1>(q.front()) << ' ' << get<2>(q.front()) << '\n';
        q.pop();
    }
}

bool cmp(vector<int> v1, vector<int> v2) {
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}

int solution(vector<vector<int>> jobs) {
    long long answer = 0;
    long long total = 0;
    int t = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    queue<tuple<int, int, int>> q;
    // for (int i = 0; i < jobs.size(); i++) {
    //     for (int j = 0; j < 2; j++) {
    //         cout << jobs[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    sort(jobs.begin(), jobs.end(), cmp);
    
    for (int i = 0; i < jobs.size(); i++) q.push({jobs[i][1], jobs[i][0], i});
    
    while (!q.empty() || !pq.empty()) {
        // pq_printer(pq);
        while (!q.empty() && (t >= get<1>(q.front()))) {
            pq.push(q.front());
            q.pop();
        }
        
        if (!pq.empty()) {
            // cout << "t: " << t << " total: " << total << " / " << get<0>(pq.top()) << ' ' << get<1>(pq.top()) << '\n';
            t += get<0>(pq.top());
            total += (t - get<1>(pq.top()));
            pq.pop();
        }
        else t = get<1>(q.front());
    }
    
    answer = total / jobs.size();
    return answer;
}

// [[0, 1000], [1, 1000], ,,, , [500, 1000]]  1 : 1000에 끝, 2 : 2000에 끝, 500: 500000에 끝
// 0 ~ 3 작업, t = 3, total += (3 - 0) = 3
// t = 3 >= 3 ,,, 3 ~ 8 작업, t = 8, total += (8 - 3) => total = 8
// t = 8 >= 1 ,,, 8 ~ 17 작업, t = 17, total += (17 - 1) = 24

// jobs = {{요청 시각, 소요 시간}, ,,, }
// q = {{소요 시간, 요청 시각, 작업 번호}, ,,, }
// pq = {{소요 시간, 요청 시각, 작업 번호}, ,,, }
// 우선 순위: min(소요 시간), min(요청 시각), min(작업 번호)
// while(!work && !q.empty()) pq.pop();  