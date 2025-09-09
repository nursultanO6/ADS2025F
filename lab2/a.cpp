#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int list[n];
    for(int i = 0;i < n; i++){
        cin >> list[i];
    }
    int k; cin >> k;
    int diff[n];
    int min = abs(list[0] - k);
    int idx = 0;
    for(int i = 1; i <n; i++){
        diff[i] = abs(list[i] - k);
        if(diff[i] < min){
            min = diff[i];
            idx = i;
        }
    }
    cout << idx;
}