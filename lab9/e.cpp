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
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string ss;
        int k;
        cin >> ss >> k;

        vector<int> lps = LPS(ss);
        int overlap = lps.back();
        int minl = ss.size() + (k-1)*(ss.size() - overlap);
        cout << minl << endl;
    }
    return 0;
}
