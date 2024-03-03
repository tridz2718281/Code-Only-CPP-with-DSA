#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int len = s.size();
    string filtered;
    for (int i = 0; i < len; i++){
        if (s[i] == ' ') continue;
        else if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+')){
            break;
        }
        else{
            filtered += s[i];
        }
    }
    if(filtered.empty()) return 0;
    long long result =  stoll(filtered);
    if (result < INT_MIN) return INT_MIN;
    else if (result > INT_MAX) return INT_MAX;
    else return result;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    cout << myAtoi(s) << "\n";
    return 0;
}
