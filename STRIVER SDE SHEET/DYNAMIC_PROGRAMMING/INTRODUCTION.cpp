// "Those who cannot remember the past are condemned to repeat it..." - Famous Dynamic Programming Quote.

/*
    * RESOURCES:
        - https://takeuforward.org/data-structure/dynamic-programming-introduction/
*/

/*  
    * Prerequisites: Recusion.
    * Solving Problems: 1. Tabulation Method 2. Memoization Method
                           - Bottom Up          - Top Down
                           - 0 to N - 1         - 0 to N
                           - or vice versa.     - or vice versa.
    * Fibonacci Numbers:
        - f(n) = f(n - 1) + f(n - 2)
        - There is sometimes no need to compute some function nodes in the recursion tree as it 
          has been already computed before. (Overlapping Subproblems)
        - This is where memoization jumps in, we store values of sub problems in map / table.
        - We can create an array of size 6, if we are calculating f(5), initialized with -1.
        - Store values returned by f(n) in dp[n]
        - Check whether dp[n] == -1 inside the function. (subproblem not encountered)
    * Memoization: - TC = O(N) - SC = O(N) + O(N) -> recursion stack space + array extra space.
    * Tabulation:
        - We go from the base case to the required case in contrast to recusrsion where we take
          top down approach.
        - Base cases for fibonacci: dp[0] = 0, dp[1] = 1.
        - Next, run a for loop from 2 to n.
        - dp[i] = dp[i - 1] + dp[i - 2] inside the loop.
        - TC = O(N), SC = O(N) -> No recusion stack space.
        - We can reduce the SC to O(1), we dont need an array.
        - Initialize two variables prev1 and prev2 with 0 and 1.
        - Next, run a for loop from 2 to n.
        - curr = pre1 and prev2
        - Then roll over 1 step to make iteration ready to calculate next fibonacci number.
*/
#include <bits/stdc++.h>
using namespace std;

// Always take the vector as reference.
int fib(int n, vector<int> &dp){
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fib(n, dp);
    return 0;
}

/*
    RESOURCES:
        - https://takeuforward.org/data-structure/dynamic-programming-introduction/
*/