#include <bits/stdc++.h>
using namespace std;

/* 
    Multiple recursion calls get executed serially, not simultaneously.
    Keep this in mind while dry running the vertical recursion tree.
*/
int get_fibonacci(int n) {
    if (n <= 1) return n;
    return get_fibonacci(n - 1) + get_fibonacci(n - 2);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cout << get_fibonacci(6) << "\n";
    return 0;
}