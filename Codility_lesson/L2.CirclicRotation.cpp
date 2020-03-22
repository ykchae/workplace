// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// https://app.codility.com/demo/results/trainingZMMRMW-AGB/
vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int size = static_cast<int>(A.size());
    if (size == 0)
        return A;
    
    vector<int> result(size);   
    for (int i = 0; i < size; i++)
    {
        int index = (i + K) % size;
        result[index] = A[i];
    }
    
    return result;
}
