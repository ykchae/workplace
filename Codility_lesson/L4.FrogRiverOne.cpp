// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// [문제] 개구리 강 건너기 : 순열
// 다시 풀어볼 것! https://wayhome25.github.io/algorithm/2017/05/30/FrogRiverOne/
// Detected time complexity: O(N)
// https://app.codility.com/demo/results/trainingM6629K-VHF/
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> check(X);
    int check_sum = 0;
    for (int i = 0; i < static_cast<int>(A.size()); i++)
    {
        if (check[A[i]-1] == 0)
        {
            check[A[i]-1] = 1;
            check_sum += 1;

            if (check_sum == X) return i;
        }
    }
    return -1;
}