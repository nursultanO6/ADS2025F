#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    deque<string> poem;
    for(int i = 0;i < n; i++){
        string s; cin >> s;
        poem.push_back(s);
    }
    while(k--){
        string ab = poem.front();
        poem.pop_front();
        poem.push_back(ab);
    }
    for(int i = 0;i < n; i++){
        cout << poem[i] << " ";
    }
}