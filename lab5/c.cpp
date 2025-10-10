#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    long long x;
    cin >> x;
    priority_queue<long long> arr;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        arr.push(a);
    }
    long long sum = 0;

    while(x--){
        sum += arr.top();
        long long t = arr.top();
        arr.pop();
        arr.push(t-1);
    }
    cout << sum;
}
