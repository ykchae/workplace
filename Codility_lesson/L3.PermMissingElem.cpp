// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// Detected time complexity: O(N) or O(N * log(N))
// https://app.codility.com/demo/results/trainingZ79A8W-327/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int size = static_cast<int>(A.size());

    vector<int> checked(size + 2);
	
    for (int i = 0; i < size; i++)
    {
        checked[A[i]] = 1;
    }
    
    for (int i = 1; i < size + 2; i++)
    {
        if (checked[i] == 0) return i;
    }
    return 1;
}
