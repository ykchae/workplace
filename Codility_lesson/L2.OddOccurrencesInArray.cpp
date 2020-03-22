// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// [Solution] sorting >> find unpaired value
// ** Detected time complexity: O(N) or O(N*log(N))
// https://app.codility.com/demo/results/trainingVJRFWP-TFS/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    std::sort(A.begin(), A.end());
    
    for (int i = 0; i < static_cast<int>(A.size()); i += 2)
    {
        if (i+1 > static_cast<int>(A.size()))
            return A[i];
        if (A[i] != A[i+1])
            return A[i];
    }
    
    return A[0];
}