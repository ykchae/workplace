// you can use includes, for example:
#include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// 구간별 합을 미리 구해놓고 중첩for문 없애기
// Detected time complexity: O(N)
// https://app.codility.com/demo/results/training4CNRCA-EKC/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int sumPart1 = 0;   // sum to begin
    int sumPart2 = 0;   // sum from end
    for (auto& a : A)
    {
        sumPart2 += a;
    }
    
    int min = INT32_MAX;
    for (int i = 0; i < static_cast<int>(A.size())-1; i++)
    {
        sumPart1 += A[i];
        sumPart2 -= A[i];
        
        int val = std::abs(sumPart1-sumPart2);
        if (min > val)
            min = val;
    }
    
    return min;
}
