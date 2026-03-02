#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    unordered_set<int> s;
    
    for (const auto& n : nums)
        s.insert(n);
    
    answer = min(s.size(), nums.size() / 2);
    
    return answer;
}