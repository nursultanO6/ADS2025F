#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    long long x;
    cin >> x;
    priority_queue<int,vector<int>,greater<int>>arr;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        arr.push(a);
    }
    
    long long sum = 0;
    int ans3 = 0;
    while(arr.size() > 1 && arr.top() < x){
        int ans = arr.top();
        arr.pop();
        int ans2 = arr.top();
        arr.pop();
        ans3 = ans + (ans2 * 2);
        sum++;
        arr.push(ans3);
    }
    if(x <= ans3 || arr.top() >= x) cout << sum;
    else cout << -1;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    long long x;
    cin >> x;
    priority_queue<int,vector<int>,greater<int>>arr;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        arr.push(a);
    }
    
    long long sum = 0;
    long long ans3 = 0;
    while(arr.size() > 1 && arr.top() < x){
        long long ans = arr.top();
        arr.pop();
        long long ans2 = arr.top();
        arr.pop();
        ans3 = ans + (ans2 * 2);
        sum++;
        arr.push(ans3);
    }
    if(x <= ans3 || arr.top() >= x) cout << sum;
    else cout << -1;
}