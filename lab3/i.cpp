#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    cin >> t;

    int l = 0, r = n - 1;
    bool found = false;
    while (l <= r) {
        int m = (l + r) / 2;
        if (list[m] == t) {
            found = true;
            break;
        } else if (list[m] > t) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    if (found) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
