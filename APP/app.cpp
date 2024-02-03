#include<iostream>
using namespace std;

int count_dig(int x){
    int x_copy = x, count = 0;
    while(x){
        if(x_copy % (x % 10) == 0 && (x % 10) != 0)
            count++;
        x /= 10;
    }
    return count;
}

int main(){
    int x;
    cin >> x;
    cout << count_dig(x) << endl;
    return 0;
}