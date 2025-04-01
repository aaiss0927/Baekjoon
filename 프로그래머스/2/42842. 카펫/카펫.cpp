#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> quadratic_formula(int a, int b, int c) {
    int x_1, x_2;
    x_1 = (-b + pow((pow(b, 2) - 4 * a * c), 0.5)) / (2 * a);
    x_2 = (-b - pow((pow(b, 2) - 4 * a * c), 0.5)) / (2 * a);
    if (x_1 < x_2) swap(x_1, x_2);
    return {x_1, x_2};
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int w, h;
    int total = brown + yellow;
    int a, b, c;
    a = 1;
    b = -(brown + 4) / 2;
    c = total;
    answer = quadratic_formula(a, b, c);
    return answer;
}

// w * h, w >= h
// total = w * h = 12
// yellow = (w - 2) * (h - 2) = wh - 2(w + h) + 4 = 2
// brown = total - tellow = 2(w + h) - 4 = 10 => w + h = 7