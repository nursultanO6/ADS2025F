#include <bits\stdc++.h>
using namespace std;
int main(){
    int n, k;cin >> n >> k;
    vector<long long> block(n);
    for(int i = 0; i < n; i++){
        cin >> block[i];
        if(i > 0)block[i] += block[i-1];
    }
    // for(int i = 0; i < n; i++){
    //     cout << block[i] << endl;
    // }
    
    for(int i = 0; i < k; i++){
        int m; cin >> m;
        
        int l = 0, r = n-1, ans = n;
        while(l <= r){
            int mid = (l+r)/2;
            if(block[mid] >= m){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << ans + 1<< endl;
    }
}