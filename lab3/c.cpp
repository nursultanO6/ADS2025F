#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while(q--){
        int cnt = 0;
        int l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
        for(int i = 0; i < n; i++){
            if((v[i] >= l1 && v[i] <= r1) || (v[i] >= l2 && v[i] <= r2)){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}

