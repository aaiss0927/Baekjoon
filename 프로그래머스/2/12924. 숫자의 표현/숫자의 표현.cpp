#include <string>
#include <vector>
using namespace std;

// 2 ... 1
// 4 ... 2
// 6 ... 3

// 9
// 1
// -1 0 1 2 3 4

// n 나누기 m
// m이 짝수일 때, 나눈 나머지가 m/2면 가능
// ... n/m - (m/2-1)가 0보다 커야함

// 15
// 3
// 3 4 5 6 7
// m이 홀수일 때, 나눈 나머지가 0이면 가능
// ... n/m - ((m-1)/2)가 0보다 커야함

int solution(int n) {
    int answer = 0;
    for (int m = 1; (m * (m + 1)) / 2 <= n; m++) {
        if (m % 2) {
            if ((n % m == 0) && ((n / m) - ((m - 1) / 2) > 0)) {
                answer++;
            }
        }
        
        else {
            if ((n % m == (m / 2)) && ((n / m) - (m / 2 - 1) > 0)) {
                answer++;
            }
        }
    }
    
    return answer;
}