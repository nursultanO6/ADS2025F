#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t; cin >> n >> t;
    vector <int> list(n);
    for(int i = 0; i < n; i++){
        cin >> list[i];
    }
    int ans = n;
    int sum = 0, l = 0;
    for(int i = 0; i < n; i++){
        sum += list[i];

        while(sum >= t){
            ans= min(ans, i - l + 1);
            sum -= list[l];
            l++;
        }
    }
    cout << ans;
}