// you can use includes, for example:
#include <algorithm>
#include <cmath>

// 배열의 절반 이하로 겹치는 숫자는 -1을 리턴, 반대인 경우는 dominator의 index 리턴
// Detected time complexity: O(N*log(N)) or O(N)
// https://app.codility.com/demo/results/trainingJ69J8N-HQ5/
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) return -1;
    
    int elemCnt = (int) floor(A.size() / 2.0);
    vector<int> array(A);
    sort(array.begin(), array.end());
    
    int dominator;
    int repeat = 0;
    int prev = A[0]-1;
    for (const auto& num : array) {
        if (prev == num) repeat++;
        else repeat = 1;
        if (repeat > elemCnt) {
            dominator = num;
            break;
        }
        prev = num;
    }
    
    if (repeat > elemCnt) {
        for (size_t i = 0; i < A.size(); i++)
        {
            if (dominator == A[i])
            {
                return i;
            }
        }
    }
    
    return -1;
}