#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n; cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> arr;
    for(int i = 0; i < n; i++){
        long long a;cin >> a;
        arr.push(a);
    }
    long long sum = 0;
    while(arr.size() > 1){
      long long a = arr.top(); arr.pop();
      long long b = arr.top(); arr.pop();
      long long mins = a+b;
      sum+= mins;
      arr.push(mins);
    }
    cout << sum;

}