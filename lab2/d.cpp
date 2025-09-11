#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    map<int,int> ads;
    for(int i = 0; i<n; i++){
        int k; cin >>k;
        ads[k]++;
    }
    int max = 0;
     for(pair<int, int> i : ads){
        if(i.second > max){
            max = i.second;
        }
    }
    map <int, int> :: reverse_iterator it;
    for(it = ads.rbegin(); it != ads.rend(); it++){
        if(max == it->second){
            cout << it->first << ' ';
        }
    }

}