#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    string a_string = to_string(a);
    string b_string = to_string(b);
    
    return (a_string + b_string) > (b_string + a_string);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    
    for (int i = 0; i < numbers.size(); i++)
        answer += to_string(numbers[i]);
    
    int idx = 0;
    while (answer[idx] == '0') idx++;
    if (idx == answer.length()) idx--;
    answer = answer.substr(idx, answer.length());
    
    return answer;
}