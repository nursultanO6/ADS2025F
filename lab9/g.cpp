#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
        
    int len = 0;  
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) { 
                len = lps[len - 1];  
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main() {
    string ss;
    cin >> ss;
    vector<int> lps = LPS(ss);
    cout << ss.size() - lps.back();
}
