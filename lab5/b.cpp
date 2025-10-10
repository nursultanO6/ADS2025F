#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    priority_queue<long long> arr;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        arr.push(a);
    }

    while (arr.size() > 1) {
        long long a = arr.top(); arr.pop();
        long long b = arr.top(); arr.pop();
        long long diff = abs(a - b);
        if (diff > 0) arr.push(diff);
    }

    if (!arr.empty())
        cout << arr.top();
    else
        cout << 0;

    return 0;
}
