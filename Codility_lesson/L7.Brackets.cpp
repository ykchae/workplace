// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// Stack 만들기!
// https://app.codility.com/demo/results/trainingTVJJE3-TKX/
#include <vector>
 // (), {}, []
static const int PARENTHESIS = 0;
static const int BRACE = 1;
static const int BRACKET = 2;

bool CheckOrder(const auto& vector, const char& sep)
{
    if (vector.empty()) return true;
    if (sep == ')' && vector[vector.size() - 1] == PARENTHESIS
        || sep == '}' && vector[vector.size() - 1] == BRACE
        || sep == ']' && vector[vector.size() - 1] == BRACKET) {
            return true;
    }
    return false;
}

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector<int> vec;
    for (const auto& ch : S)
    {
        // open case
        if (ch == '(') {
            vec.push_back(PARENTHESIS);
            continue;
        } else if (ch == '{') {
            vec.push_back(BRACE);
            continue;
        } else if (ch == '[') {
            vec.push_back(BRACKET);
            continue;
        }
        
        // close case
        bool isChecked = CheckOrder(vec, ch);
        if (isChecked && !vec.empty()) {
            vec.pop_back();
        } else {
            return 0;
        }
    }
    
    if (!vec.empty()) return 0;
    return 1;
}