#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    queue<int> K,S;
    for(int i = 0; i < n;i++){
        if(s[i] == 'S'){
            S.push(i);
        }else{
            K.push(i);
        }
    }

    while(!K.empty() && !S.empty()){
        int ids = S.front();
        int idk = K.front();

        S.pop();
        K.pop();

        if(ids < idk){
            S.push(n + idk);
        }else{
            K.push(n + ids);
        }
    }
    cout << (K.empty() ? "SAKAYANAGI" : "KATSURAGI");
    return 0;
}