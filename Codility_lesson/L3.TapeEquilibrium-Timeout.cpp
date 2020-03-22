// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// Detected time complexity: O(N * N) ---> Timeout
// https://app.codility.com/demo/results/trainingUA7Y97-UQS/
int getSum(int index, int P, int val, vector<int> &A);

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int size = static_cast<int>(A.size());

    int min = *std::max_element(A.begin(), A.end());
    for (int i = 1; i < size; i++)
    {
        int part1 = getSum(i-1, 0, A[i-1], A);
        int part2 = getSum(size-1, i, A[size-1], A);
        min = std::min(min, fabs(part1-part2));
    }
    return min;
}

int getSum(int index, int P, int val, vector<int> &A)
{
    if (P == index)
        return val;
    
    val += A[index-1];
    return getSum(index - 1, P, val, A);
}