// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// Detected time complexity: O(1)
// https://app.codility.com/demo/results/trainingJHB9GK-AA7/
int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    if (X == Y) return 0;
    return ((Y - X) % D == 0) ? (Y - X) / D : (Y - X) / D + 1;
}