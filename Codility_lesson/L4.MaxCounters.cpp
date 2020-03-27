// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// [문제] 명령어 배열(A)를 실행한 Counter 결과 리턴하기
// cond1. A[K] = X, 1 <= X <= N 이면, K는 increase(X)
// cond2. A[K] = N + 1 이면, K는 max counter
// [풀이] Max Counter 명령어(N+1) 를 효율적으로 수행하는 것이 핵심!

// Detected time complexity: O(N + M) --> Big-O Notation
// https://app.codility.com/demo/results/trainingC9TGFY-NNH/
vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector<int> result(N);

    int maxCounter = 0;
    int working = 0;

    for (const auto& a : A)
    {
        
        if (a - 1 == N)
        {
            maxCounter = working;
        }
        else
        {
			// 핵심문장!
            if (maxCounter > result[a - 1])
            {
                result[a - 1] = maxCounter;
            }
            result[a - 1]++;
            working = (result[a - 1] > working) ? result[a - 1] : working;
        }
    }
    
    if (maxCounter > 0)
    {
        for (auto& val : result)
        {
            val = std::max(val, maxCounter);
        }
    }
    
    return result;
}