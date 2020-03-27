#include <algorithm>
#include <vector>

// https://app.codility.com/demo/results/trainingS468R9-VK4/
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    bool isStart = false;
    int binary = N;
    
    vector<int> vec;
    int gap = 0;
    while (binary > 0)
    {
        int change = binary % 2;
        if (isStart && change == 0) gap++;
        else if (change == 1) {
            isStart = true;
            vec.push_back(gap);
            gap = 0;
        }
        binary /= 2;
    }
    
    return *std::max_element(vec.begin(), vec.end());
}