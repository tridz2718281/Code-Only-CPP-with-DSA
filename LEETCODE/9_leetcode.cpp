#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor){
    int i, count;
    bool resPos = ! ((dividend < 0) ^ (divisor < 0));
    cout << resPos << "\n";
    for (i = 0, count = 0; i <= dividend; i += divisor, ++count);
    return resPos * (--count);
}

int main(){
    cout << divide(-9, -4) << "\n";
    return 0;
}