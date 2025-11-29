#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    vector<int> result;

    if (A >= B) {
        int cur = A;
        int steps = A - B;
        cout << steps << "\n";
        for (int i = 0; i < steps; i++) {
            cur -= 1;
            result.push_back(cur);
        }
        for (int x : result) cout << x << " ";
        return 0;
    }

    vector<int> rev;
    int x = B;
    while (x > A) {
        if (x % 2 == 0) {
            x /= 2;
            rev.push_back(0);
        } else {
            x += 1;
            rev.push_back(1);
        }
    }

    int extra = A - x;
    int steps = rev.size() + extra;
    cout << steps << "\n";

    int cur = A;
    for (int i = 0; i < extra; i++) {
        cur -= 1;
        result.push_back(cur);
    }

    for (int i = rev.size() - 1; i >= 0; i--) {
        if (rev[i] == 0) cur *= 2;
        else cur -= 1;
        result.push_back(cur);
    }

    for (int v : result) cout << v << " ";
}
