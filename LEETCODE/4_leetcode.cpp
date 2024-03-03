#include <bits/stdc++.h>
using namespace std;

bool chk_pal(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i]) return false;
    return true;
}

string longest_substr(string s) {
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    int st = 2;
    int ed = s.find('o');
    cout << s.substr(st, ed - st + 1) << endl;
    return 0;
}