#include <bits/stdc++.h>
using namespace std;

bool chk_palindrome(int i, string &s){
    if (i >= s.size() / 2) return true;
    if (s[i] != s[s.size() - i - 1]) return false;
    chk_palindrome(i + 1, s);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    cout << chk_palindrome(0, s) << "\n";
    return 0;
}