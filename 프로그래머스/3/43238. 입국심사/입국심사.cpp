#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left, right;
    left = 1; right = (long long)*max_element(times.begin(), times.end()) * n;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long total_people = 0;
        
        for (const auto& t : times) {
            total_people += (mid / t);
            if (total_people >= n) break;
        }
        
        if (total_people >= n) {
            answer = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    
    return answer;
}
// nums[0] + ,,, nums[len - 1] = n
// total_times[i] = times[i] * num[i]
// n을 0부터 len-1까지 잘 분배해서 total_times 원소의 최댓값이 최소가 되는 경우 찾기
// 1 ~ times.back() * n 범위에서 조건을 만족하는 최솟값 찾기
// t = 20 가정 시 (20/10) + (20/11) + (20/12) + (20/13) + (20/14) + (20/50) = 6 가능

//       times         
// 10 11 12 13 14 50
//  0  0  0  0  0  0
//  2  1  1  1  1  0

// 6명 가정

// n: 입국심사 대상자
// times: 각 심사관의 심사 시간
// return: 모든 사람 심사 받는 데 걸리는 시간 최솟값
// 1 <= n <= 10^9
// 1 <= times[i] <= 10^9
// 1 <= times.size() <= 10^5