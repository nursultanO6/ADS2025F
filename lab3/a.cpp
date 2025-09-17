#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    int list[t];
    for(int i = 0; i < t; i++)cin >> list[i];
    int n, m; cin >> n >> m;
    int list2[n][m];
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            cin >> list2[i][j];
        }
    }
    int k = 0;
    while(t--){
        bool tr = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j < m; j++){
                if(list[k] == list2[i][j]){
                    cout << i << " " << j << endl;
                    tr = 1;
                    break;
                }
            }
            if(tr)break;
        }if(!tr)cout << "-1" << endl;
        k++;
    }
}