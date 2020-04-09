#include <algorithm>

// 풀이법: 제일 작은 값(음수*음수=양수)과의 곱과 제일 큰 값들과의 곱을 비교하기
// Detected time complexity: O(N * log(N))
// https://app.codility.com/demo/results/training3A55DA-554/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int maximal = 0;

    sort(A.begin(), A.end(), greater<int>());
    maximal = A[0] * A[1] * A[2];
    
    int size = static_cast<int>(A.size());
    if (A[size-1] < 0 && A[size-2] < 0 )
    {
        int product = A[0] * A[size-1] * A[size-2];
        if (maximal < product) maximal = product;
    }
    
    return maximal;
}