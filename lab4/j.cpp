#include <bits/stdc++.h>
using namespace std;

vector<int> result;

void takeMedians(const vector<int>& arr, int l, int r) {
    if (l > r) return;
    int mid = (l + r) / 2;
    result.push_back(arr[mid]);
    takeMedians(arr, l, mid - 1);
    takeMedians(arr, mid + 1, r);
}

int main() {
    int n; 
    cin >> n;
    int total = (1 << n) - 1;

    vector<int> arr(total);
    for (int i = 0; i < total; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    takeMedians(arr, 0, total - 1);

    for(int i : result)cout << i << " ";
    return 0;
}