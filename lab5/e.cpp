#include <bits/stdc++.h>
using namespace std;

int main() {
    long long q; 
    cin >> q;
    long long k;
    cin >> k;
    priority_queue<long long, vector<long long>, greater<long long>> arr;
    long long sum = 0;
    while(q--){
        string s;
        cin >> s;
        if(s == "insert"){
            long long x; cin >> x;
            if(arr.size() < k){
                sum += x;
                arr.push(x);
            }else if(x > arr.top()){
                sum -= arr.top();
                arr.pop();
                arr.push(x);
                sum += x;
            }
        }
        else{
            cout << sum << endl;
        }
    }
    
}