// you can use includes, for example:
#include <algorithm>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// 배열에 없는 최소 양의 정수값을 리턴하시오
// Detected time complexity: O(N) or O(N * log(N))
// https://app.codility.com/demo/results/training537M75-E6M/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    auto minmax = std::minmax_element(A.begin(), A.end());
    if (*minmax.second < 0 || *minmax.first > 1) return 1;
    else {
        set<int> sortedSet(A.begin(), A.end());
        int count = 1;
        for (auto& s : sortedSet)
        {
            if (s <= 0) continue;
            else if(count != s) return count;
            count++;
        }
        return count;
    }
}