#include <string>
#include <vector>
using namespace std;

vector<int> numbers;
vector<int> v;
int target;
int total;

void bt(int n, int sum) {
    if (n == numbers.size()) {
        if (sum == target) total++;
        return;
    }
    
    bt(n + 1, sum + numbers[n]);
    bt(n + 1, sum - numbers[n]);
}

int solution(vector<int> inp_numbers, int inp_target) {
    int answer = 0;
    numbers = inp_numbers;
    target = inp_target;
    bt(1, numbers[0]);
    bt(1, -numbers[0]);
    answer = total;
    return answer;
}