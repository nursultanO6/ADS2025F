#include <bits/stdc++.h>
using namespace std;
int binary(const vector<int>& v, long long target) {
    int l = 0, r = v.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (v[m] <= target) l = m + 1;
        else r = m;
    }
    return l;
}
int main(){
    int n;cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int r; cin >> r;
    while(r--){
        int p, sum = 0; cin >> p;
        int nu = binary(v, p);
        for(int i = 0; i<nu; i++){
            sum += v[i];
        }
        cout << nu << " " << sum << endl;
    }
    
}

