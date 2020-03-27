// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// Detected time complexity: O(N) or O(N * log(N))
// [1,000,000,000] Case 주의하자!
// https://app.codility.com/demo/results/trainingQKY9QF-NQH/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = (int) A.size();
    vector<int> checked(size);
    for (auto& a : A)
    {
        if (a > size) continue;
        checked[a-1]++;
    }
    
    for (auto& c : checked)
    {
        if (c != 1) return 0;
    }
    return 1;
}