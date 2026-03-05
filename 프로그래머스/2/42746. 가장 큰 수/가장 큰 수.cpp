#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp (const string& num1, const string& num2) {    
    return num1 + num2 > num2 + num1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_numbers;
    
    for (const auto& num : numbers)
        str_numbers.push_back(to_string(num));
    
    sort(str_numbers.begin(), str_numbers.end(), cmp);
    
    for (const auto& s_num : str_numbers) answer += s_num;
    if (answer.front() == '0') return "0";
    
    return answer;
}