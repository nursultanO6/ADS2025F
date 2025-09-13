#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    while (n--) {
        int k; 
        cin >> k;
        queue<char> q;
        int freq[26] = {0};

        for (int i = 0; i < k; i++) {
            char ch; 
            cin >> ch;
            freq[ch - 'a']++;
            q.push(ch);

            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            if (q.empty()) cout << -1 << " ";
            else cout << q.front() << " ";
        }
        cout << endl;
    }
    return 0;
}
