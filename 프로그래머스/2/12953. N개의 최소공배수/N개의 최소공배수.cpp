#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void prime_decomposition(int n) {
    
}

int solution(vector<int> arr) {
    int answer = 1;
    
    vector<int> prime_arr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
                            61, 67, 71, 73, 79, 83, 89, 97};
    vector<int> prime_decomp_cnt(101, 0);
    
    for (int n : arr) {        
        for (auto p : prime_arr) {
            int cnt = 0;
            
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            
            prime_decomp_cnt[p] = max(prime_decomp_cnt[p], cnt);
        }
    }
    
    for (int i = 1; i < 101; i++) {
        if (prime_decomp_cnt[i])
            answer *= pow(i, prime_decomp_cnt[i]);
    }
    
    return answer;
}

// 2 = 2^1
// 6 = 2^1 * 3^1
// 8 = 2^3
// 14 = 2^1 * 7^1
// lcm = 2^3 * 3^1 * 7^1

// 1 ~ 100 자연수 배열 arr
// 각 원소 소인수분해
// 1 ~ 100 소수 배열 prime
// prime의 각 원소 max 값 채택