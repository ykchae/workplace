// you can use includes, for example:
#include <stack>

// Detected time complexity: O(N)
// https://app.codility.com/demo/results/trainingA2X2EF-4G8/
int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    
    stack<int> myStack;
    H.push_back(0);
    
    for (const auto& h : H) {
        if (myStack.empty() || myStack.top() <= h) {
            myStack.push(h);
        } else {
            while (!myStack.empty() && myStack.top() > h) {
                int current = myStack.top();
                myStack.pop();
                if (myStack.empty() || myStack.top() <= h || myStack.top() != current) {
                    ans++;
                }
            }
            myStack.push(h);
        }
    }
    return ans;
}