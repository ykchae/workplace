// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


// https://app.codility.com/demo/results/training294AUT-V8W/ --> 62 point
// https://stackoverflow.com/questions/4801242/algorithm-to-calculate-number-of-intersecting-discs
// Falk Hüffner's idea
/*
int number_of_disc_intersections ( const vector<int> &A ) {
    int sum=0;
    vector<int> start(A.size(),0);
    vector<int> end(A.size(),0);
    for (unsigned int i=0;i<A.size();i++){
        if ((int)i<A[i]) start[0]++;
        else        start[i-A[i]]++;
        if (i+A[i]>=A.size())   end[A.size()-1]++;
        else                    end[i+A[i]]++;
    }
    int active=0;
    for (unsigned int i=0;i<A.size();i++){
        sum+=active*start[i]+(start[i]*(start[i]-1))/2;
        if (sum>10000000) return -1;
        active+=start[i]-end[i];
    }
    return sum;
}
*/
struct Disc {
    int min;
    int max;
};

bool isOverlapped(int val, int min, int max) {
    if (max >= val && val >= min) {
        return true;
    }
    return false;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    int size = static_cast<int>(A.size());
    for (int i = 0; i < size-1; i++) {
        Disc a;
        a.min = i - A[i];
        a.max = i + A[i];
        for (int j = i+1; j < size; j++) {
            Disc b;
            b.min = j - A[j];
            b.max = j + A[j];
            
            if (isOverlapped(a.min, b.min, b.max) || isOverlapped(a.max, b.min, b.max)
            || isOverlapped(b.min, a.min, a.max) || isOverlapped(b.max, a.min, a.max)) {
                ans++;
            }
        }
    }
    
    return (ans > 10000000) ? -1 : ans;
}